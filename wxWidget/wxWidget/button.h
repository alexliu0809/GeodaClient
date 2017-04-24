//
//  button.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef button_h
#define button_h

#include <wx/wx.h>

class Button : public wxFrame
{
public:
    Button(const wxString& title);
    
    void OnQuit(wxCommandEvent & event);
};


#endif /* button_h */
