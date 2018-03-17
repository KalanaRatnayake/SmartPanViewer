#pragma once
#include <stdexcept>

extern "C" { __declspec(dllexport) void createCore(int left, int middle, int right); }

extern "C" { __declspec(dllexport) uchar* returnLeftCameraImage(); }

extern "C" { __declspec(dllexport) uchar* returnMiddleCameraImage(); }

extern "C" { __declspec(dllexport) uchar* returnRightCameraImage(); }

extern "C" { __declspec(dllexport) uchar* returnStitchedImage(); }

