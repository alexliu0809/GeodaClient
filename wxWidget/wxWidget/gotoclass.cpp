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
: wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(800, 550))
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
    
    //Model Spec Top level
    wxBoxSizer *model_top_level_sizer = new wxBoxSizer(wxHORIZONTAL);
    
    //Set up model spec left
    wxBoxSizer *model_left_sizer = new wxBoxSizer(wxVERTICAL);
    
    //Y
    wxFoldPanelBar *bar_Y = new wxFoldPanelBar(panel);
    wxFoldPanel item_Y = bar_Y->AddFoldPanel(wxT("Y(required)"));
    wxListBox *lb_Y = new wxListBox(item_Y.GetParent(), ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
    lb_Y->Append( wxT("Add Item Here") );
    bar_Y->AddFoldPanelWindow(item_Y, lb_Y);
    model_left_sizer ->  Add(bar_Y,1,wxGROW); //add to left
    
    //YE
    wxFoldPanelBar *bar_YE = new wxFoldPanelBar(panel);
    wxFoldPanel item_Ye = bar_YE->AddFoldPanel(wxT("YE"),true); //collapsed = true
    wxListBox *lb_YE = new wxListBox(item_Ye.GetParent(), ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
    lb_YE->Append( wxT("Add Item Here") );
    bar_YE->AddFoldPanelWindow(item_Ye, lb_YE);
    model_left_sizer ->  Add(bar_YE,1,wxGROW);
    
    
    
    //Intruments
    wxFoldPanelBar *bar_Ins = new wxFoldPanelBar(panel);
    wxFoldPanel item_Ins = bar_Ins->AddFoldPanel(wxT("Instruments"),true); //collapsed = true
    wxListBox *lb_Ins = new wxListBox(item_Ins.GetParent(), ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
    lb_Ins->Append( wxT("Add Item Here") );
    bar_Ins->AddFoldPanelWindow(item_Ins, lb_Ins);
    model_left_sizer ->  Add(bar_Ins,1,wxGROW);
    
    //R
    //Set up model spec right
    wxFoldPanelBar *bar_R = new wxFoldPanelBar(panel);
    wxFoldPanel item_R = bar_R->AddFoldPanel(wxT("R"),true);
    wxListBox *lb_R = new wxListBox(item_R.GetParent(), ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
    lb_R->Append( wxT("Add Item Here") );
    bar_R->AddFoldPanelWindow(item_R, lb_R);
    model_left_sizer ->  Add(bar_R,1,wxGROW);
    
    //left set up
    model_top_level_sizer -> Add(model_left_sizer,1,wxGROW);
    
    
    //Set up model spec right
    wxFoldPanelBar *bar_X = new wxFoldPanelBar(panel);
    wxFoldPanel item_X = bar_X->AddFoldPanel(wxT("X(required)"));
    wxListBox *lb_X = new wxListBox(item_X.GetParent(), ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
    lb_X->Append( wxT("Add Item Here") );
    bar_X->AddFoldPanelWindow(item_X, lb_X);
    model_top_level_sizer ->  Add(bar_X,1,wxGROW);
    
    //add model spec
    leftvbox -> Add(strModelSpec,0,wxALIGN_LEFT);
    leftvbox -> Add(model_top_level_sizer,1,wxGROW);
    leftvbox -> AddSpacer(10);
    
    //Esimation
    wxStaticText *strEsimation =  new wxStaticText(panel, wxID_ANY, wxT("Estimation"));
    //Estimation Top Level:
    //wxBoxSizer *est_top_level_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBox* est_top_level_staticBox = new wxStaticBox(panel, wxID_ANY, wxT(""));
    wxStaticBoxSizer* est_top_level_sizer = new wxStaticBoxSizer(est_top_level_staticBox, wxHORIZONTAL);
    
    //Type
    //wxStaticBox* staticBox_type = new wxStaticBox(panel, wxID_ANY, wxT(""));
    //wxStaticBoxSizer* staticSizer_type = new wxStaticBoxSizer(staticBox_type, wxVERTICAL);
    wxArrayString strings_type;
    strings_type.Add(wxT("Standard"));
    strings_type.Add(wxT("Spatial Lag"));
    strings_type.Add(wxT("Spatial Error"));
    strings_type.Add(wxT("Spatial Lag+Error"));
    wxRadioBox* radioBox_type = new wxRadioBox(panel, wxID_ANY, wxT("Model Type"), wxDefaultPosition, wxDefaultSize, strings_type, 1, wxRA_SPECIFY_COLS);
    est_top_level_sizer ->Add(radioBox_type, 0, wxALIGN_LEFT |wxALL, 0);
    //staticSizer_type -> Add(radioBox_type, 0, wxALIGN_LEFT |wxALL, 0);
    //est_top_level_sizer -> Add(staticSizer_type,1,wxGROW);
    
    //Method
    //wxStaticBox* staticBox_method = new wxStaticBox(panel, wxID_ANY, wxT(""));
    //wxStaticBoxSizer* staticSizer_method = new wxStaticBoxSizer(staticBox_method, wxVERTICAL);
    wxArrayString strings_method;
    strings_method.Add(wxT("Standard"));
    strings_method.Add(wxT("Spatial Lag"));
    strings_method.Add(wxT("Spatial Error"));
    strings_method.Add(wxT("Spatial Lag+Error"));
    wxRadioBox* radioBox_method = new wxRadioBox(panel, wxID_ANY, wxT("Method"), wxDefaultPosition, wxDefaultSize, strings_method, 1, wxRA_SPECIFY_COLS);
    est_top_level_sizer ->Add(radioBox_method, 0, wxALIGN_LEFT |wxALL, 0);
    //staticSizer_method -> Add(radioBox_method, 0, wxALIGN_LEFT |wxALL, 0);
    //est_top_level_sizer -> Add(staticSizer_method,1,wxGROW);
    
    //Errors
    //wxStaticBox* staticBox_error = new wxStaticBox(panel, wxID_ANY, wxT(""));
    //wxStaticBoxSizer* staticSizer_error = new wxStaticBoxSizer(staticBox_error, wxVERTICAL);
    /*
     wxWindow *parent, wxWindowID id, const wxString& label,
    const wxPoint& pos = wxDefaultPosition,
    const wxSize& size = wxDefaultSize, long style = 0,
    const wxValidator& validator = wxDefaultValidator,
    const wxString& name = wxCheckBoxNameStr
     */
    wxArrayString strings_error;
    strings_error.Add(wxT("White"));
    strings_error.Add(wxT("HAC"));
    strings_error.Add(wxT("KP HET"));
    wxCheckListBox *checkBox_error = new wxCheckListBox(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, strings_error, 0, wxDefaultValidator, wxT("Error"));
    est_top_level_sizer ->Add(checkBox_error, 0, wxALIGN_LEFT | wxTOP | wxLeft, 15);
    //staticSizer_error -> Add(radioBox_error, 0, wxALIGN_LEFT |wxALL, 0);
    //est_top_level_sizer -> Add(staticSizer_error,1,wxGROW);
    
    //add
    leftvbox ->  Add(strEsimation,0,wxGROW); //0 means does not change space when resizeing, wxGROW Means auto sizing. Grow Enables two sides growing, but 0/1 controls the size of its parent direction
    leftvbox ->  Add(est_top_level_sizer,0,wxGROW); //Set the space given to estimation to 0
    //leftvbox -> AddSpacer(10);

    
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
