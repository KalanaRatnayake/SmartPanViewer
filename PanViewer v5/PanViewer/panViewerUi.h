///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May 29 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/wrapsizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/bmpbuttn.h>
#include "wtypes.h"
#include <iostream>
#include "panViewerCore.h"
#include "wx/thread.h"
#include "boost\chrono.hpp"
#include "boost\thread.hpp"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class FrameInitial
///////////////////////////////////////////////////////////////////////////////
class FrameInitial : public wxFrame 
{
	private:
		//event handlers
		void onQuit(wxCommandEvent& event);
		void onStart(wxCommandEvent& event);
	
	protected:
		wxStaticBitmap* leftCamera;
		wxStaticText* m_staticText4;
		wxSlider* leftCamSelector;
		wxStaticBitmap* middleCam;
		wxStaticText* m_staticText5;
		wxSlider* m_slider5;
		wxButton* m_button8;
		wxStaticBitmap* rightCam;
		wxStaticText* m_staticText7;
		wxSlider* m_slider7;
		wxButton* m_button9;
	
	public:
		panViewerCore commonCore;
		boost::thread display;
		
		FrameInitial(panViewerCore& core, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PanViewer 2.0"), const wxPoint& pos = wxPoint( 0,0 ), const wxSize& size = wxSize( 840,410 ), long style = wxDEFAULT_FRAME_STYLE | wxMAXIMIZE | wxSTAY_ON_TOP | wxTAB_TRAVERSAL);
		
		void DisplayCameras(panViewerCore& commonCore);

		~FrameInitial();

		wxDECLARE_EVENT_TABLE();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FrameStitched
///////////////////////////////////////////////////////////////////////////////
class FrameStitched : public wxFrame 
{
	private:
	
	protected:
		wxStaticBitmap* stitichedImage;
		wxBitmapButton* mapImage;
		wxButton* btnBackStitched;
		wxButton* btnExitStitched;
		
		// Virtual event handlers, overide them in your derived class
		virtual void True( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FrameStitched(panViewerCore& core, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PanViewer 2.0"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 840,410 ), long style = wxDEFAULT_FRAME_STYLE | wxMAXIMIZE | wxSTAY_ON_TOP | wxTAB_TRAVERSAL);
		
		void displayStitched(panViewerCore& core);

		~FrameStitched();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class frameMap
///////////////////////////////////////////////////////////////////////////////
class frameMap : public wxFrame 
{
	private:
	
	protected:
		wxStaticBitmap* mapImage;
		wxStaticBitmap* stitchedImage;
		wxButton* btnBackMap;
		wxButton* btnExitMap;
		
		// Virtual event handlers, overide them in your derived class
		virtual void True( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		frameMap( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PanViewer 2.0"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 840,410 ), long style = wxDEFAULT_FRAME_STYLE | wxMAXIMIZE | wxSTAY_ON_TOP | wxTAB_TRAVERSAL);
		
		void displayMap(panViewerCore& core);

		~frameMap();
	
};

#endif //__NONAME_H__

enum
{
	QUIT = wxID_EXIT,
	START,
};