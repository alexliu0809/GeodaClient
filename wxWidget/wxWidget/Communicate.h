//
//  Communicate.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef Communicate_h
#define Communicate_h

#include "Panels.h"
#include <wx/wxprec.h>


class Communicate : public wxFrame
{
public:
    Communicate(const wxString& title);
    
    
    LeftPanel *m_lp;
    RightPanel *m_rp;
    wxPanel *m_parent;
    
};

#endif /* Communicate_h */
