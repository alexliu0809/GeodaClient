//
//  gotoclass.h
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef gotoclass_h
#define gotoclass_h

#include <wx/listctrl.h>
#include <wx/dirctrl.h>
#include <wx/dnd.h>
#include <wx/wx.h>
#include <wx/window.h>


class GotoClass : public wxFrame
{
public:
    GotoClass(const wxString& title);
    // OnSelect(wxCommandEvent& event);
    void OnDragInit(wxListEvent& event);
    void BtnRunClicked(wxCommandEvent & event);
    void ListBoxClicked(wxCommandEvent &event);
    
    wxPanel *panel; //tp level panel
    
    wxListBox *lb_Y;
    wxListBox *lb_YE;
    wxListBox *lb_Ins;
    wxListBox *lb_R;
    wxListBox *lb_X;
    wxListCtrl *lb_var;

    
};



class MyTargetListBox : public wxTextDropTarget
{
    public:
        MyTargetListBox(wxListBox *owner);
        virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& data);
    
        wxListBox *m_owner;
};

#endif /* gotoclass_h */
