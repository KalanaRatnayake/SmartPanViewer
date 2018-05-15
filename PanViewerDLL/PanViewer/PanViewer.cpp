// PanViewer.cpp : Defines the exported functions for the DLL application.
//

#include <stdio.h>
#include "panViewerUI.h"

panViewerUI pvui;

extern "C" {

	__declspec(dllexport) void createUI(int left, int middle, int right, int width, int height) {
		pvui = panViewerUI(left, middle, right, width, height);
	}

	__declspec(dllexport) void openCameraOutput() {
		pvui.openCameraOutput();
	}

	__declspec(dllexport) void stitchedOutput() {
		pvui.stitchedOutput();
	}

	__declspec(dllexport) void deleteUI() {
		pvui.deleteUI();
	}
}