///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "panViewerUi.h"

///////////////////////////////////////////////////////////////////////////

wxBEGIN_EVENT_TABLE(FrameInitial, wxFrame)
EVT_MENU(QUIT, FrameInitial::onQuit)
EVT_MENU(START, FrameInitial::onStart)
wxEND_EVENT_TABLE()


panViewerCore commonCore;
boost::thread display;

FrameInitial::FrameInitial(panViewerCore& core, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	commonCore = core;
	//get the screen resolution to maximize window in anycomputer
	int horizontal;
	int vertical;
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
	//end of screen resolution finding snippet

	this->SetSizeHints(wxSize(horizontal, vertical), wxSize(horizontal, vertical));
	
	wxBoxSizer* Layout;
	Layout = new wxBoxSizer( wxHORIZONTAL );
	Layout->SetMinSize( wxSize(horizontal, vertical) );

	wxWrapSizer* LeftCameraDock;
	LeftCameraDock = new wxWrapSizer( wxVERTICAL );
	
	wxStaticBoxSizer* LeftCameraViewer;
	LeftCameraViewer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );	
	LeftCameraViewer->SetMinSize( wxSize( 165,150 ) );

	leftCamera = new wxStaticBitmap( LeftCameraViewer->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(horizontal/3, vertical/2), 0 );

	LeftCameraViewer->Add( leftCamera, 1, 0, 0 );
	LeftCameraDock->Add( LeftCameraViewer, 1, wxALIGN_CENTER_HORIZONTAL, 0 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Select New Left Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetMinSize(wxSize(horizontal/4, vertical/20));
	
	LeftCameraDock->Add( m_staticText4, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 40 );
	
	leftCamSelector = new wxSlider( this, wxID_ANY, 0, 0, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	leftCamSelector->SetMinSize(wxSize(horizontal / 4, vertical / 20));
	
	LeftCameraDock->Add( leftCamSelector, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 10 );
	Layout->Add( LeftCameraDock, 1, 0, 0 );
	
	wxWrapSizer* middleCameraDock;
	middleCameraDock = new wxWrapSizer( wxVERTICAL );
	
	wxStaticBoxSizer* middleCameraViewer;
	middleCameraViewer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	middleCameraViewer->SetMinSize( wxSize( 165,150 ) );

	middleCam = new wxStaticBitmap( middleCameraViewer->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(horizontal/3, vertical/2), 0 );
	middleCameraViewer->Add( middleCam, 1, 0, 0 );
	
	middleCameraDock->Add( middleCameraViewer, 1, wxALIGN_CENTER_HORIZONTAL, 0 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Select New Middle Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetMinSize(wxSize(horizontal / 4, vertical / 20));
	
	middleCameraDock->Add( m_staticText5, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 40 );
	
	m_slider5 = new wxSlider( this, wxID_ANY, 1, 0, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider5->SetMinSize(wxSize(horizontal / 4, vertical / 20));
	
	middleCameraDock->Add( m_slider5, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_button8 = new wxButton( this, START, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button8->SetMinSize(wxSize(horizontal / 4, vertical / 10));
	
	middleCameraDock->Add( m_button8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );	
	Layout->Add( middleCameraDock, 1, 0, 2 );
	
	wxWrapSizer* rightCameraDoc;
	rightCameraDoc = new wxWrapSizer( wxVERTICAL );
	
	wxStaticBoxSizer* rightCameraViewer;
	rightCameraViewer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	rightCameraViewer->SetMinSize( wxSize( 165,150 ) );

	rightCam = new wxStaticBitmap( rightCameraViewer->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(horizontal/3, vertical/2), 0 );
	rightCameraViewer->Add( rightCam, 1, 0, 0 );
	
	rightCameraDoc->Add( rightCameraViewer, 1, wxALIGN_RIGHT, 0 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Select New Right Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	m_staticText7->SetMinSize(wxSize(horizontal / 4, vertical / 20));
	
	rightCameraDoc->Add( m_staticText7, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 40 );
	
	m_slider7 = new wxSlider( this, wxID_ANY, 2, 0, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider7->SetMinSize(wxSize(horizontal / 4, vertical / 20));
	
	rightCameraDoc->Add( m_slider7, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_button9 = new wxButton( this, QUIT, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button9->SetMinSize(wxSize(horizontal / 4, vertical / 10));
	
	rightCameraDoc->Add( m_button9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	Layout->Add( rightCameraDoc, 1, 0, 0 );
	
	this->SetSizer( Layout );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, START, NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, QUIT, NULL, this );

	display = boost::thread{ FrameInitial::DisplayCameras, commonCore };
}

void FrameInitial::DisplayCameras(panViewerCore& commonCore) {
	int left, middle, right;
	cv::Mat leftIn, middleIn, rightIn;
	wxImage leftTemp, middleTemp, rightTemp;
	wxBitmap leftCamB, middleCamB, rightCamB;

	while (true) {
		left = leftCamSelector->GetValue();
		middle = m_slider5->GetValue();
		right = m_slider7->GetValue();

		leftIn = commonCore.leftCameraImage();
		middleIn = commonCore.middleCameraImage();
		rightIn = commonCore.rightCameraImage();

		leftTemp = wxImage(leftIn.cols, leftIn.rows, leftIn.data, true);
		middleTemp = wxImage(middleIn.cols, middleIn.rows, middleIn.data, true);
		rightTemp = wxImage(rightIn.cols, rightIn.rows, rightIn.data, true);

		leftCamB = wxBitmap(leftTemp);
		middleCamB = wxBitmap(middleTemp);
		rightCamB = wxBitmap(rightTemp);

		if (left == 0) {
			leftCamera->SetBitmap(leftCamB);
		}
		else if (left == 1) {
			leftCamera->SetBitmap(middleCamB);
		}
		else if (left == 2) {
			leftCamera->SetBitmap(rightCamB);
		}

		if (middle == 0) {
			middleCam->SetBitmap(leftCamB);
		}
		else if (middle == 1) {
			middleCam->SetBitmap(middleCamB);
		}
		else if (middle == 2) {
			middleCam->SetBitmap(rightCamB);
		}

		if (right == 0) {
			rightCam->SetBitmap(leftCamB);
		}
		else if (right == 1) {
			rightCam->SetBitmap(middleCamB);
		}
		else if (right == 2) {
			rightCam->SetBitmap(rightCamB);
		}
	}
}

void FrameInitial::onStart(wxCommandEvent& WXUNUSED(event)) {
	this->Show(false);
	wxFrame* StitichFrame = new FrameStitched(commonCore, NULL);
	StitichFrame->Show(true);
}

void FrameInitial::onQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

FrameInitial::~FrameInitial()
{
	// Disconnect Events
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, START, NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, QUIT, NULL, this );
	
}

FrameStitched::FrameStitched(panViewerCore& core, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	//get the screen resolution to maximize window in anycomputer
	int horizontal;
	int vertical;
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
	//end of screen resolution finding snippet


	this->SetSizeHints(wxSize(horizontal, vertical), wxSize(horizontal, vertical));
	
	wxBoxSizer* wholeLayout;
	wholeLayout = new wxBoxSizer( wxVERTICAL );
	wholeLayout->SetMinSize(wxSize(horizontal, vertical-50));
	
	wxStaticBoxSizer* stitchedView;
	stitchedView = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	stitchedView->SetMinSize(wxSize(horizontal-15, 5 * (vertical - 50) / 9));
	
	stitichedImage = new wxStaticBitmap( stitchedView->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(horizontal-15, 5 * (vertical - 50) / 9), 0 );
	
	stitchedView->Add( stitichedImage, 1, wxALL, 0 );
	wholeLayout->Add( stitchedView, 1, 0, 0 );
	
	wxWrapSizer* ControlViewStitched;
	ControlViewStitched = new wxWrapSizer( wxHORIZONTAL );
	ControlViewStitched->SetMinSize(wxSize(horizontal-15, 4 * (vertical - 50) / 9));
	
	wxWrapSizer* MapViewer;
	MapViewer = new wxWrapSizer( wxHORIZONTAL );
	MapViewer->SetMinSize(wxSize(5*(horizontal-10) / 6, 4 * (vertical - 50) / 9));
	
	mapImage = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(5 * (horizontal - 10) / 6, 4 * (vertical - 50) / 9), wxBU_AUTODRAW );
	mapImage->SetBitmapDisabled( wxNullBitmap );
	mapImage->SetMinSize(wxSize(5 * (horizontal - 10) / 6, 4* (vertical - 50) / 9));
	
	MapViewer->Add( mapImage, 1, wxALL, 0 );
	ControlViewStitched->Add( MapViewer, 1, wxALL, 2 );
	
	wxWrapSizer* Controller;
	Controller = new wxWrapSizer( wxVERTICAL );
	Controller->SetMinSize( wxSize((horizontal - 10) / 6, 2 * (vertical - 50) / 9));
	
	btnBackStitched = new wxButton( this, wxID_ANY, wxT("Back"), wxDefaultPosition, wxSize((horizontal - 10) / 6, 2*(vertical - 120) / 9), 0 );
	btnBackStitched->SetMinSize(wxSize((horizontal - 10) / 6, 2*(vertical - 120) / 9));
	Controller->Add( btnBackStitched, 1, wxALL, 0 );
	
	btnExitStitched = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxSize((horizontal - 10) / 6, 2*(vertical - 120) / 9), 0 );
	btnExitStitched->SetMinSize(wxSize((horizontal - 10) / 6, 2*(vertical - 120) / 9));
	Controller->Add( btnExitStitched, 1, wxALL, 0 );
	
	
	ControlViewStitched->Add( Controller, 1, 0, 0 );
	wholeLayout->Add( ControlViewStitched, 1, 0, 0 );
	
	
	this->SetSizer( wholeLayout );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	mapImage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	btnBackStitched->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	btnExitStitched->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
}

void FrameStitched::displayStitched(panViewerCore& core) {
	cv::Mat stitchedIn;
	wxImage stitchedTemp;
	wxBitmap stitchedCamB;

	while (true) {
		stitchedIn = core.stitchedImage();

		stitchedTemp = wxImage(stitchedIn.cols, stitchedIn.rows, stitchedIn.data, true);
		
		stitchedCamB = wxBitmap(stitchedTemp);

		stitichedImage->SetBitmap(stitchedCamB);
	
	}
}

FrameStitched::~FrameStitched()
{
	// Disconnect Events
	mapImage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	btnBackStitched->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	btnExitStitched->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	
}

frameMap::frameMap( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	//get the screen resolution to maximize window in anycomputer
	int horizontal;
	int vertical;
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
	//end of screen resolution finding snippet

	this->SetSizeHints(wxSize(horizontal, vertical), wxSize(horizontal, vertical));
	
	wxBoxSizer* wholeLayout;
	wholeLayout = new wxBoxSizer( wxVERTICAL );
	wholeLayout->SetMinSize(wxSize(horizontal, vertical - 50));
	
	wxStaticBoxSizer* mapView;
	mapView = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	mapView->SetMinSize(wxSize(horizontal - 15, 5 * (vertical - 50) / 9));

	mapImage = new wxStaticBitmap( mapView->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(horizontal - 15, 5 * (vertical - 50) / 9), 0 );
	mapView->Add( mapImage, 1, wxALL, 0 );	
	wholeLayout->Add( mapView, 1, wxALL, 0 );
	
	wxWrapSizer* ControlViewMap;
	ControlViewMap = new wxWrapSizer( wxHORIZONTAL );
	ControlViewMap->SetMinSize(wxSize(horizontal - 15, 4 * (vertical - 50) / 9));

	wxWrapSizer* StitchedViewer;
	StitchedViewer = new wxWrapSizer( wxHORIZONTAL );
	
	StitchedViewer->SetMinSize(wxSize(5 * (horizontal - 10) / 6, 4 * (vertical - 50) / 9));
	stitchedImage = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize(5 * (horizontal - 10) / 6, 4 * (vertical - 50) / 9), 0 );
	stitchedImage->SetMinSize(wxSize(5 * (horizontal - 10) / 6, 4 * (vertical - 50) / 9));
	
	StitchedViewer->Add( stitchedImage, 1, wxALL, 0 );
	ControlViewMap->Add( StitchedViewer, 1, wxALL, 3 );
	
	wxWrapSizer* Controller;
	Controller = new wxWrapSizer( wxVERTICAL );
	Controller->SetMinSize(wxSize((horizontal - 10) / 6, 2 * (vertical - 50) / 9));
	
	btnBackMap = new wxButton( this, wxID_ANY, wxT("Back"), wxDefaultPosition, wxSize((horizontal - 10) / 6, 2 * (vertical - 120) / 9), 0 );
	btnBackMap->SetMinSize(wxSize((horizontal - 10) / 6, 2 * (vertical - 120) / 9));
	
	Controller->Add( btnBackMap, 1, 0, 0 );
	
	btnExitMap = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxSize((horizontal - 10) / 6, 2 * (vertical - 120) / 9), 0 );
	btnExitMap->SetMinSize(wxSize((horizontal - 10) / 6, 2 * (vertical - 120) / 9));
	
	Controller->Add( btnExitMap, 1, wxALL, 0 );
	ControlViewMap->Add( Controller, 1, 0, 0 );
	wholeLayout->Add( ControlViewMap, 1, 0, 0 );
	
	this->SetSizer( wholeLayout );
	this->Layout();
	this->Centre( wxBOTH );
	
	// Connect Events
	btnBackMap->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
	btnExitMap->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
}

void frameMap::displayMap(panViewerCore& core) {
	cv::Mat stitchedIn;
	wxImage stitchedTemp;
	wxBitmap stitchedCamB;

	while (true) {
		stitchedIn = core.stitchedImage();

		stitchedTemp = wxImage(stitchedIn.cols, stitchedIn.rows, stitchedIn.data, true);

		stitchedCamB = wxBitmap(stitchedTemp);

		stitchedImage->SetBitmap(stitchedCamB);

	}
}

frameMap::~frameMap()
{
	// Disconnect Events
	btnBackMap->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
	btnExitMap->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
}