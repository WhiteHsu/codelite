//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: AccelTableBaseDlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "AccelTableBaseDlg.h"


// Declare the bitmap loading function
extern void wxCFD7DInitBitmapResources();

static bool bBitmapLoaded = false;


AccelTableBaseDlg::AccelTableBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCFD7DInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer1);
    
    wxBoxSizer* bSizer5 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer1->Add(bSizer5, 0, wxEXPAND, WXC_FROM_DIP(5));
    
    m_textCtrlFilter = new wxSearchCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxTE_PROCESS_ENTER);
    m_textCtrlFilter->SetToolTip(_("Search for a keyboard shortcut either by its keyboard shortcut or by its description"));
    m_textCtrlFilter->SetFocus();
    m_textCtrlFilter->ShowSearchButton(true);
    m_textCtrlFilter->ShowCancelButton(false);
    
    bSizer5->Add(m_textCtrlFilter, 1, wxALL, WXC_FROM_DIP(5));
    
    wxBoxSizer* bSizer4 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer1->Add(bSizer4, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    m_dvListCtrl = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(300,200)), wxDV_VERT_RULES|wxDV_ROW_LINES|wxDV_SINGLE);
    
    bSizer4->Add(m_dvListCtrl, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_dvListCtrl->AppendTextColumn(_("Description"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(200), wxALIGN_LEFT);
    m_dvListCtrl->AppendTextColumn(_("Keyboard Shortcut"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT);
    m_dvListCtrl->SetMinSize(wxSize(300,200));
    
    wxBoxSizer* bSizer3 = new wxBoxSizer(wxVERTICAL);
    
    bSizer4->Add(bSizer3, 0, 0, WXC_FROM_DIP(5));
    
    m_buttonEdit = new wxButton(this, wxID_ANY, _("&Edit..."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    
    bSizer3->Add(m_buttonEdit, 0, wxALL, WXC_FROM_DIP(5));
    
    m_buttonDefault = new wxButton(this, wxID_ANY, _("&Defaults"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    
    bSizer3->Add(m_buttonDefault, 0, wxALL, WXC_FROM_DIP(5));
    
    m_stdBtnSizer6 = new wxStdDialogButtonSizer();
    
    bSizer1->Add(m_stdBtnSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));
    
    m_button8 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button8->SetDefault();
    m_stdBtnSizer6->AddButton(m_button8);
    
    m_button10 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer6->AddButton(m_button10);
    m_stdBtnSizer6->Realize();
    
    SetName(wxT("AccelTableBaseDlg"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_textCtrlFilter->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AccelTableBaseDlg::OnText), NULL, this);
    m_dvListCtrl->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(AccelTableBaseDlg::OnDVItemActivated), NULL, this);
    m_buttonEdit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnEditButton), NULL, this);
    m_buttonEdit->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AccelTableBaseDlg::OnEditUI), NULL, this);
    m_buttonDefault->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonDefaults), NULL, this);
    m_button8->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonOk), NULL, this);
    
}

AccelTableBaseDlg::~AccelTableBaseDlg()
{
    m_textCtrlFilter->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AccelTableBaseDlg::OnText), NULL, this);
    m_dvListCtrl->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(AccelTableBaseDlg::OnDVItemActivated), NULL, this);
    m_buttonEdit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnEditButton), NULL, this);
    m_buttonEdit->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AccelTableBaseDlg::OnEditUI), NULL, this);
    m_buttonDefault->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonDefaults), NULL, this);
    m_button8->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonOk), NULL, this);
    
}
