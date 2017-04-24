//
//  absolute.cpp
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//


#include "absolute.h"


Absolute::Absolute(const wxString& title)
: wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(250, 180))
{
    
    wxPanel *panel = new wxPanel(this, -1);
    
    menubar = new wxMenuBar;
    file = new wxMenu;
    edit = new wxMenu;
    help = new wxMenu;
    
    menubar->Append(file, wxT("&File"));
    menubar->Append(edit, wxT("&Edit"));
    menubar->Append(help, wxT("&Help"));
    SetMenuBar(menubar);
    
    textctrl = new wxTextCtrl(panel, -1, wxT(""), wxPoint(-1, -1),
                              wxSize(250, 150));
    
    Centre();
}
