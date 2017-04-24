//
//  align.cpp
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//
#include "align.h"

Align::Align(const wxString& title)
: wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(300, 200))
{
    
    wxPanel *panel = new wxPanel(this, -1);
    
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    
    wxButton *ok = new wxButton(panel, -1, wxT("Ok"));
    wxButton *cancel = new wxButton(panel, -1, wxT("Cancel"));
    
    hbox1->Add(new wxPanel(panel, -1));
    vbox->Add(hbox1, 1, wxEXPAND);
    
    
    hbox2->Add(ok);
    hbox2->Add(cancel);
    
    vbox->Add(hbox2, 0, wxALIGN_CENTER_HORIZONTAL |  wxBOTTOM , 30); //10 is space here for right and botton
    panel->SetSizer(vbox);
    
    Centre();
}
