#pragma once

class panViewerUI
{
public:
	panViewerUI();

	panViewerUI(int left, int middle, int right);

	void openCameraOutput();

	void stitchedOutput();

	void openAllOutputs();

	void deleteUI();
};

