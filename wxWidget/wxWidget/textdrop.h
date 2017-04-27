//
//  textdrop.h
//  wxWidget
//
//  Created by Enze on 4/25/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#ifndef textdrop_h
#define textdrop_h
#include <wx/wx.h>
#include <wx/dnd.h>
#include <wx/listctrl.h>
#include <wx/dirctrl.h>
class TextDrop : public wxFrame
{
public:
    TextDrop(const wxString& title);
    
    void OnSelect(wxCommandEvent& event);
    void OnDragInit(wxListEvent& event);
    
    wxGenericDirCtrl *m_gdir;
    wxListCtrl *m_lc1;
    wxListCtrl *m_lc2;
    
};


class MyTextDropTarget : public wxTextDropTarget
{
public:
    MyTextDropTarget(wxListCtrl *owner);
    
    virtual bool OnDropText(wxCoord x, wxCoord y,
                            const wxString& data);
    
    wxListCtrl *m_owner;
    
};
#endif /* textdrop_h */
