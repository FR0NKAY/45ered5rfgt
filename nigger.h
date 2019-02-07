#pragma once
#if !defined(DEBUG) || DEBUG == 0
#define BOOST_DISABLE_ASSERTS
#endif
#pragma warning(disable: 4503)
#define ADVLOG 1
std::random_device rd;
std::mt19937 generator(rd());
#include <iostream>
#include <atlstr.h>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <random>
#include <tlhelp32.h>

#include <ctime>
#include <cstdio>
#include <direct.h>
#include <sys/stat.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Rpcrt4.lib")
#pragma comment(lib, "libcurl.lib")
#include <shlwapi.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#define WIN32_LEAN_AND_MEAN
#include <intrin.h>
#include <iphlpapi.h>
HW_PROFILE_INFO hwProfileInfo;
enum class WmiQueryError {
	None,
	BadQueryFailure,
	PropertyExtractionFailure,
	ComInitializationFailure,
	SecurityInitializationFailure,
	IWbemLocatorFailure,
	IWbemServiceConnectionFailure,
	BlanketProxySetFailure,
};

struct WmiQueryResult
{
	std::vector<std::wstring> ResultList;
	WmiQueryError Error = WmiQueryError::None;
	std::wstring ErrorDescription;
};

WmiQueryResult getWmiQueryResult(std::wstring wmiQuery, std::wstring propNameOfResultObject, bool allowEmptyItems = false) {
	WmiQueryResult retVal;
	retVal.Error = WmiQueryError::None;
	retVal.ErrorDescription = L"";

	HRESULT hres;

	IWbemLocator *pLoc = NULL;
	IWbemServices *pSvc = NULL;
	IEnumWbemClassObject* pEnumerator = NULL;
	IWbemClassObject *pclsObj = NULL;
	VARIANT vtProp;

	// Step 1: --------------------------------------------------
	// Initialize COM. ------------------------------------------

	hres = CoInitializeEx(0, COINIT_MULTITHREADED);
	if (FAILED(hres))
	{
		retVal.Error = WmiQueryError::ComInitializationFailure;
		retVal.ErrorDescription = L"Failed to initialize COM library. Error code : " + std::to_wstring(hres);
	}
	else
	{
		// Step 2: --------------------------------------------------
		// Set general COM security levels --------------------------

		hres = CoInitializeSecurity(
			NULL,
			-1,                          // COM authentication
			NULL,                        // Authentication services
			NULL,                        // Reserved
			RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication
			RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation
			NULL,                        // Authentication info
			EOAC_NONE,                   // Additional capabilities
			NULL                         // Reserved
		);

		if (FAILED(hres))
		{
			retVal.Error = WmiQueryError::SecurityInitializationFailure;
			retVal.ErrorDescription = L"Failed to initialize security. Error code : " + std::to_wstring(hres);
		}
		else
		{
			// Step 3: ---------------------------------------------------
			// Obtain the initial locator to WMI -------------------------
			pLoc = NULL;

			hres = CoCreateInstance(
				CLSID_WbemLocator,
				0,
				CLSCTX_INPROC_SERVER,
				IID_IWbemLocator, (LPVOID *)&pLoc);

			if (FAILED(hres))
			{
				retVal.Error = WmiQueryError::IWbemLocatorFailure;
				retVal.ErrorDescription = L"Failed to create IWbemLocator object. Error code : " + std::to_wstring(hres);
			}
			else
			{
				// Step 4: -----------------------------------------------------
				// Connect to WMI through the IWbemLocator::ConnectServer method

				pSvc = NULL;

				// Connect to the root\cimv2 namespace with
				// the current user and obtain pointer pSvc
				// to make IWbemServices calls.
				hres = pLoc->ConnectServer(
					_bstr_t(L"ROOT\\CIMV2"), // Object path of WMI namespace
					NULL,                    // User name. NULL = current user
					NULL,                    // User password. NULL = current
					0,                       // Locale. NULL indicates current
					NULL,                    // Security flags.
					0,                       // Authority (for example, Kerberos)
					0,                       // Context object
					&pSvc                    // pointer to IWbemServices proxy
				);

				// Connected to ROOT\\CIMV2 WMI namespace

				if (FAILED(hres))
				{
					retVal.Error = WmiQueryError::IWbemServiceConnectionFailure;
					retVal.ErrorDescription = L"Could not connect to Wbem service.. Error code : " + std::to_wstring(hres);
				}
				else
				{
					// Step 5: --------------------------------------------------
					// Set security levels on the proxy -------------------------

					hres = CoSetProxyBlanket(
						pSvc,                        // Indicates the proxy to set
						RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
						RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
						NULL,                        // Server principal name
						RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx
						RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
						NULL,                        // client identity
						EOAC_NONE                    // proxy capabilities
					);

					if (FAILED(hres))
					{
						retVal.Error = WmiQueryError::BlanketProxySetFailure;
						retVal.ErrorDescription = L"Could not set proxy blanket. Error code : " + std::to_wstring(hres);
					}
					else
					{
						// Step 6: --------------------------------------------------
						// Use the IWbemServices pointer to make requests of WMI ----

						// For example, get the name of the operating system
						pEnumerator = NULL;
						hres = pSvc->ExecQuery(
							bstr_t("WQL"),
							bstr_t(wmiQuery.c_str()),
							WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
							NULL,
							&pEnumerator);

						if (FAILED(hres))
						{
							retVal.Error = WmiQueryError::BadQueryFailure;
							retVal.ErrorDescription = L"Bad query. Error code : " + std::to_wstring(hres);
						}
						else
						{
							// Step 7: -------------------------------------------------
							// Get the data from the query in step 6 -------------------

							pclsObj = NULL;
							ULONG uReturn = 0;

							while (pEnumerator)
							{
								HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
									&pclsObj, &uReturn);

								if (0 == uReturn)
								{
									break;
								}

								// VARIANT vtProp;

								// Get the value of desired property
								hr = pclsObj->Get(propNameOfResultObject.c_str(), 0, &vtProp, 0, 0);
								if (S_OK != hr) {
									retVal.Error = WmiQueryError::PropertyExtractionFailure;
									retVal.ErrorDescription = L"Couldn't extract property: " + propNameOfResultObject + L" from result of query. Error code : " + std::to_wstring(hr);
								}
								else {
									BSTR val = vtProp.bstrVal;

									// Sometimes val might be NULL even when result is S_OK
									// Convert NULL to empty string (otherwise "std::wstring(val)" would throw exception)
									if (NULL == val) {
										if (allowEmptyItems) {
											retVal.ResultList.push_back(std::wstring(L""));
										}
									}
									else {
										retVal.ResultList.push_back(std::wstring(val));
									}
								}
							}
						}
					}
				}
			}
		}
	}

	// Cleanup
	// ========

	VariantClear(&vtProp);
	if (pclsObj)
		pclsObj->Release();

	if (pSvc)
		pSvc->Release();

	if (pLoc)
		pLoc->Release();

	if (pEnumerator)
		pEnumerator->Release();

	CoUninitialize();

	return retVal;
}
string ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

int RandomInt(int min, int max) // ez random
{
	return ((generator() % (int)(((max)+1) - (min))) + (min));
}

bool isRunning(const char* name)
{
	HANDLE SnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (SnapShot == INVALID_HANDLE_VALUE)
		return false;

	PROCESSENTRY32 procEntry;
	procEntry.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(SnapShot, &procEntry))
		return false;

	do
	{
		if (strcmp(procEntry.szExeFile, name) == 0)
			return true;
	} while (Process32Next(SnapShot, &procEntry));

	return false;
}


void MouseMove(int x, int y)
{
	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1, &Input, sizeof(INPUT));
}

std::string GetActiveWindowTitle()
{
	char wnd_title[256];
	HWND hwnd = GetForegroundWindow(); // get handle of currently active window
	GetWindowText(hwnd, wnd_title, sizeof(wnd_title));
	return wnd_title;
}

bool randombool() {
	std::uniform_int_distribution<int> d(0, 1); //1 to 10, inclusive
	if (d(rd) == 0)
		return true;
	else return false;
}

void finish_with_error(MYSQL *con)
{
	mysql_close(con);
	ImGui::Text("ERRO!");
}

using namespace std;

void removeCharsFromString(string &str, char* charsToRemove) {
	for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
		str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
	}
}