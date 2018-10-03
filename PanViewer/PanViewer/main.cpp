#include <wx/wx.h>
#include "panViewerUi.h"


class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }
	bool shuttingDown;
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
	int horizontal;
	int vertical;
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;

	panViewerCore core;
	core = panViewerCore(0, 1, 2, horizontal/3, vertical/2 );

	wxFrame* mainFrame = new FrameInitial(core, NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}