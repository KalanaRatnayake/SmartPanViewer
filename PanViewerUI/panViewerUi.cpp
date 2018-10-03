///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

FrameInitial::FrameInitial( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* Layout;
	Layout = new wxBoxSizer( wxHORIZONTAL );
	
	Layout->SetMinSize( wxSize( 840,400 ) ); 
	wxWrapSizer* LeftCameraDock;
	LeftCameraDock = new wxWrapSizer( wxVERTICAL );
	
	wxStaticBoxSizer* LeftCameraViewer;
	LeftCameraViewer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	LeftCameraViewer->SetMinSize( wxSize( 165,150 ) ); 
	leftCamera = new wxStaticBitmap( LeftCameraViewer->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 266,200 ), 0 );
	LeftCameraViewer->Add( leftCamera, 1, 0, 0 );
	
	
	LeftCameraDock->Add( LeftCameraViewer, 1, wxALIGN_CENTER_HORIZONTAL, 0 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Select New Left Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetMinSize( wxSize( 245,15 ) );
	
	LeftCameraDock->Add( m_staticText4, 1, wxALL, 15 );
	
	leftCamSelector = new wxSlider( this, wxID_ANY, 0, 0, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	leftCamSelector->SetMinSize( wxSize( 245,25 ) );
	
	LeftCameraDock->Add( leftCamSelector, 1, wxALL, 15 );
	
	
	Layout->Add( LeftCameraDock, 1, 0, 0 );
	
	wxWrapSizer* middleCameraDock;
	middleCameraDock = new wxWrapSizer( wxVERTICAL );
	
	wxStaticBoxSizer* middleCameraViewer;
	middleCameraViewer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	middleCameraViewer->SetMinSize( wxSize( 165,150 ) ); 
	middleCam = new wxStaticBitmap( middleCameraViewer->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 266,200 ), 0 );
	middleCameraViewer->Add( middleCam, 1, 0, 0 );
	
	
	middleCameraDock->Add( middleCameraViewer, 1, wxALIGN_CENTER_HORIZONTAL, 0 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Select New Middle Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetMinSize( wxSize( 245,15 ) );
	
	middleCameraDock->Add( m_staticText5, 1, wxALL, 15 );
	
	m_slider5 = new wxSlider( this, wxID_ANY, 1, 0, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider5->SetMinSize( wxSize( 245,25 ) );
	
	middleCameraDock->Add( m_slider5, 1, wxALL, 15 );
	
	m_button8 = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button8->SetMinSize( wxSize( 245,40 ) );
	
	middleCameraDock->Add( m_button8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	Layout->Add( middleCameraDock, 1, 0, 2 );
	
	wxWrapSizer* rightCameraDoc;
	rightCameraDoc = new wxWrapSizer( wxVERTICAL );
	
	wxStaticBoxSizer* rightCameraViewer;
	rightCameraViewer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	rightCameraViewer->SetMinSize( wxSize( 165,150 ) ); 
	rightCam = new wxStaticBitmap( rightCameraViewer->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 265,200 ), 0 );
	rightCameraViewer->Add( rightCam, 1, 0, 0 );
	
	
	rightCameraDoc->Add( rightCameraViewer, 1, wxALIGN_RIGHT, 0 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Select New Right Camera"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	m_staticText7->SetMinSize( wxSize( 245,15 ) );
	
	rightCameraDoc->Add( m_staticText7, 1, wxALL, 15 );
	
	m_slider7 = new wxSlider( this, wxID_ANY, 2, 0, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider7->SetMinSize( wxSize( 245,25 ) );
	
	rightCameraDoc->Add( m_slider7, 1, wxALL, 15 );
	
	m_button9 = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button9->SetMinSize( wxSize( 245,40 ) );
	
	rightCameraDoc->Add( m_button9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	Layout->Add( rightCameraDoc, 1, 0, 0 );
	
	
	this->SetSizer( Layout );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameInitial::True ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameInitial::True ), NULL, this );
}

FrameInitial::~FrameInitial()
{
	// Disconnect Events
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameInitial::True ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameInitial::True ), NULL, this );
	
}

FrameStitched::FrameStitched( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* wholeLayout;
	wholeLayout = new wxBoxSizer( wxVERTICAL );
	
	wholeLayout->SetMinSize( wxSize( 840,400 ) ); 
	wxStaticBoxSizer* stitchedView;
	stitchedView = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	stitchedView->SetMinSize( wxSize( 820,200 ) ); 
	stitichedImage = new wxStaticBitmap( stitchedView->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 820,200 ), 0 );
	stitchedView->Add( stitichedImage, 1, wxALL, 0 );
	
	
	wholeLayout->Add( stitchedView, 1, 0, 0 );
	
	wxWrapSizer* ControlViewStitched;
	ControlViewStitched = new wxWrapSizer( wxHORIZONTAL );
	
	ControlViewStitched->SetMinSize( wxSize( 840,180 ) ); 
	wxWrapSizer* MapViewer;
	MapViewer = new wxWrapSizer( wxHORIZONTAL );
	
	MapViewer->SetMinSize( wxSize( 620,150 ) ); 
	mapImage = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 620,150 ), wxBU_AUTODRAW );
	
	mapImage->SetBitmapDisabled( wxNullBitmap );
	mapImage->SetMinSize( wxSize( 620,150 ) );
	
	MapViewer->Add( mapImage, 1, wxALL, 0 );
	
	
	ControlViewStitched->Add( MapViewer, 1, 0, 0 );
	
	wxWrapSizer* Controller;
	Controller = new wxWrapSizer( wxVERTICAL );
	
	Controller->SetMinSize( wxSize( 200,150 ) ); 
	btnBackStitched = new wxButton( this, wxID_ANY, wxT("Back"), wxDefaultPosition, wxSize( 200,75 ), 0 );
	btnBackStitched->SetMinSize( wxSize( 200,75 ) );
	
	Controller->Add( btnBackStitched, 1, wxALL, 0 );
	
	btnExitStitched = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxSize( 200,75 ), 0 );
	btnExitStitched->SetMinSize( wxSize( 200,75 ) );
	
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

FrameStitched::~FrameStitched()
{
	// Disconnect Events
	mapImage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	btnBackStitched->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	btnExitStitched->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameStitched::True ), NULL, this );
	
}

frameMap::frameMap( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* wholeLayout;
	wholeLayout = new wxBoxSizer( wxVERTICAL );
	
	wholeLayout->SetMinSize( wxSize( 840,400 ) ); 
	wxStaticBoxSizer* mapView;
	mapView = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	mapView->SetMinSize( wxSize( 820,200 ) ); 
	mapImage = new wxStaticBitmap( mapView->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 820,200 ), 0 );
	mapView->Add( mapImage, 1, wxALL, 0 );
	
	
	wholeLayout->Add( mapView, 1, wxALL, 0 );
	
	wxWrapSizer* ControlViewMap
	;
	ControlViewMap
	= new wxWrapSizer( wxHORIZONTAL );
	
	ControlViewMap
	->SetMinSize( wxSize( 840,180 ) );
	wxWrapSizer* StitchedViewer;
	StitchedViewer = new wxWrapSizer( wxHORIZONTAL );
	
	StitchedViewer->SetMinSize( wxSize( 620,150 ) ); 
	stitchedImage = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 620,150 ), 0 );
	stitchedImage->SetMinSize( wxSize( 620,150 ) );
	
	StitchedViewer->Add( stitchedImage, 1, wxALL, 0 );
	
	
	ControlViewMap
	->Add( StitchedViewer, 1, 0, 0 );
	
	wxWrapSizer* Controller;
	Controller = new wxWrapSizer( wxVERTICAL );
	
	Controller->SetMinSize( wxSize( 200,150 ) ); 
	btnBackMap = new wxButton( this, wxID_ANY, wxT("Back"), wxDefaultPosition, wxSize( 200,75 ), 0 );
	btnBackMap->SetMinSize( wxSize( 200,75 ) );
	
	Controller->Add( btnBackMap, 1, 0, 0 );
	
	btnExitMap = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxSize( 200,75 ), 0 );
	btnExitMap->SetMinSize( wxSize( 200,75 ) );
	
	Controller->Add( btnExitMap, 1, wxALL, 0 );
	
	
	ControlViewMap
	->Add( Controller, 1, 0, 0 );
	
	
	wholeLayout->Add( ControlViewMap
	, 1, 0, 0 );
	
	
	this->SetSizer( wholeLayout );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnBackMap->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
	btnExitMap->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
}

frameMap::~frameMap()
{
	// Disconnect Events
	btnBackMap->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
	btnExitMap->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMap::True ), NULL, this );
	
}
