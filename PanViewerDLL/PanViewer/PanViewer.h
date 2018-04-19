#pragma once
#include <stdexcept>

extern "C" { __declspec(dllexport) void createUI(int left, int middle, int right, int width, int height); }

extern "C" { __declspec(dllexport) void openCameraOutput(); }

extern "C" { __declspec(dllexport) void stitchedOutput(); }

extern "C" { __declspec(dllexport) void deleteUI(); }

