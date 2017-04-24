//
//  Panels.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef Panels_h
#define Panels_h

#include <wx/wx.h>
#include <wx/panel.h>

class LeftPanel : public wxPanel
{
public:
    LeftPanel(wxPanel *parent);
    
    void OnPlus(wxCommandEvent & event);
    void OnMinus(wxCommandEvent & event);
    
    wxButton *m_plus;
    wxButton *m_minus;
    wxPanel *m_parent;
    int count;
    
};

class RightPanel : public wxPanel
{
public:
    RightPanel(wxPanel *parent);
    
    void OnSetText(wxCommandEvent & event);
    
    wxStaticText *m_text;
    
};

const int ID_PLUS = 101;
const int ID_MINUS = 102;

#endif /* Panels_h */
