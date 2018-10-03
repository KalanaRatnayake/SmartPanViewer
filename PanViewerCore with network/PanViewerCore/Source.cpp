#include "panViewerUI.h"
#include <opencv2/opencv.hpp>

int main() {
	panViewerUI ui;
	
	ui = panViewerUI(2, 1, 0, 1200, 600);

	ui.openAllOutputs();
}