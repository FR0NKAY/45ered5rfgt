#define GLFW_EXPOSE_NATIVE_WGL
#define GLFW_EXPOSE_NATIVE_WIN32 
#define IMGUI_INCLUDE_IMGUI_USER_INL
#define IMGUI_INCLUDE_IMGUI_USER_H
#define CBC 0
#define CTR 1
#define ECB 0

#include <Windows.h>
#include <lazy_importer.hpp>
#include <xorstr.hpp>
#include <filesystem>
#include <cstdio>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <cstring>
#include <future>
#include <strsafe.h>
#include <codecvt>
#include <thread>
#include <Wbemidl.h>
#include <bitset>
#include <fstream>
#include <irrKlang.h>
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

#include <interception.h>
#pragma comment(lib, "interception.lib")
#include <random>
#include <chrono>
#include <curl/curl.h>
#include <stdio.h>
#include <string>
#include "dirent.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <aes.h>
#include <modes.h>
#include <osrng.h>
#include <base64.h>
#include "picosha2.h"
#include "nigger.h"
#include "json.hpp"
#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl2.h"
#include "resource.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#pragma comment(lib, "wbemuuid.lib")
using json = nlohmann::json;

static void glfw_error_callback(int error, const char* description)
{
	char* buffer;

	snprintf(buffer, sizeof(buffer), xorstr("Glfw Error %d: %s\n"), error, description);
	MessageBoxA(nullptr, LPCSTR(buffer), "", MB_OK | MB_ICONERROR);
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	static_cast<std::string*>(userp)->append(static_cast<char*>(contents), size * nmemb);

	return size * nmemb;
}

std::string auth_text = "Authenticating...";
bool enterpressionado;
bool loggedinglfw;
static int page = 0;
int jitterdelay = 50;
std::string confighash;
bool login_button_pressed = false;
int slidernovo = 1;
const char* tipos_cps[] =
{
	"Old Slider",
	"New Slider",
	"Blatant"
};
auto b_get = false;
auto b_get_right = false;
std::string sz_text = xorstr("click to bind");
std::string sz_text_right = xorstr("click to bind");
std::string confighashtemp;
int beepstatus;
bool newslots[9] = { true };
bool newslots_right[9] = { true };
bool slotpermitido = false;
bool controletotal = false;
bool jittertoggle = false;
bool lunarBypass = false;
bool logado = false;
bool soundfinish;
bool togglesprint = false;
bool issprinting = false;
bool beeptoggle;
bool hidewindowtoggle;
static int jitterclirk = 1;
bool autopotapply;


bool togglewtap;
int wtapdelaymin;
static int nigga1 = 7;
static int nigga2 = 12;
static float cps_min = 7;
std::string hwidserials;
static float cps_max = 12;
bool imguicontrole = true;
bool clicker_thread_controle = true;
bool clicker2_thread_controle = true;
bool timer_thread_controle = true;
bool hulk_thread_controle = true;
std::string stringsal = xorstr("Uq$783mye8zENF$^");
std::string hashhwid;
std::string username;
bool shouldiplaysound;
bool shouldiplaysoundright;
std::string password;
#include "encrypt.h"
HHOOK hookdoMouse;
HHOOK RIGHThookdoMouse;
HHOOK hookdoTeclado;
std::string niggatitlenigga;
bool ligado;
BOOLEAN mouseDown;
BOOLEAN RIGHTmouseDown;
BOOL controle;
int currentslot;
int textslot;;
bool filterslots;
bool cleanstrings = true;
bool cleanfiles = true;
#include <Iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")

std::string getMAC() {
	PIP_ADAPTER_INFO AdapterInfo;
	DWORD dwBufLen = sizeof(IP_ADAPTER_INFO);
	char* mac_addr = (char*)malloc(18);

	AdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
	if (AdapterInfo == NULL) {
		free(mac_addr);
		return NULL; // it is safe to call free(NULL)
	}

	// Make an initial call to GetAdaptersInfo to get the necessary size into the dwBufLen variable
	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW) {
		free(AdapterInfo);
		AdapterInfo = (IP_ADAPTER_INFO*)malloc(dwBufLen);
		if (AdapterInfo == NULL) {

			free(mac_addr);
			return NULL;
		}
	}

	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR) {
		// Contains pointer to current adapter info
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;

		// technically should look at pAdapterInfo->AddressLength
		//   and not assume it is 6.
		sprintf(mac_addr, "%02X:%02X:%02X:%02X:%02X:%02X",
			pAdapterInfo->Address[0], pAdapterInfo->Address[1],
			pAdapterInfo->Address[2], pAdapterInfo->Address[3],
			pAdapterInfo->Address[4], pAdapterInfo->Address[5]);


	}
	free(AdapterInfo);
	std::string mac_addr_str = mac_addr;
	return mac_addr_str; // caller must free.
}

const char* soundstext[] =
{
	"G303",
	"G502",
	"G303 V2",
	"GPro",
	"HP Mouse",
	"Generic Microsoft Mouse",
	"Old Mouse",
	"Oof",
	"Custom File"
};
char custom_sound_path[1024] = "<put the exact custom sound path (with filename) here>";
bool update_custom_sound = false;
bool loop_custom_sound = false;
bool stop_custom_sound_on_release;
bool cleanitself;
bool soundstoggle;
bool inventoryjitter = false;
bool rightmouseligado;
bool destructconfig;
int refreshdelay = 500;
std::string janelaatual;
char janelaminecraftchar[200] = "Minecraft";
int errorcondition;
POINT mouse;
INPUT leftclick;
INPUT rightclick;
float cps_min_ms;
float cps_max_ms;
float delayy;
int delayupdown;
int cpsatual;
int slotmin = 2;
int slotmax = 9;
int slotsword = 1;
bool autopottoggle;
float autopotdelay = 100;
bool minecraftaberto = false;
bool debuginfo = false;
bool windowonly = false;
static int clickcounter;
bool blockhit = false;
bool randomizeblockhit = false;
int randomizationpercentageblockhit = 40;
int blockhitcurrentchance;
static char charusername[300];
static char charpassword[300];
bool randomize = true;
int clickerkeybind = VK_F4;
int rightclickerkeybind = VK_F3;
int autopotkeybind;
bool autopotkeybinddown;
int selectedsound;
std::string query;
std::string query2;
std::string query3;
char charquery[1000];
char charquery2[1000];
char charquery3[1000];
std::string mysqlusername;
std::string mysqlserver;
std::string mysqlpassword;
std::string mysqldatabase;
bool selfdeletetoggle;
std::string pubKeyBase64 =
xorstr("MFYwEAYHKoZIzj0CAQYFK4EEAAoDQgAEnbTUkd3GORk3kO5CDoVD8oW2k3oIyoAoeqeSY3ntfZuVV/dFk3O9YJlpmU/tcA1sch2JniwosgUOfKLScOUDSA==");
std::string base64_encode(unsigned char const*, unsigned int len);

std::string XOR(std::string value, std::string key);

static inline bool is_base64(unsigned char c)
{
	return (isalnum(c) || (c == '+') || (c == '/'));
}

static const std::string base64_chars = xorstr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len)
{
	std::string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (in_len--)
	{
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3)
		{
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i < 4); i++)
				ret += base64_chars[char_array_4[i]];
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while ((i++ < 3))
			ret += '=';
	}

	return ret;
}

std::string XOR(std::string value, std::string key)
{
	std::string retval(value);
	const long unsigned int klen = key.length();
	const long unsigned int vlen = value.length();
	unsigned long int k = 0;
	unsigned long int v = 0;
	for (; v < vlen; v++)
	{
		retval[v] = value[v] ^ key[k];
		k = (++k < klen ? k : 0);
	}
	return retval;
}

void concatenateHwid(std::wstring queryy, std::wstring propNameOfResultObject)
{
	WmiQueryResult res;
	res = getWmiQueryResult(std::move(queryy), std::move(propNameOfResultObject));

	if (res.Error != WmiQueryError::None)
	{
		return; // Exitting function
	}

	for (const auto& item : res.ResultList)
	{
		hwidserials += ws2s(item);
		hwidserials += getMAC();
	}
}


LRESULT __stdcall mouse_callback(int code, WPARAM wparam, LPARAM lparam)
{
	auto hook = reinterpret_cast<MSLLHOOKSTRUCT*>(lparam);

	if (logado && !(hook->flags == LLMHF_INJECTED))
	{
		switch (wparam)
		{
		case WM_MOUSEWHEEL:

			if (HIWORD(hook->mouseData) == 120)
			{
				if (currentslot == 49)
				{
					currentslot = 57;
				}
				else
				{
					currentslot--;
				}
			}
			else
			{
				if (currentslot == 57)
				{
					currentslot = 49;
				}
				else
				{
					currentslot++;
				}
			}

			break;
		case WM_LBUTTONDOWN:

			mouseDown = true;
			break;
		case WM_LBUTTONUP:
			mouseDown = false;
			break;


		case WM_RBUTTONDOWN:
			RIGHTmouseDown = true;
			break;
		case WM_RBUTTONUP:
			RIGHTmouseDown = false;
			break;

		}
	}

	return CallNextHookEx(hookdoMouse, code, wparam, lparam);

}

void rightdown()
{

	INPUT input = INPUT();
	// left down

	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &input, sizeof(INPUT));

	shouldiplaysoundright = true;
}

void rightup()
{

	INPUT input = INPUT();
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &input, sizeof(INPUT));

	// left up
	shouldiplaysoundright = false;

}

bool is_file_exist(const char* fileName)
{
	const std::ifstream infile(fileName);
	return infile.good();
}


struct ARGS
{
	int i;
	int d;
};

bool resetinventorykey;

int AutoPot() // thread dos clicks
{
	int slotatual;
	int slotatualint;

	INPUT numberinput;

	numberinput.type = INPUT_KEYBOARD;
	numberinput.ki.wScan = 0;
	numberinput.ki.time = 0;
	numberinput.ki.dwExtraInfo = 0;
	numberinput.ki.wVk = 0x53;
	slotatual = slotmin;
	while (imguicontrole) {

		Sleep(autopotdelay / 2);
		float autopotdelayrand = distribucaoint((autopotdelay * 0.75), (autopotdelay * 1.25));
		if (autopotapply)
		{
			slotatual = slotmin;
			autopotapply = false;
		}
		if (slotatual > slotmax)
		{
			slotatual = slotmin;
		}
		slotatualint = slotatual + 48;
		numberinput.ki.wVk = slotatualint;
		if (resetinventorykey)
		{
			slotatual = slotmin;
			resetinventorykey = false;
		}
		if (autopottoggle && autopotkeybinddown)
		{
			numberinput.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &numberinput, sizeof(INPUT));

			numberinput.ki.dwFlags = KEYEVENTF_KEYUP; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &numberinput, sizeof(INPUT));

			Sleep(autopotdelayrand);
			rightdown();
			Sleep(distribucaoint(10, 20));
			rightup();

			Sleep(autopotdelayrand);

			numberinput.ki.wVk = slotsword + 48;

			numberinput.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &numberinput, sizeof(INPUT));

			numberinput.ki.dwFlags = KEYEVENTF_KEYUP; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &numberinput, sizeof(INPUT));
			slotatual++;
			autopotkeybinddown = false;
		}

	}

	return 0;
}

BOOL IsProcessElevated()
{
	BOOL fIsElevated = FALSE;
	HANDLE hToken = NULL;
	TOKEN_ELEVATION elevation;
	DWORD dwSize;

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
	{
		goto Cleanup;  // if Failed, we treat as False
	}


	if (!GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &dwSize))
	{
		goto Cleanup;// if Failed, we treat as False
	}

	fIsElevated = elevation.TokenIsElevated;

Cleanup:
	if (hToken)
	{
		CloseHandle(hToken);
		hToken = NULL;
	}
	return fIsElevated;
}

GLFWwindow* window;


LRESULT CALLBACK testeTeclado(int nCode, WPARAM wParam, LPARAM lParam) // listener do teclado
{
	PKBDLLHOOKSTRUCT keyStruct = (PKBDLLHOOKSTRUCT)lParam;
	if (logado)
	{
		if (nullptr != keyStruct &&
			WM_KEYDOWN == wParam
			&& 'W' == keyStruct->vkCode)
		{
			issprinting = true;
		}
		if (
			WM_KEYDOWN == wParam
			&& autopotkeybind == keyStruct->vkCode)
		{
			autopotkeybinddown = true;
		}
		if (
			WM_KEYDOWN == wParam
			&& ('1' == keyStruct->vkCode || '2' == keyStruct->vkCode || '3' == keyStruct->vkCode || '4' ==
				keyStruct->vkCode || '5' == keyStruct->vkCode || '6' == keyStruct->vkCode || '7' == keyStruct->
				vkCode || '8' == keyStruct->vkCode || '9' == keyStruct->vkCode))
		{
			currentslot = keyStruct->vkCode;
		}
		if (nullptr != keyStruct
			&& WM_KEYUP == wParam) {
			if (VK_F9 == keyStruct->vkCode)
			{
				imguicontrole = !imguicontrole;
			}


			if (

				clickerkeybind == keyStruct->vkCode)
			{
				if (ligado)
				{
					ligado = false;
					beepstatus = 2;
				}
				else
				{
					ligado = true;
					beepstatus = 3;
				}
			}
			if (

				'W' == keyStruct->vkCode)
			{
				issprinting = false;
			}
			if (

				rightclickerkeybind == keyStruct->vkCode)
			{
				if (rightmouseligado)
				{
					rightmouseligado = false;
					beepstatus = 2;
				}
				else
				{
					rightmouseligado = true;
					beepstatus = 3;
				}
			}





			if (

				VK_END == keyStruct->vkCode)
			{
				hidewindowtoggle = !hidewindowtoggle;
				if (hidewindowtoggle)
				{

					glfwHideWindow(window);

				}
				else
				{

					glfwShowWindow(window);

				}
			}
		}

	}

	else
	{
		if (nullptr != keyStruct
			&& WM_KEYUP == wParam
			&& VK_RETURN == keyStruct->vkCode)
		{
			enterpressionado = true;
		}
	}
	return nCode < 0 ? CallNextHookEx(hookdoTeclado, nCode, wParam, lParam) : 0;
}




int HULK() // hooks do mouse e teclado
{

	hookdoMouse = SetWindowsHookExA(WH_MOUSE_LL, &mouse_callback, nullptr, 0);

	MSG lpMsg;
	while (imguicontrole && GetMessageA(&lpMsg, nullptr, 0, 0))
	{

		TranslateMessage(&lpMsg);
		DispatchMessageA(&lpMsg);
	}


	UnhookWindowsHookEx(hookdoMouse);
	hulk_thread_controle = false;
	return 0;
}
int HULK_kb() // hooks do mouse e teclado
{

	hookdoTeclado = SetWindowsHookExA(WH_KEYBOARD_LL, &testeTeclado, nullptr, 0);

	MSG lpMsg;
	while (imguicontrole && GetMessageA(&lpMsg, nullptr, 0, 0))
	{

		TranslateMessage(&lpMsg);
		DispatchMessageA(&lpMsg);
	}


	UnhookWindowsHookEx(hookdoTeclado);
	return 0;
}

int skipclicks;


void leftdown()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));




	skipclicks++;
	shouldiplaysound = true;
}

int leftup()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));
	shouldiplaysound = false;
	return 0;
}


bool vidaclicker;
int cps_atual;
float cps_atual_ms;
void loadconfig()
{
	CURL* curl;
	CURLcode res;
	std::string response;

	curl = curl_easy_init();
	if (curl)
	{
		std::stringstream ssdata;
		ssdata << (char*)xorstr("http://192.99.120.56/api/config?name=") << curl_easy_escape(
			curl, username.c_str(), strlen(username.c_str()));
		std::string configUrl = ssdata.str();
		configUrl.erase(std::remove(configUrl.begin(), configUrl.end(), ' '), configUrl.end());
		curl_easy_setopt(curl, CURLOPT_URL, configUrl.c_str());

		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			MessageBoxA(
				nullptr,
				xorstr("There was an error while trying to communicate with our servers. Check your Internet connection and try again."),
				"", MB_OK | MB_ICONERROR);
			curl_easy_cleanup(curl);
			imguicontrole = false;
		}
		else
		{
			long response_code;
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
			if (response_code == 200)
			{
				ImGuiStyle& style = ImGui::GetStyle();
				if (response != (char*)xorstr("{}\n") && response != (char*)xorstr("null"))
				{
					auto config = json::parse(response);

					ligado = config[xorstr("clicker_toggle")];
					nigga1 = config[xorstr("cps_min")];
					nigga2 = config[xorstr("cps_max")];
					randomize = config[xorstr("randomize_toggle")];
					clickerkeybind = config[xorstr("clicker_keybind")];
					refreshdelay = config[xorstr("refresh_delay")];
					filterslots = config[xorstr("slofilter_toggle")];
					textslot = config[xorstr("slotfilter_selectedslot")];
					soundstoggle = config[xorstr("clicksounds_toggle")];
					selectedsound = config[xorstr("clicksounds_selectedsound")];
					beeptoggle = config[xorstr("beep_toggle")];
					slidernovo = config[xorstr("newslider_toggle")];
					jittertoggle = config[xorstr("jitter_toggle")];
					jitterclirk = config[xorstr("jitter_strength")];
					jitterdelay = config[xorstr("jitter_delay")];
					inventoryjitter = config[xorstr("jitter_inventory")];
					windowonly = config[xorstr("misc_windowonly")];
					std::string tmpstrwindowname = config[xorstr("misc_specifiedwindow")];
					if (tmpstrwindowname.size() <= 200)
					{
						memset(janelaminecraftchar, 0, sizeof janelaminecraftchar);
						std::strncpy(janelaminecraftchar, tmpstrwindowname.data(), tmpstrwindowname.size());
					}
					rightmouseligado = config[xorstr("misc_rightclicker_toggle")];
					togglesprint = config[xorstr("misc_togglesprinttoggle")];
					togglewtap = config[xorstr("misc_wtap_toggle")];
					wtapdelaymin = config[xorstr("misc_wtap_delay")];
					blockhit = config[xorstr("misc_blockhit_toggle")];
					randomizeblockhit = config[xorstr("misc_blockhit_randomize")];
					randomizationpercentageblockhit = config[xorstr("misc_blockhit_randomizechance")];
					autopottoggle = config[xorstr("misc_autopot_toggle")];
					autopotkeybind = config[xorstr("misc_autopot_keybind")];
					slotsword = config[xorstr("misc_autopot_swordslot")];
					autopotdelay = config[xorstr("misc_autopot_delay")];
					slotmin = config[xorstr("misc_autopot_minslots")];
					slotmax = config[xorstr("misc_autopot_maxslots")];
					cleanstrings = config[xorstr("other_cleanstrings")];
					cleanfiles = config[xorstr("other_cleanfiles")];

					if (config.count("custom_sound_path") != 0) {
						std::string tmpstrcustom_sound_path = config[xorstr("custom_sound_path")];
						if (tmpstrcustom_sound_path.size() <= 1000)
						{
							memset(custom_sound_path, 0, sizeof custom_sound_path);
							std::strncpy(custom_sound_path, tmpstrcustom_sound_path.data(), tmpstrcustom_sound_path.size());
						}
					}
					if (config.count("stop_custom_sound_on_release") != 0) {
						stop_custom_sound_on_release = config[xorstr("stop_custom_sound_on_release")];

					}
					if (config.count("loop_custom_sound") != 0) {
						loop_custom_sound = config[xorstr("loop_custom_sound")];

					}
					style.Colors[ImGuiCol_Text].w = config[xorstr("other_color11")];
					style.Colors[ImGuiCol_Text].x = config[xorstr("other_color12")];
					style.Colors[ImGuiCol_Text].y = config[xorstr("other_color13")];
					style.Colors[ImGuiCol_Text].z = config[xorstr("other_color14")];
					style.Colors[ImGuiCol_WindowBg].w = config[xorstr("other_color21")];
					style.Colors[ImGuiCol_WindowBg].x = config[xorstr("other_color22")];
					style.Colors[ImGuiCol_WindowBg].y = config[xorstr("other_color23")];
					style.Colors[ImGuiCol_WindowBg].z = config[xorstr("other_color24")];
					style.Colors[ImGuiCol_Button].w = config[xorstr("other_color31")];
					style.Colors[ImGuiCol_Button].x = config[xorstr("other_color32")];
					style.Colors[ImGuiCol_Button].y = config[xorstr("other_color33")];
					style.Colors[ImGuiCol_Button].z = config[xorstr("other_color34")];
				}
			}

			curl_easy_cleanup(curl);
		}
	}
}
void saveconfig(bool deleteConfig)
{
	ImGuiStyle& style = ImGui::GetStyle();

	json config;
	if (!deleteConfig)
	{
		config[xorstr("clicker_toggle")] = ligado;
		config[xorstr("cps_min")] = nigga1;
		config[xorstr("cps_max")] = nigga2;
		config[xorstr("randomize_toggle")] = randomize;
		config[xorstr("clicker_keybind")] = clickerkeybind;
		config[xorstr("refresh_delay")] = refreshdelay;
		config[xorstr("slofilter_toggle")] = filterslots;
		config[xorstr("slotfilter_selectedslot")] = textslot;
		config[xorstr("clicksounds_toggle")] = soundstoggle;
		config[xorstr("clicksounds_selectedsound")] = selectedsound;
		config[xorstr("beep_toggle")] = beeptoggle;
		config[xorstr("newslider_toggle")] = slidernovo;
		config[xorstr("jitter_toggle")] = jittertoggle;
		config[xorstr("jitter_strength")] = jitterclirk;
		config[xorstr("jitter_delay")] = jitterdelay;
		config[xorstr("jitter_inventory")] = inventoryjitter;
		config[xorstr("misc_windowonly")] = windowonly;
		config[xorstr("misc_specifiedwindow")] = janelaminecraftchar;
		config[xorstr("misc_rightclicker_toggle")] = rightmouseligado;
		config[xorstr("misc_togglesprinttoggle")] = togglesprint;
		config[xorstr("misc_wtap_toggle")] = togglewtap;
		config[xorstr("misc_wtap_delay")] = wtapdelaymin;
		config[xorstr("misc_blockhit_toggle")] = blockhit;
		config[xorstr("misc_blockhit_randomize")] = randomizeblockhit;
		config[xorstr("misc_blockhit_randomizechance")] = randomizationpercentageblockhit;
		config[xorstr("misc_autopot_toggle")] = autopottoggle;
		config[xorstr("misc_autopot_keybind")] = autopotkeybind;
		config[xorstr("misc_autopot_swordslot")] = slotsword;
		config[xorstr("misc_autopot_delay")] = autopotdelay;
		config[xorstr("misc_autopot_minslots")] = slotmin;
		config[xorstr("misc_autopot_maxslots")] = slotmax;
		config[xorstr("other_cleanstrings")] = cleanstrings;
		config[xorstr("other_cleanfiles")] = cleanfiles;
		config[xorstr("other_color11")] = style.Colors[ImGuiCol_Text].w;
		config[xorstr("other_color12")] = style.Colors[ImGuiCol_Text].x;
		config[xorstr("other_color13")] = style.Colors[ImGuiCol_Text].y;
		config[xorstr("other_color14")] = style.Colors[ImGuiCol_Text].z;
		config[xorstr("other_color21")] = style.Colors[ImGuiCol_WindowBg].w;
		config[xorstr("other_color22")] = style.Colors[ImGuiCol_WindowBg].x;
		config[xorstr("other_color23")] = style.Colors[ImGuiCol_WindowBg].y;
		config[xorstr("other_color24")] = style.Colors[ImGuiCol_WindowBg].z;
		config[xorstr("other_color31")] = style.Colors[ImGuiCol_Button].w;
		config[xorstr("other_color32")] = style.Colors[ImGuiCol_Button].x;
		config[xorstr("other_color33")] = style.Colors[ImGuiCol_Button].y;
		config[xorstr("other_color34")] = style.Colors[ImGuiCol_Button].z;
		config[xorstr("custom_sound_path")] = custom_sound_path;
		config[xorstr("stop_custom_sound_on_release")] = stop_custom_sound_on_release;
		config[xorstr("loop_custom_sound")] = loop_custom_sound;
	}

	CURL* curl;
	CURLcode res;
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, xorstr("http://192.99.120.56/api/config"));
		std::stringstream ssdata;
		std::string usr_param = (char*)xorstr("usr=");
		std::string pass_param = (char*)xorstr("&pass=");
		std::string cfg_param = (char*)xorstr("&cfg=");
		ssdata << usr_param << curl_easy_escape(curl, username.c_str(), strlen(username.c_str())) << pass_param <<
			curl_easy_escape(curl, password.c_str(), strlen(password.c_str())) << cfg_param <<
			curl_easy_escape(curl, config.dump().c_str(), strlen(config.dump().c_str()));
		std::string payload = ssdata.str();
		payload.erase(std::remove(payload.begin(), payload.end(), ' '), payload.end());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			MessageBoxA(
				nullptr,
				(char*)xorstr(L"There was an error while trying to communicate with our servers. Check your Internet connection and try again."),
				"", MB_OK | MB_ICONERROR);
			curl_easy_cleanup(curl);
			imguicontrole = false;
		}
		else
		{
			long response_code;
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
			if (response_code == 200)
			{
				//MessageBoxA(nullptr, xorstr("Config saved on cloud."), "", MB_ICONINFORMATION);
			}
			else
			{
				MessageBoxA(nullptr, xorstr("Error saving config."), "", MB_ICONERROR);
			}
			curl_easy_cleanup(curl);
		}
	}
}



char* load_resource_as_char_array(int resource_id, int* length_callback) {
	LPCSTR resource_type = "WAVE";
	HMODULE hModule = GetModuleHandle(NULL); // get the handle to the current module (the executable file)
	HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(resource_id), resource_type); // substitute RESOURCE_ID and RESOURCE_TYPE.
	HGLOBAL hMemory = LoadResource(hModule, hResource);
	DWORD dwSize = SizeofResource(hModule, hResource);
	LPVOID lpAddress = LockResource(hMemory);

	char* bytes = new char[dwSize];
	memcpy(bytes, lpAddress, dwSize);
	*length_callback = dwSize;
	return bytes;
}

irrklang::ISoundSource* load_soundsource_from_resource(irrklang::ISoundEngine* engine, int resource_id, irrklang::ik_c8* sound_name) {
	int resource_len_int;
	auto resource_data = load_resource_as_char_array(resource_id, &resource_len_int);
	irrklang::ISoundSource* sound_source = engine->addSoundSourceFromMemory(resource_data, resource_len_int, sound_name);
	return sound_source;
}

int TimerThread()
{
	int delaywtap;
	wtapdelaymin = 100;

	irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();

	if (!engine)
	{
		MessageBoxA(nullptr, xorstr("Couldn't start sound system."), "", MB_ICONERROR);
		imguicontrole = false;
	}

	irrklang::ISoundSource* g303_src = load_soundsource_from_resource(engine, IDR_WAVE1, "G303");
	irrklang::ISoundSource* g502_src = load_soundsource_from_resource(engine, IDR_WAVE2, "G502");
	irrklang::ISoundSource* g303v2_src = load_soundsource_from_resource(engine, IDR_WAVE3, "G303_V2");
	irrklang::ISoundSource* gpro_src = load_soundsource_from_resource(engine, IDR_WAVE4, "GPro");
	irrklang::ISoundSource* hp_src = load_soundsource_from_resource(engine, IDR_WAVE5, "HP");
	irrklang::ISoundSource* microsoft_src = load_soundsource_from_resource(engine, IDR_WAVE6, "Microsoft");
	irrklang::ISoundSource* old_src = load_soundsource_from_resource(engine, IDR_WAVE7, "Old");
	irrklang::ISoundSource* oof_src = load_soundsource_from_resource(engine, IDR_WAVE9, "Oof");

	INPUT sprintinput;

	sprintinput.type = INPUT_KEYBOARD;
	sprintinput.ki.wScan = 0;
	sprintinput.ki.time = 0;
	sprintinput.ki.dwExtraInfo = 0;
	sprintinput.ki.wVk = VK_LCONTROL;

	auto timeNow = std::chrono::steady_clock::now();
	auto timeStartSound = timeNow;
	auto timeStartCPS = timeNow;
	auto timeStartJitter = timeNow;
	auto timeStartWtap = timeNow;
	auto timeStartConfig = timeNow;
	while (imguicontrole)
	{

		delaywtap = distribucaoint(wtapdelaymin - (wtapdelaymin * 0.25), wtapdelaymin + (wtapdelaymin * 1.25));
		timeNow = std::chrono::steady_clock::now();
		auto timepassedSound = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - timeStartSound).count();
		auto timepassedWtap = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - timeStartWtap).count();
		auto timepassedCPS = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - timeStartCPS).count();
		auto timePassedJitter = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - timeStartJitter).count();
		auto timepassedconfig = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - timeStartConfig).count();

		if ((static_cast<int>(timepassedconfig) >= 60000) && logado)
		{
			std::async(std::launch::async, saveconfig, false);
			timeStartConfig = std::chrono::steady_clock::now();

		}
		if (togglesprint)
		{
			if (issprinting)
			{
				sprintinput.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
				SendInput(1, &sprintinput, sizeof(INPUT));
			}
			else
			{
				sprintinput.ki.dwFlags = KEYEVENTF_KEYUP; // there is no KEYEVENTF_KEYDOWN
				SendInput(1, &sprintinput, sizeof(INPUT));
			}
		}
		if (static_cast<int>(timePassedJitter) >= jitterdelay)
		{
			GetCursorPos(&mouse);
			if (ligado && jittertoggle && mouseDown && !(niggatitlenigga == janelaatual))
			{
				int jitterez;
				jitterez = distribucaoint(1, 8);

				if (windowonly)
				{
					if (minecraftaberto)
					{
						switch (jitterez)
						{
						case 1:
							MouseMove((mouse.x + jitterclirk), (mouse.y));
							break;
						case 2:
							MouseMove((mouse.x), (mouse.y + jitterclirk));
							break;
						case 3:
							MouseMove((mouse.x), (mouse.y - jitterclirk));
							break;
						case 4:
							MouseMove((mouse.x - jitterclirk), (mouse.y));
							break;
						case 5:
							MouseMove((mouse.x - jitterclirk), (mouse.y + jitterclirk));
							break;
						case 6:
							MouseMove((mouse.x + jitterclirk), (mouse.y - jitterclirk));
							break;
						case 7:
							MouseMove((mouse.x + jitterclirk), (mouse.y + jitterclirk));
							break;
						case 8:
							MouseMove((mouse.x - jitterclirk), (mouse.y - jitterclirk));
							break;
						}
					}
				}
				else
				{
					switch (jitterez)
					{
					case 1:
						MouseMove((mouse.x + jitterclirk), (mouse.y));
						break;
					case 2:
						MouseMove((mouse.x), (mouse.y + jitterclirk));
						break;
					case 3:
						MouseMove((mouse.x), (mouse.y - jitterclirk));
						break;
					case 4:
						MouseMove((mouse.x - jitterclirk), (mouse.y));
						break;
					case 5:
						MouseMove((mouse.x - jitterclirk), (mouse.y + jitterclirk));
						break;
					case 6:
						MouseMove((mouse.x + jitterclirk), (mouse.y - jitterclirk));
						break;
					case 7:
						MouseMove((mouse.x + jitterclirk), (mouse.y + jitterclirk));
						break;
					case 8:
						MouseMove((mouse.x - jitterclirk), (mouse.y - jitterclirk));
						break;
					}
				}
			}
			timeStartJitter = std::chrono::steady_clock::now();
		}
		if (static_cast<int>(timepassedCPS) >= refreshdelay)
		{
			if (slidernovo == 1)
			{
				try
				{
					if (randomize)
					{
						
						int distribution_nonce = distribucaoint(0, 3);
						cps_min = nigga1 - distribution_nonce;
						cps_max = nigga1 + distribution_nonce;
					}
					else
					{
						cps_min = nigga1;
						cps_max = nigga1 + 1;
					}
				}
				catch (int e)
				{
					MessageBoxA(nullptr, LPCSTR(to_string(e).c_str()), "", MB_OK | MB_ICONERROR);
				}
			}
			else if (slidernovo == 2)
			{
				try
				{
					cps_min = nigga1 - 1;
					cps_max = nigga1;
				}
				catch (int e)
				{
					MessageBoxA(nullptr, LPCSTR(to_string(e).c_str()), "", MB_OK | MB_ICONERROR);
				}
			}
			else
			{
				try
				{
					if (nigga1 > nigga2) nigga1 = nigga2 - 1;
					cps_min = nigga1;
					cps_max = nigga2;
				}
				catch (int e)
				{
					MessageBoxA(nullptr, LPCSTR(to_string(e).c_str()), "", MB_OK | MB_ICONERROR);
				}
			}
			cps_min_ms = ((1 / static_cast<float>(cps_min)) * 1000);
			cps_max_ms = ((1 / static_cast<float>(cps_max)) * 1000);
			delayy = distribucaoint(cps_max_ms, cps_min_ms);
			timeStartCPS = std::chrono::steady_clock::now();
		}
		if (!mouseDown && stop_custom_sound_on_release && selectedsound == 8) {

			engine->stopAllSounds();
		}
		if ((static_cast<float>(timepassedSound) >= delayy) && soundstoggle && shouldiplaysound)
		{

			if (loop_custom_sound && selectedsound == 8) {
				if (!engine->isCurrentlyPlaying(custom_sound_path)) {
					engine->play2D(custom_sound_path, true);
				}

			}
			else {
				switch (selectedsound)
				{
				case 0:
				{
					engine->play2D(g303_src);
					break;
				}
				case 1:
					engine->play2D(g502_src);

					break;
				case 2:
					engine->play2D(g303v2_src);

					break;
				case 3:
					engine->play2D(gpro_src);

					break;
				case 4:
					engine->play2D(hp_src);

					break;
				case 5:
					engine->play2D(microsoft_src);

					break;
				case 6:
					engine->play2D(old_src);

					break;
				case 7:
					engine->play2D(oof_src);
					break;
				case 8:
					engine->play2D(custom_sound_path);
					break;
				}

			}

			timeStartSound = std::chrono::steady_clock::now();
		}
		if ((static_cast<float>(timepassedWtap) >= delaywtap) && togglewtap && ligado && mouseDown && !(niggatitlenigga
			==
			janelaatual))
		{
			INPUT wtapinput;
			wtapinput.type = INPUT_KEYBOARD;
			wtapinput.ki.wScan = 0;
			wtapinput.ki.time = 0;
			wtapinput.ki.dwExtraInfo = 0;
			wtapinput.ki.wVk = 'W';
			wtapinput.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &wtapinput, sizeof(INPUT));

			wtapinput.ki.dwFlags = KEYEVENTF_KEYUP; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &wtapinput, sizeof(INPUT));
			wtapinput.type = INPUT_KEYBOARD;
			wtapinput.ki.wScan = 0;
			wtapinput.ki.time = 0;
			wtapinput.ki.dwExtraInfo = 0;
			wtapinput.ki.wVk = 'W';
			wtapinput.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &wtapinput, sizeof(INPUT));

			wtapinput.ki.dwFlags = KEYEVENTF_KEYUP; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &wtapinput, sizeof(INPUT));
			timeStartWtap = std::chrono::steady_clock::now();

		}

		if (newslots[currentslot - 49])
		{
			slotpermitido = true;
		}
		else
		{
			slotpermitido = false;
		}
		std::vector<int> v{ jitterdelay, refreshdelay, static_cast<int>(delayy), delaywtap };
		Sleep(2);
	}
	timer_thread_controle = false;
	engine->drop();
	return 0;
}


std::uniform_int_distribution<int> distanciaupdown(15, 30); //1 to 10, inclusive
std::uniform_int_distribution<int> blockhitrandomization(0, 100);

int updowncount;
int skipclickcondition;

std::chrono::milliseconds timepassed;
auto timeStart = std::chrono::steady_clock::now();

int clickVerifyFunction()
{
	bool shouldClickLeft = true;
	bool shouldClickRight = true;
	if (skipclicks >= skipclickcondition)
	{
		skipclicks = 0;
		shouldClickLeft = false;
		shouldClickRight = false;
	}

	if (windowonly)
	{
		if (!minecraftaberto)
		{
			shouldClickLeft = false;
			shouldClickRight = false;
		}
	}
	if (filterslots)
	{
		if (!slotpermitido)
		{
			shouldClickLeft = false;
			shouldClickRight = false;
		}
	}
	if (!mouseDown)
	{
		shouldClickLeft = false;
	}
	if (!RIGHTmouseDown)
	{
		shouldClickRight = false;
	}
	if (niggatitlenigga == janelaatual)
	{
		shouldClickLeft = false;
		shouldClickRight = false;
	}
	if (!ligado)
	{
		shouldClickLeft = false;
	}
	if (!rightmouseligado)
	{
		shouldClickRight = false;
	}
	if (shouldClickLeft)
	{

		leftdown();
		Sleep(delayupdown);
		updowncount++;
		leftup();
		if (blockhit)
		{
			if (randomizeblockhit)
			{
				if (blockhitcurrentchance <= randomizationpercentageblockhit)
				{
					rightdown();
					Sleep(delayupdown);
					updowncount++;
					rightup();
				}
			}
			else
			{
				rightdown();
				Sleep(delayupdown);
				updowncount++;
				rightup();
			}
		}
		clickcounter++;
	}





	if (shouldClickRight)
	{
		rightdown();
		Sleep(delayupdown);
		updowncount++;
		rightup();
	}
	return 0;
}

int ClickThread() // thread dos clicks
{
	while (imguicontrole)
	{
		switch (beepstatus)
		{
		case 2:
			if (beeptoggle)
			{
				Beep(300, 200);
			}

			beepstatus = 0;
			break;
		case 3:
			if (beeptoggle)
			{
				Beep(600, 200);
			}
			beepstatus = 0;
			break;
		}

		clickVerifyFunction();
		if ((delayy - (delayupdown * updowncount)) > 0)
		{
			Sleep(delayy - (delayupdown * updowncount));
		}

		updowncount = 0;
	}
	clicker_thread_controle = false;
	return 0;
}


int ClickThread2() // thread dos clicks
{
	wtapdelaymin = 100;


	while (imguicontrole)
	{
		if (login_button_pressed) {
			enterpressionado = false;

			username = charusername;
			password = charpassword;


			//login
			std::string url = xorstr("http://192.99.120.56/api/auth");
			std::string responseData;
			std::string key = xorstr("CTu5J/vEFzojIw/cvi8eHa2QWo7Wg+ZykJekTtu8Um8=");

			CURL* curl;
			CURLcode res;
			curl = curl_easy_init();
			if (curl)
			{
				curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);


				json data;
				int nonce = distribucaoint(1, 5000);

				data[xorstr("username")] = username;
				data[xorstr("password")] = password;
				data[xorstr("nonce")] = nonce;
				data[xorstr("hwid")] = hashhwid;
				data[xorstr("version")] = xorstr("2.8.5");
				CryptoPP::AutoSeededRandomPool rnd;
				// Generate a random key
				CryptoPP::SecByteBlock aesKey(nullptr, CryptoPP::AES::DEFAULT_KEYLENGTH);
				rnd.GenerateBlock(aesKey, aesKey.size());


				// Generate a random IV
				CryptoPP::SecByteBlock aesIv(CryptoPP::AES::BLOCKSIZE);
				rnd.GenerateBlock(aesIv, aesIv.size());


				std::string strIvBase64, strKeyBase64;

				CryptoPP::StringSource ssIv(static_cast<CryptoPP::byte*>(&aesIv[0]), aesIv.size(), true,
					new CryptoPP::Base64Encoder(
						new CryptoPP::StringSink(strIvBase64)
					) // Base64Encoder
				); // StringSource
				CryptoPP::StringSource ssKey(static_cast<CryptoPP::byte*>(&aesKey[0]), aesKey.size(), true,
					new CryptoPP::Base64Encoder(
						new CryptoPP::StringSink(strKeyBase64)
					) // Base64Encoder
				); // StringSource

				data[xorstr("iv")] = strIvBase64;
				data[xorstr("key")] = strKeyBase64;


				std::string jsonDump = data.dump();
				std::string compressedJsonDump = jsonDump;
				std::string encrypted = base64_encode(XOR(compressedJsonDump, key));

				std::stringstream ssdata;
				ssdata << "c=" << curl_easy_escape(curl, encrypted.c_str(), strlen(encrypted.c_str()));
				std::string payload = ssdata.str();
				payload.erase(std::remove(payload.begin(), payload.end(), ' '), payload.end());

				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
				curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

				res = curl_easy_perform(curl);
				if (res != CURLE_OK)
				{

					MessageBoxA(
						nullptr,
						xorstr("There was an error while trying to communicate with our servers. Check your Internet connection and try again."),
						"", MB_OK | MB_ICONERROR);
					curl_easy_cleanup(curl);
					imguicontrole = false;
				}
				else
				{
					auth_text = "Verifying sesion..";
					long response_code;
					curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

					if (response_code == 200)
					{
						std::string token;
						string cipher, encoded, recovered;

						try
						{
							cipher = responseData;

							CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption decryptionObj;
							decryptionObj.SetKeyWithIV(aesKey, aesKey.size(), aesIv);

							// The StreamTransformationFilter removes
							//  padding as required.
							CryptoPP::StringSource decryptionStringSource(cipher, true,
								new CryptoPP::Base64Decoder(
									new CryptoPP::
									StreamTransformationFilter(
										decryptionObj,
										new CryptoPP::StringSink(
											recovered)
									) // StreamTransformationFilter
								)
							); // StringSource
							auto responseJson = json::parse(recovered);
							if (data[xorstr("version")] != responseJson[xorstr("version")])
							{
								MessageBoxA(nullptr, xorstr("This version is outdated. A new version was released. Please re-download the file."), xorstr(""),
									MB_ICONERROR);
								imguicontrole = false;
							}
							else if (data[xorstr("nonce")] != responseJson[xorstr("nonce")]
								|| data[xorstr("username")] != responseJson[xorstr("username")]
								|| data[xorstr("hwid")] != responseJson[xorstr("hwid")]
								)
							{

								MessageBoxA(
									nullptr,
									xorstr("There was an error while trying to communicate with our servers. Check your Internet connection and try again."),
									"", MB_OK | MB_ICONERROR);
								imguicontrole = false;
							}
							else
							{
								logado = true;
								loggedinglfw = true;
								CHAR czTempPath[MAX_PATH] = { 0 };
								GetTempPathA(MAX_PATH, czTempPath); // retrieving temp path
								string sPath = czTempPath;
								sPath += data[xorstr("hwid")]; // adding my file.bat
								ofstream autologin;
								autologin.open(sPath);
								autologin << username << "\n" << password;
								autologin.close();
								loadconfig();


							}
						}
						catch (const CryptoPP::Exception& e)
						{

							//MessageBoxA(nullptr, e.what(), "", MB_OK | MB_ICONERROR);
							MessageBoxA(
								nullptr,
								xorstr("There was an error while trying to communicate with our servers. Check your Internet connection and try again."),
								"", MB_OK | MB_ICONERROR);
							imguicontrole = false;
						}
					}
					else
					{
						std::ostringstream oss;
						oss << responseData;
						std::istringstream ss(responseData);
						MessageBoxA(nullptr, LPCSTR(ss.str().c_str()), "", MB_OK | MB_ICONERROR);
					}

					curl_easy_cleanup(curl);
				}
			}
			enterpressionado = false;
			login_button_pressed = false;
		}
		skipclickcondition = distribucaoint(50, 100);

		if (janelaatual.find(janelaminecraftchar) != std::string::npos)
		{
			minecraftaberto = true;
		}
		else
		{
			minecraftaberto = false;
		}
		blockhitcurrentchance = distribucaoint(0, 100);
		if (slidernovo == 2)
			delayupdown = 0;
		else
			delayupdown = distribucaoint(15, 30);

		cpsatual = (1000 / delayy);


		Sleep(cpsatual * 1000);


		updowncount = 0;
	}
	clicker2_thread_controle = false;
	return 0;
}



void windowCloseCallback(GLFWwindow* window)
{
	imguicontrole = false;
}


const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

std::string random_string(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}


std::string truncate(std::string str, size_t width, bool show_ellipsis = true)
{
	if (str.length() > width)
	{
		if (show_ellipsis)
			return str.substr(0, width) + "...";
		return str.substr(0, width);
	}
	return str;
}

int main(char* argv[])
{
	bool process_admin = false;
	// Setup window
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
	{
		MessageBoxA(nullptr, xorstr("Error on creating window, leaving..."), "", MB_OK);
		return 1;
	}

	window = glfwCreateWindow(300, 230, "", nullptr, nullptr);
	glfwSetWindowCloseCallback(window, windowCloseCallback);

	if (window == nullptr)
		return 1;

	HWND hWnd = glfwGetWin32Window(window);
	glfwMakeContextCurrent(window);


	// Setup Dear ImGui context
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = nullptr;


	(void)io;
	ImGuiStyle* style = &ImGui::GetStyle();
	style->FrameRounding = 5.0f;
	ImFont* pFont = io.Fonts->AddFontFromFileTTF("C:\\windows\\fonts\\calibri.ttf", 14.0f);


	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL2_Init();

	//Drive Serial
	//ImGuiStyle& style = ImGui::GetStyle();
	if (IsProcessElevated()) {
		process_admin = true;
	}
	for (static bool first = true; first; first = false)
	{
		int iii = 0;
		for (iii = 0; iii <= 8; iii++)
		{
			newslots[iii] = true;
		}
	}

	thread thr_hulk(HULK);
	thread thr_hulk_kb(HULK_kb);
	thread thr_click(ClickThread);
	thread thr_click2(ClickThread2);
	thread thr_timer(TimerThread);
	thread thr_pot(AutoPot);

	std::string hwidfinal;

	std::string queryhwid;


	concatenateHwid(xorstr(L"SELECT ProcessorId FROM Win32_Processor"), xorstr(L"ProcessorId"));
	concatenateHwid(xorstr(L"SELECT SerialNumber FROM Win32_BaseBoard"), xorstr(L"SerialNumber"));
	std::string::iterator end_pos = std::remove(hwidserials.begin(), hwidserials.end(), ' ');
	hwidserials.erase(end_pos, hwidserials.end());
	hashhwid = picosha2::hash256_hex_string(hwidserials);
	char* charhashhwid = new char[hashhwid.length() + 1];
	strcpy(charhashhwid, hashhwid.c_str());
	controle = 1;

	CHAR czTempPath[MAX_PATH] = { 0 };
	GetTempPathA(MAX_PATH, czTempPath); // retrieving temp path
	string sPath = czTempPath;
	sPath += hashhwid; // adding my file.bat
	if (std::filesystem::exists(sPath)) {
		std::ifstream autologin_ifs(sPath);
		std::string autologin_content((std::istreambuf_iterator<char>(autologin_ifs)),
			(std::istreambuf_iterator<char>()));


		std::string autologin_delimiter = "\n";
		string::size_type autologin_delimiter_pos = autologin_content.find(autologin_delimiter);
		if (autologin_content.npos != autologin_delimiter_pos) {

			std::string autologin_password = autologin_content.substr(autologin_delimiter_pos + 1).c_str();

			std::string autologin_username = autologin_content.substr(0, autologin_delimiter_pos);
			std::copy(autologin_username.begin(), autologin_username.end(), charusername);
			std::copy(autologin_password.begin(), autologin_password.end(), charpassword);

		}
	}



	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.00f);
	bool controlemysql1 = true;
	bool conectado = "";
	bool sanidade = false;
	char* charhashpassword;
	int colorpage = 0;
	std::string hashpassword;
	int tentativaerro = 0;
	std::string temppass = "";
	// Main loop
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.92f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.23f, 0.23f, 0.23f, 1.0f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.00f, 0.47f, 0.69f, 1.0f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.41f, 0.64f, 1.0f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.27f, 0.54f, 0.83f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.32f, 0.63f, 0.87f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.40f, 0.80f, 0.20f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.40f, 0.55f, 0.80f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 0.40f, 0.80f, 0.30f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 0.40f, 0.80f, 0.40f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 0.39f, 0.80f, 0.60f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 0.39f, 0.80f, 0.60f);
	colors[ImGuiCol_Button] = ImVec4(0.00f, 0.40f, 0.61f, 1.0f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.48f, 0.71f, 1.0f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.54f, 0.80f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.40f, 0.90f, 0.45f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.45f, 0.90f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 0.53f, 0.87f, 0.80f);
	colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.41f, 0.60f, 0.70f, 1.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.56f, 0.70f, 0.90f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.16f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 0.82f, 1.00f, 0.60f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.82f, 1.00f, 0.90f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.34f, 0.68f, 0.78f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.45f, 0.90f, 0.80f);
	colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.40f, 0.73f, 0.84f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.28f, 0.57f, 0.82f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.00f, 0.35f, 0.65f, 0.84f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.00f, 0.45f, 0.90f, 0.80f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	while (imguicontrole)
	{
		Sleep(10);
		glfwPollEvents();
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		int visible = glfwGetWindowAttrib(window, GLFW_VISIBLE);
		janelaatual = GetActiveWindowTitle();

		if (hidewindowtoggle)
		{
			if (visible)
			{
				glfwHideWindow(window);
			}
		}
		else
		{
			if (!visible)
			{
				glfwShowWindow(window);
			}
		}
		ImGui::SetNextWindowSize(ImVec2(width, height));
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::Begin(xorstr("MonkeyClicker 2.8.5"), nullptr,
			ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
		if (logado)
		{
			int contagemtext = 0;
			contagemtext = 0;
			for (static bool first = true; first; first = false)
			{
				glfwSetWindowSize(window, 700, 500);
			}


			controle = 1;

			const char* tabs[] = {
				xorstr("Main"),
				xorstr("Auto"),
				xorstr("Misc"),
				xorstr("Other")
			};
			ImGuiStyle& style = ImGui::GetStyle();


			for (int i = 0; i < IM_ARRAYSIZE(tabs); i++)
			{
				//ImGui::GetStyle().Colors[ImGuiCol_Button] = ImColor(54, 54, 54, 255);
				if (page == i)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1f, 0.1f, 0.1f, 0.1f));
					if (ImGui::Button(tabs[i], ImVec2(ImGui::GetWindowSize().x / IM_ARRAYSIZE(tabs) - 15, 0)))
						page = i;

					ImGui::PopStyleColor();
				}
				else
				{
					if (ImGui::Button(tabs[i], ImVec2(ImGui::GetWindowSize().x / IM_ARRAYSIZE(tabs) - 15, 0)))
						page = i;
				}


				//ImGui::GetStyle().Colors[ImGuiCol_Button] = ImColor(54, 54, 54, 255);

				if (i < IM_ARRAYSIZE(tabs) - 1)
					ImGui::SameLine();
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			switch (page)
			{
			case 0:

				ImGui::Checkbox(xorstr("AutoClicker###ligado"), &ligado);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("AutoClicker Main Toggle"));

				ImGui::SameLine(0.0F, -200.0F);


				if (ImGui::Button(sz_text.c_str()))
					b_get = true;
				if (b_get)
				{
					for (auto i = 1; i < 256; i++)
					{
						if (GetAsyncKeyState(i) & 0x8000)
						{
							if (i != 12)
							{
								clickerkeybind = i == VK_ESCAPE ? 0 : i;
								b_get = false;
							}
						}
					}
					sz_text = xorstr("press a key");
				}
				else if (!b_get && clickerkeybind == 0)
					sz_text = xorstr("click to bind");
				else if (!b_get && clickerkeybind != 0)
					sz_text = xorstr("bound to ") + get_key_name_by_id(clickerkeybind);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Autoclicker Hotkey"));

				ImGui::Checkbox(xorstr("Right-clicker###rightmouseligado"), &rightmouseligado);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Will RightClick when user \n holds down right-mouse"));
				ImGui::SameLine(0.0F, -200.0F);
				if (ImGui::Button(sz_text_right.c_str()))
					b_get_right = true;
				if (b_get_right)
				{
					for (auto i = 1; i < 256; i++)
					{
						if (GetAsyncKeyState(i) & 0x8000)
						{
							if (i != 12)
							{
								rightclickerkeybind = i == VK_ESCAPE ? 0 : i;
								b_get_right = false;
							}
						}
					}
					sz_text_right = xorstr("press a key");
				}
				else if (!b_get_right && rightclickerkeybind == 0)
					sz_text_right = xorstr("click to bind");
				else if (!b_get_right && rightclickerkeybind != 0)
					sz_text_right = xorstr("bound to ") + get_key_name_by_id(rightclickerkeybind);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Right Autoclicker Hotkey"));
				ImGui::Spacing();
				if (ligado || rightmouseligado)
				{
					if (slidernovo == 1)
					{
						ImGui::SliderInt(xorstr("CPS"), &nigga1, 6, 25);


						ImGui::SameLine();
						ImGui::Checkbox(xorstr("Randomize"), &randomize);
						if (ImGui::IsItemHovered())
							ImGui::SetTooltip(xorstr("Randomize the CPS the clicker will work at"));
					}
					else if (slidernovo == 2)
					{
						ImGui::SliderInt(xorstr("CPS"), &nigga1, 6, 100);
					}
					else
					{
						ImGui::SliderInt(xorstr("CPS Min"), &nigga1, 3, 25);
						ImGui::SliderInt(xorstr("CPS Max"), &nigga2, 3, 25);
					}
				}
				ImGui::Combo(xorstr("CPS Mode"), &slidernovo, tipos_cps, IM_ARRAYSIZE(tipos_cps));
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(
						xorstr("Choose your Clicker Mode: \n  Old Mode:\n  2 sliders for Minimum \n  and Max CPS\n\n  New Mode:  1 randomized \n  Slider \n\n  Blatant:\n  Extremely Fast \n  Clicking with no \n  randomization"));

				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();
				ImGui::Checkbox(xorstr("Only Weapon###filterslots"), &filterslots);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Makes the autoclicker \nonly work on certain slots"));
				int indexslots;
				int ind;

				int conditiontext;
				for (ind = 0; ind <= 8; ind++)
				{
					if (newslots[ind])
					{
						contagemtext++;
					}
					else
					{
						contagemtext--;
					}
					if (contagemtext == 9) conditiontext = 2;
					else if (contagemtext == -9) conditiontext = 3;
					else conditiontext = 1;
				}
				if (filterslots)
				{
					if (!(conditiontext == 3))
					{
						ImGui::Text(xorstr("Allowed Slots"));
					}


					for (indexslots = 0; indexslots <= 8; indexslots++)
					{
						if (newslots[indexslots] == true)
						{
							std::string s = std::to_string(indexslots + 1);

							if (ImGui::Button(s.c_str()))
							{
								newslots[indexslots] = !(newslots[indexslots]);
							}

							if (indexslots != 8)
							{
								ImGui::SameLine();
							}
						}
					}


					ImGui::Text("");
					if (!(conditiontext == 2)) ImGui::Text(xorstr("Blocked Slots"));
					for (indexslots = 0; indexslots <= 8; indexslots++)
					{
						if (newslots[indexslots] == false)
						{
							std::string s = std::to_string(indexslots + 1);

							if (ImGui::Button(s.c_str()))
							{
								newslots[indexslots] = !(newslots[indexslots]);
							}

							if (indexslots != 8)
							{
								ImGui::SameLine();
							}
						}
					}
				}

				ImGui::Text("");
				/*ImGui::SameLine();
				ImGui::InputInt("Slot###textslot", &textslot);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip("Slot which the autoclicker \nwill work if Only Weapon is activated");*/

				ImGui::Spacing();
				ImGui::Checkbox(xorstr("Click Sounds###soundstoggle"), &soundstoggle);
				ImGui::SameLine();
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Clicker will play mouse-sounds \ntogether with the clicking"));

				ImGui::Combo(xorstr("Sound###selectedsound"), &selectedsound, soundstext, IM_ARRAYSIZE(soundstext));
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Sound the Click Sounds feature will play"));

				if (selectedsound == 8) {
					ImGui::InputText(xorstr("Custom Sound Path###custom_sound_path"), custom_sound_path, 1000);
					if (ImGui::IsItemHovered())
						ImGui::SetTooltip(xorstr("//BETA//\nPut the exact path of the WAV sound file here.\nIf the path is wrong the sound will not play.\nExample: C:\\Users\\Celesian\\Desktop\\sound.wav"));
					ImGui::Checkbox(xorstr("Stop custom sound on mouse release."), &stop_custom_sound_on_release);
					ImGui::Checkbox(xorstr("Loop custom sound."), &loop_custom_sound);
				}

				break;

			case 1:

				ImGui::Checkbox(xorstr("WTap###togglewtap"), &togglewtap);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Will cancel movement while autoclicking"));

				ImGui::SliderInt(xorstr("Delay###wtapdelaymin"), &wtapdelaymin, 10, 1000);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Delay of WTap Cycle"));

				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();
				ImGui::Text(xorstr("BlockHitting"));
				ImGui::Checkbox(xorstr("Enable###blockhit"), &blockhit);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Will RightClick together \nwith Autoclicker"));
				if (blockhit)
				{
					ImGui::Checkbox(xorstr("Randomize###randomizeblockhit"), &randomizeblockhit);
					if (ImGui::IsItemHovered())
						ImGui::SetTooltip(xorstr("Randomize blockhitting"));
				}


				if (blockhit && randomizeblockhit)
				{
					ImGui::SliderInt(xorstr("Chance###randomizationpercentageblockhit"), &randomizationpercentageblockhit,
						5, 100);
					if (ImGui::IsItemHovered())
						ImGui::SetTooltip(xorstr("Chance of blockhit randomization"));
				}
				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();

				ImGui::Checkbox(xorstr("AutoPot###autopottoggle"), &autopottoggle);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Will Throw Pots / Eat Soup \n when user presses key"));
				ImGui::SameLine();
				ImGui::Hotkey(xorstr("###autopotkeybind"), &autopotkeybind, ImVec2(200.0f, 25.0f));
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Key which will \n activate AutoPot"));

				ImGui::InputInt(xorstr("Sword Slot ###slotsword"), &slotsword);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Slot which your sword is in"));
				ImGui::InputFloat(xorstr("Delay###autopotdelay"), &autopotdelay);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Delay which AutoPot will work on"));
				ImGui::InputInt(xorstr("Start ###slotmin"), &slotmin);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Start of array of items \n you want to throw/eat"));
				ImGui::InputInt("End ###slotmax", &slotmax);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("End of array of items \n you want to throw/eat"));
				if (ImGui::Button("Apply"))
				{
					autopotapply = true;
				}
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Update Values"));
				ImGui::Spacing();


				break;

			case 2:

				ImGui::Checkbox(xorstr("Window Only###windowonly"), &windowonly);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Make clicker and keybinds\n only work on the \n specified window"));

				ImGui::SameLine();
				ImGui::InputText(xorstr("Name###janelaminecraftchar"), janelaminecraftchar, 64);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Name of the window"));


				ImGui::Checkbox(xorstr("ToggleSprint###togglesprint"), &togglesprint);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Will sprint automatically for the user"));


				ImGui::Spacing();

				ImGui::Separator();
				ImGui::Spacing();
				ImGui::Checkbox(xorstr("Jitter ###jittertoggle"), &jittertoggle);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Toggles Jitter"));
				if (jittertoggle)
				{
					ImGui::SliderInt(xorstr("Jitter Strength###jitterclirk"), &jitterclirk, 1, 10);
					if (ImGui::IsItemHovered())
						ImGui::SetTooltip(xorstr("The amount of pixels jitter \n will move each cycle"));
					ImGui::InputInt(xorstr("Jitter Delay###jitterdelay"), &jitterdelay, 25, 100);
					if (ImGui::IsItemHovered())
						ImGui::SetTooltip(xorstr("Duration of jitter cycles"));

				}
				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();
				ImGui::Checkbox(xorstr("Beep on Toggle###beeptoggle"), &beeptoggle);
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Autoclicker will beep when \nthe toggle hotkey is pressed"));
				//ImGui::SameLine();
				//ImGui::Checkbox("New Slider###slidernovo", &slidernovo);




				break;

			case 3:

				if (ImGui::Button(xorstr("Self-Destruct (F9)")))
				{
					imguicontrole = false;
				}
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Will Self-Destruct Autoclicker"));


				ImGui::Spacing();

				if (ImGui::Button(xorstr("Hide (END)")))

				{
					hidewindowtoggle = !hidewindowtoggle;
				}
				if (ImGui::IsItemHovered())
					ImGui::SetTooltip(xorstr("Hide Autoclicker Window\nDon't forget to self-destruct\nShortcut: END"));
				ImGui::SameLine();
				if (ImGui::Button(xorstr("Save Config")))
				{
					saveconfig(false);
				}
				ImGui::SameLine();
				if (ImGui::Button(xorstr("Load Config")))
				{
					loadconfig();
				}
				ImGui::SameLine();
				if (ImGui::Button(xorstr("Delete Config")))
				{
					saveconfig(true);
				}


				if (colorpage == 0)
				{
					ImGui::Text(xorstr("Edit Text Color"));
					ImGui::ColorEdit4("", &style.Colors[ImGuiCol_Text].x);


					ImGui::Spacing();
					if (ImGui::Button(xorstr("Text Color")))
					{
						colorpage = 0;
					}
					if (ImGui::Button(xorstr("Background Color")))
					{
						colorpage = 1;
					}
					if (ImGui::Button(xorstr("Button Color")))
					{
						colorpage = 2;
					}
				}
				else
				{
					if (colorpage == 1)
					{
						ImGui::Text(xorstr("Edit Background Color"));
						ImGui::ColorEdit4("", &style.Colors[ImGuiCol_WindowBg].x);


						ImGui::Spacing();
						if (ImGui::Button(xorstr("Text Color")))
						{
							colorpage = 0;
						}
						if (ImGui::Button(xorstr("Background Color")))
						{
							colorpage = 1;
						}
						if (ImGui::Button(xorstr("Button Color")))
						{
							colorpage = 2;
						}
					}
					else
					{
						if (colorpage == 2)
						{
							ImGui::Text(xorstr("Edit Button Color"));
							ImGui::ColorEdit4("", &style.Colors[ImGuiCol_Button].x);


							ImGui::Spacing();
							if (ImGui::Button(xorstr("Text Color")))
							{
								colorpage = 0;
							}
							if (ImGui::Button(xorstr("Background Color")))
							{
								colorpage = 1;
							}
							if (ImGui::Button(xorstr("Button Color")))
							{
								colorpage = 2;
							}
						}
					}
				}
				ImGui::Spacing();


				//ImGui::ColorEdit4("Text Color", &style.Colors[ImGuiCol_Text].x, true);
				//ImGui::ColorEdit4("Background Color", &style.Colors[ImGuiCol_WindowBg].x, true);
				//ImGui::ColorEdit4("Button Color", &style.Colors[ImGuiCol_Button].x, true);
			}

			if (!process_admin) {
				ImGui::Spacing();
				ImGui::Text("You are not running Monkey as administrator,\nthis could lead to MonkeyClicker not working on\nsome clients.");
			}

		}
		else
		{
			//
			if (imguicontrole)
			{
				ImGui::Text("Login/Register");


				ImGui::InputText("Username", charusername, 64);
				ImGui::InputText("Password", charpassword, 64, ImGuiInputTextFlags_Password);
				if (!login_button_pressed) {
					if (ImGui::Button("Login") || enterpressionado)
					{
						enterpressionado = false;
						login_button_pressed = true;
						sanidade = true;

					}
					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));
					if (ImGui::Button("Exit"))
					{
						imguicontrole = false;
					}
					ImGui::PopStyleColor();

				}
				else {
					ImGui::Text(auth_text.c_str());
				}
			}
		}


		ImGui::End();
		ImGui::Render();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
		glfwMakeContextCurrent(window);
		glfwSwapBuffers(window);
	}


	HANDLE hulkHandle = thr_hulk.native_handle();
	PostThreadMessage(GetThreadId(hulkHandle), WM_QUIT, 0, 0);



	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	thr_hulk.detach();
	thr_hulk_kb.detach();
	thr_click.detach();
	thr_click2.detach();
	thr_timer.detach();
	thr_pot.detach();
	glfwDestroyWindow(window);
	glfwTerminate();

	if (logado) {
		const int result = MessageBox(NULL, xorstr("Do you want the clicker to forget your saved login?"), xorstr(""), MB_YESNO);
		if (result == IDYES) {
			CHAR czTempDeletePath[MAX_PATH] = { 0 };
			GetTempPathA(MAX_PATH, czTempDeletePath); // retrieving temp path
			string sDeletePath = czTempDeletePath;
			sDeletePath += hashhwid; // adding my file.bat
			DeleteFileA(sDeletePath.c_str());
		}
	}
	return 0;
}
