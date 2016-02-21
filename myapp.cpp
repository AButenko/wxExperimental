// Name: main.cpp
// Purpose: Experimental wxWidgets sample
// Author: Anton Butenko

#include "wx/wx.h"
#include "frames/mainframe.hpp"

// Declare the application class
class WxExp : public wxApp
{
  public:
    // Called on application startup
    virtual bool OnInit();

};

// Implements WxExp& GetApp()
DECLARE_APP(WxExp)
// Give wxWidgets the means to create a WxExp object
IMPLEMENT_APP(WxExp)


// Initialize the application
bool WxExp::OnInit()
{
  // Create the main application window
  MainFrame *frame = new MainFrame(wxT("Experimental wxWidgets App"));
  
  //example of dynamic events handling
  frame->Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnAbout));
  // Show it
  frame->Show(true);
  // Start the event loop
  return true;
}

