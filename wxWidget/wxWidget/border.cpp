//
//  border.cpp
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#include "border.h"

Border::Border(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 200))
{
    wxColour col1, col2;
    col1.Set(wxT("#4f5049"));
    col2.Set(wxT("#ededed"));
    
    wxPanel *panel = new wxPanel(this, -1);
    panel->SetBackgroundColour(col1);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    
    wxPanel *midPan = new wxPanel(panel, wxID_ANY);
    midPan->SetBackgroundColour(col2);
    
    vbox->Add(midPan, 1, wxEXPAND | wxALL, 20);
    panel->SetSizer(vbox);
    
    Centre();
}
