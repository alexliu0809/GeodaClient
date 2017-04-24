//
//  toolbars.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef toolbars_h
#define toolbars_h

#include <wx/wx.h>

class Toolbar : public wxFrame
{
public:
    Toolbar(const wxString& title);
    
    void OnQuit(wxCommandEvent& event);
    
    wxToolBar *toolbar1;
    wxToolBar *toolbar2;
    
};


#endif /* toolbars_h */
