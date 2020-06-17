#pragma once
#include "imgui.h"
#include "imgui_internal.h"
#include <Windows.h>
namespace ImGui {
	bool Hotkey(const char* label, int* k, const ImVec2& size_arg);
}
