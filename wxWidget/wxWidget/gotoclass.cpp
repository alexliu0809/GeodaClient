//
//  gotoclass.cpp
//  wxWidget
//
//  Created by Enze on 4/9/17.
//  Copyright © 2017 alexliu. All rights reserved.
//

#include "gotoclass.h"
#include "Listbox.h"
#include "foldpanelbar.h"

GotoClass::GotoClass(const wxString& title)
: wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(600, 400))
{
    /*
    wxBoxSizer  *topSizer = new wxBoxSizer( wxVERTICAL );
    // 创建一个最小大小为 100x60的多行文本框
    topSizer->Add(
                  new wxTextCtrl( this, wxID_ANY, "My text.",
                                 wxDefaultPosition, wxSize(100,60), wxTE_MULTILINE),
                  1,         // 垂直方向可缩放,缩放因子为1
                  wxEXPAND|  // 水平方向可缩放
                  wxALL,     // 四周都由空白边框
                  10 );      // 空白边框大小为10
    wxBoxSizer *buttonSizer = new wxBoxSizer( wxHORIZONTAL );
    buttonSizer->Add(
                     new wxButton( this, wxID_OK, "OK" ),
                     1,          // 水平方向不可缩放
                     wxALL,     // 四周有空白边框:(注意默认为顶部对齐)
                     10 );      // 空白边框大小为10
    buttonSizer->Add(
                     new wxButton( this, wxID_CANCEL, "Cancel" ),
                     1,         // 水平方向不可缩放
                     wxALL,     // 四周有空白边框:(注意默认为顶部对齐)
                     10 );      // 空白边框大小为10
    topSizer->Add(
                  buttonSizer,
                  1,                // 垂直方向不可缩放
                  wxGROW ); // 无边框并且居中对齐
    SetSizer( topSizer ); // 绑定对话框和布局控件
    topSizer->Fit( this );          // 调用对话框大小
    topSizer->SetSizeHints( this ); // 设置对话框最小大小
    */
    
    
    
    wxPanel *panel = new wxPanel(this, -1); //Top Level Panel
    
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL); //Top Level Container
    
    wxBoxSizer *uppervbox = new wxBoxSizer(wxVERTICAL); //Upper Part. Spatil + 5btns
    
    wxBoxSizer *lowerhbox = new wxBoxSizer(wxHORIZONTAL); //Model Selction and below
    
    
    //The Top Menu Bar
    wxStaticText *st1 =  new wxStaticText(panel, wxID_ANY, wxT("Spatial Regression Dialog"));
    uppervbox->Add(st1,0, wxALIGN_LEFT);
    
    //Add 5 buttons
    wxBoxSizer *spatialButtonsBoxer = new wxBoxSizer(wxHORIZONTAL);
    wxButton *openModel = new wxButton(panel, wxID_ANY, wxT("OpenModel"));
    wxButton *saveModel = new wxButton(panel, wxID_ANY, wxT("Save Model"));
    wxButton *resetModel = new wxButton(panel, wxID_ANY, wxT("Reset Model"));
    wxButton *preference = new wxButton(panel, wxID_ANY, wxT("Preference"));
    wxButton *run = new wxButton(panel, wxID_ANY, wxT("Run"));
    spatialButtonsBoxer -> Add(openModel,1);
    spatialButtonsBoxer -> Add(saveModel,1);
    spatialButtonsBoxer -> Add(resetModel,1);
    spatialButtonsBoxer -> Add(preference,1);
    spatialButtonsBoxer -> Add(run,1);
    uppervbox -> Add(spatialButtonsBoxer,1,wxGROW);
    uppervbox -> AddSpacer(10);
    /**** Upperbox is set here ****/
    
    
    //Testing for folding
    
    //uppervbox -> Add(test,1,wxGROW);
    
    
    //After setting up the top menu, add it
    vbox -> Add(uppervbox, 0, wxGROW);
    
    
    /***** Set up LowerBox *****/
    wxBoxSizer *leftvbox = new wxBoxSizer(wxVERTICAL); //Model Selection and below
    wxBoxSizer *rightvbox = new wxBoxSizer(wxVERTICAL); //Var
    
    //Add Left:
    
    //Model spec
    wxStaticText *strModelSpec =  new wxStaticText(panel, wxID_ANY, wxT("Model Specifications"));
    wxFoldPanelBar *bar = new wxFoldPanelBar(panel);
    wxFoldPanel item = bar->AddFoldPanel(wxT("Y(required)"));
    bar->AddFoldPanelWindow(item, new wxTextCtrl( item.GetParent(), wxID_ANY, "My text.", wxDefaultPosition, wxSize(100,60), wxTE_MULTILINE));
    
    //test->Item(2);
    
    //add
    leftvbox ->  Add(strModelSpec,0,wxALIGN_LEFT);
    leftvbox ->  Add(bar,1,wxGROW);
    leftvbox -> AddSpacer(10);
    
    //Esimation
    wxStaticText *strEsimation =  new wxStaticText(panel, wxID_ANY, wxT("Estimation"));
    wxStaticBox* staticBox = new wxStaticBox(panel, wxID_ANY, wxT(""));
    wxStaticBoxSizer* staticSizer = new wxStaticBoxSizer(staticBox, wxVERTICAL);
    wxArrayString strings;
    strings.Add(wxT("Standard"));
    strings.Add(wxT("Spatial Lag"));
    strings.Add(wxT("Spatial Error"));
    strings.Add(wxT("Spatial Lag+Error"));
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, wxT("Model Type"), wxDefaultPosition, wxDefaultSize, strings, 1, wxRA_SPECIFY_COLS);
    
    staticSizer -> Add(radioBox, 0, wxALIGN_LEFT |wxALL, 0);
    
    //add
    leftvbox ->  Add(strEsimation,0,wxGROW); //0 means does not change space when resizeing, wxGROW Means auto sizing. Grow Enables two sides growing, but 0/1 controls the size of its parent direction
    leftvbox ->  Add(staticSizer,0);
    leftvbox -> AddSpacer(10);

    
    //Model Weights
    wxStaticBox* staticBox1 = new wxStaticBox(panel, wxID_ANY, wxT("Model Weights"));
    wxStaticBoxSizer* staticSizer1 = new wxStaticBoxSizer(staticBox1, wxVERTICAL);
    wxStaticText *strSetWeight =  new wxStaticText(panel, wxID_ANY, wxT("Setup Weights"));
    wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, wxT("select a model weights for spatial regression"), wxDefaultPosition, wxDefaultSize);
    
    staticSizer1 -> Add(checkbox,0);
    
    
    //Left Box add
    leftvbox -> Add(strSetWeight,0);
    leftvbox ->  Add(staticSizer1,0);
    checkbox->SetValue(false);
    
    //******Lower Left set here
    
    
    //Lower Left is Set, add to lower box
    lowerhbox -> Add(leftvbox,1,wxGROW | wxLeft);
    
    
    //Setting up lower right
    //Variables
    wxStaticText *strVariables =  new wxStaticText(panel, wxID_ANY, wxT("Variables"));
    wxListBox *lb_var = new wxListBox(panel, ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
    lb_var->Append( wxT("po90") );
    lb_var->Append( wxT("po80") );
    lb_var->Append( wxT("po70") );
    lb_var->Append( wxT("po60") );
    lb_var->Append( wxT("south") );
    lb_var->Append( wxT("fh90") );
    lb_var->Append( wxT("fh80") );
    lb_var->Append( wxT("fh70") );
    rightvbox -> Add(strVariables,0,wxGROW );
    rightvbox -> Add(lb_var,1,wxGROW);
    
    //Lower right is Set, add to lower right
    lowerhbox -> Add(rightvbox,0.3,wxGROW);
    
    
    //Lower Box Set Up
    vbox -> Add(lowerhbox,1,wxEXPAND); //proportion to 1 and set a wxEXPAND flag.
    
    
    //Panel Bind Top level sizer
    panel->SetSizer(vbox);
    
    
    Centre();
    
}
