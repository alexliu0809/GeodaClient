//
//  menu.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <wx/wx.h>
#include <wx/menu.h>

class SimpleMenu : public wxFrame
{
public:
    SimpleMenu(const wxString& title);
    
    void OnQuit(wxCommandEvent& event);
    
    wxMenuBar *menubar;
    wxMenu *file;
    
};

#endif /* menu_h */
