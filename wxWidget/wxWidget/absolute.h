//
//  absolute.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef absolute_h
#define absolute_h

#include <wx/wx.h>

class Absolute : public wxFrame
{
public:
    Absolute(const wxString& title);
    
    wxMenuBar *menubar;
    wxMenu *file;
    wxMenu *edit;
    wxMenu *help;
    wxTextCtrl *textctrl;
    
};

#endif /* absolute_h */
