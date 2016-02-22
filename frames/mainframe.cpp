
#include "mainframe.hpp"

// Static events handling
// Event table for MainFrame
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
//   EVT_MENU	(wxID_ABOUT, 		MainFrame::OnAbout)
  EVT_MENU	(wxID_EXIT, 		MainFrame::OnQuit)
  EVT_SIZE	(			MainFrame::OnSize)
  EVT_BUTTON	(wxID_OK, 		MainFrame::OnButtonOK)
END_EVENT_TABLE()

void MainFrame::OnAbout(wxCommandEvent& event)
{
  wxString msg;
  msg.Printf(wxT("Hello and welcome to %s"), wxVERSION_STRING);
  wxMessageBox(msg, wxT("About Experimental"), wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
  // Destroy the frame
  Close();
}

void MainFrame::OnSize(wxSizeEvent& event)
{
}

void MainFrame::OnButtonOK(wxCommandEvent& event)
{
  wxMessageBox(wxT("You pressed OK button"), wxT("OK"), wxOK | wxICON_INFORMATION | wxCENTRE, this);
}


#include "../icon.xpm"

MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
  // Set the frame icon
  SetIcon(wxIcon(icon_xpm));
  // Create a file menu bar
  wxMenu *fileMenu = new wxMenu;
  // The "About" item should be in the help menu
  wxMenu *helpMenu = new wxMenu;
  helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));
  fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"), wxT("Quit this program"));
  // Now append the freshly created menu to the menu bar...
  wxMenuBar *menuBar = new wxMenuBar();
  menuBar->Append(fileMenu, wxT("&File"));
  menuBar->Append(helpMenu, wxT("&Help"));
  // ... and attach this menu bar to the frame
  SetMenuBar(menuBar);
  
  // add button to demonstrate  button event handling by mainframe
  wxButton* button = new wxButton(this, wxID_OK, wxT("OK"), wxPoint(0, 0));
  
  // Create a status bar just for future
  CreateStatusBar(2);
  SetStatusText(wxT("Welcome to wxWidgets!"));
}
