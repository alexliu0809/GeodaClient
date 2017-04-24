//
//  Communicate.cpp
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#include <stdio.h>
#include "Communicate.h"

Communicate::Communicate(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(290, 150))
{
    m_parent = new wxPanel(this, wxID_ANY);
    
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    
    m_lp = new LeftPanel(m_parent);
    m_rp = new RightPanel(m_parent);
    
    hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
    hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);
    
    m_parent->SetSizer(hbox);
    
    this->Centre();
}
