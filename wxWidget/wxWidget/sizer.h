//
//  sizer.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef sizer_h
#define sizer_h

#include <wx/wx.h>

class Sizer : public wxFrame
{
public:
    Sizer(const wxString& title);
    
    wxMenuBar *menubar;
    wxMenu *file;
    wxMenu *edit;
    wxMenu *help;
    wxTextCtrl *textctrl;
    
};

#endif /* sizer_h */
