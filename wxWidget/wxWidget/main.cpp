//
//  main.cpp
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#include "main.h"
#include "gotoclass.h"
#include "textdrop.h"


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    GotoClass *gotoclass = new GotoClass(wxT("PySALRegression"));
    gotoclass->Show(true);

    
    return true;
    //TextDrop *td = new TextDrop(wxT("TextDrop"));
    //td->Show(true);
    
    //return true;
}
