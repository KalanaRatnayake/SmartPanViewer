#include "panViewerUI.h"

int main() {
	panViewerUI ui = panViewerUI(2, 1, 0, 1200, 300);

	//ui.openCameraOutput();
	ui.stitchedOutput();
}