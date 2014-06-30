//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 The CodeLite Team
// file name            : editorsettingslocalbase.cpp
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: editorsettingslocalbase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "editorsettingslocalbase.h"


// Declare the bitmap loading function
extern void wxC2ED4InitBitmapResources();

static bool bBitmapLoaded = false;


LocalEditorSettingsbase::LocalEditorSettingsbase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC2ED4InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    m_staticText = new wxStaticText(this, wxID_ANY, _("Untick one or more checkboxes to set any local preferences,"), wxDefaultPosition, wxSize(-1, -1), 0);
    wxFont m_staticTextFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticTextFont.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText->SetFont(m_staticTextFont);
    
    mainSizer->Add(m_staticText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
    
    m_treebook1 = new wxTreebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    wxImageList* m_treebook1_il = new wxImageList(16, 16);
    m_treebook1->AssignImageList(m_treebook1_il);
    
    mainSizer->Add(m_treebook1, 1, wxALL|wxEXPAND, 5);
    
    m_panel2 = new wxPanel(m_treebook1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    int m_panel2ImgIndex;
    m_panel2ImgIndex = m_treebook1_il->Add(wxXmlResource::Get()->LoadBitmap(wxT("indent")));
    m_treebook1->AddPage(m_panel2, _("Indentation"), true, m_panel2ImgIndex);
    
    wxBoxSizer* boxSizer3 = new wxBoxSizer(wxVERTICAL);
    m_panel2->SetSizer(boxSizer3);
    
    wxFlexGridSizer* fgSizer31 = new wxFlexGridSizer(0, 2, 0, 20);
    fgSizer31->SetFlexibleDirection( wxBOTH );
    fgSizer31->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    fgSizer31->AddGrowableCol(1);
    
    boxSizer3->Add(fgSizer31, 1, wxALL|wxEXPAND, 5);
    
    m_indentsUsesTabsEnable = new wxCheckBox(m_panel2, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_indentsUsesTabsEnable->SetValue(true);
    
    fgSizer31->Add(m_indentsUsesTabsEnable, 0, wxALL, 5);
    
    m_indentsUsesTabs = new wxCheckBox(m_panel2, wxID_ANY, _("Use tabs in indentation"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_indentsUsesTabs->SetValue(false);
    m_indentsUsesTabs->SetToolTip(_("If clear, only spaces will be used for indentation.\nIf set, a mixture of tabs and spaces will be used."));
    
    fgSizer31->Add(m_indentsUsesTabs, 0, wxALL, 5);
    
    m_tabWidthEnable = new wxCheckBox(m_panel2, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_tabWidthEnable->SetValue(true);
    
    fgSizer31->Add(m_tabWidthEnable, 0, wxALL, 5);
    
    wxBoxSizer* bSizer7 = new wxBoxSizer(wxHORIZONTAL);
    
    fgSizer31->Add(bSizer7, 1, wxEXPAND, 5);
    
    m_staticTexttabWidth = new wxStaticText(m_panel2, wxID_ANY, _("Columns per tab character in document:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer7->Add(m_staticTexttabWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    bSizer7->Add(0, 0, 1, wxEXPAND, 5);
    
    m_tabWidth = new wxSpinCtrl(m_panel2, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize(-1, -1), wxSP_ARROW_KEYS);
    m_tabWidth->SetRange(1, 20);
    m_tabWidth->SetValue(4);
    
    bSizer7->Add(m_tabWidth, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_indentWidthEnable = new wxCheckBox(m_panel2, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_indentWidthEnable->SetValue(true);
    
    fgSizer31->Add(m_indentWidthEnable, 0, wxALL, 5);
    
    wxBoxSizer* bSizer6 = new wxBoxSizer(wxHORIZONTAL);
    
    fgSizer31->Add(bSizer6, 1, wxEXPAND, 5);
    
    m_staticTextindentWidth = new wxStaticText(m_panel2, wxID_ANY, _("Columns per indentation level:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer6->Add(m_staticTextindentWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    bSizer6->Add(0, 0, 1, wxEXPAND, 5);
    
    m_indentWidth = new wxSpinCtrl(m_panel2, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize(-1, -1), wxSP_ARROW_KEYS);
    m_indentWidth->SetRange(1, 20);
    m_indentWidth->SetValue(4);
    
    bSizer6->Add(m_indentWidth, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_panel3 = new wxPanel(m_treebook1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    int m_panel3ImgIndex;
    m_panel3ImgIndex = m_treebook1_il->Add(wxXmlResource::Get()->LoadBitmap(wxT("margins")));
    m_treebook1->AddPage(m_panel3, _("Margins"), false, m_panel3ImgIndex);
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    m_panel3->SetSizer(boxSizer2);
    
    wxFlexGridSizer* fgSizer21 = new wxFlexGridSizer(0, 2, 0, 20);
    fgSizer21->SetFlexibleDirection( wxBOTH );
    fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    fgSizer21->AddGrowableCol(1);
    
    boxSizer2->Add(fgSizer21, 1, wxALL|wxEXPAND, 5);
    
    m_displayBookmarkMarginEnable = new wxCheckBox(m_panel3, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_displayBookmarkMarginEnable->SetValue(true);
    
    fgSizer21->Add(m_displayBookmarkMarginEnable, 0, wxALL, 5);
    
    m_displayBookmarkMargin = new wxCheckBox(m_panel3, wxID_ANY, _("Display Breakpoints / Bookmarks margin"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_displayBookmarkMargin->SetValue(false);
    
    fgSizer21->Add(m_displayBookmarkMargin, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_checkBoxDisplayFoldMarginEnable = new wxCheckBox(m_panel3, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_checkBoxDisplayFoldMarginEnable->SetValue(true);
    
    fgSizer21->Add(m_checkBoxDisplayFoldMarginEnable, 0, wxALL, 5);
    
    m_checkBoxDisplayFoldMargin = new wxCheckBox(m_panel3, wxID_ANY, _("Display Folding margin"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxDisplayFoldMargin->SetValue(false);
    m_checkBoxDisplayFoldMargin->SetToolTip(_("Display the margin that lets you 'fold' individual functions, or sections of functions, to hide their contents"));
    
    fgSizer21->Add(m_checkBoxDisplayFoldMargin, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_checkBoxHideChangeMarkerMarginEnable = new wxCheckBox(m_panel3, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_checkBoxHideChangeMarkerMarginEnable->SetValue(true);
    
    fgSizer21->Add(m_checkBoxHideChangeMarkerMarginEnable, 0, wxALL, 5);
    
    m_checkBoxHideChangeMarkerMargin = new wxCheckBox(m_panel3, wxID_ANY, _("Hide change marker margin"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxHideChangeMarkerMargin->SetValue(false);
    m_checkBoxHideChangeMarkerMargin->SetToolTip(_("Display the margin in which a coloured line marks any altered line"));
    
    fgSizer21->Add(m_checkBoxHideChangeMarkerMargin, 0, wxALL, 5);
    
    m_displayLineNumbersEnable = new wxCheckBox(m_panel3, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_displayLineNumbersEnable->SetValue(true);
    
    fgSizer21->Add(m_displayLineNumbersEnable, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_displayLineNumbers = new wxCheckBox(m_panel3, wxID_ANY, _("Display line numbers"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_displayLineNumbers->SetValue(false);
    m_displayLineNumbers->SetToolTip(_("Display line numbers margin"));
    
    fgSizer21->Add(m_displayLineNumbers, 0, wxALL, 5);
    
    m_panel4 = new wxPanel(m_treebook1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    int m_panel4ImgIndex;
    m_panel4ImgIndex = m_treebook1_il->Add(wxXmlResource::Get()->LoadBitmap(wxT("misc")));
    m_treebook1->AddPage(m_panel4, _("Misc"), false, m_panel4ImgIndex);
    
    wxBoxSizer* boxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_panel4->SetSizer(boxSizer5);
    
    wxFlexGridSizer* fgSizer2 = new wxFlexGridSizer(0, 2, 0, 20);
    fgSizer2->SetFlexibleDirection( wxBOTH );
    fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    fgSizer2->AddGrowableCol(1);
    
    boxSizer5->Add(fgSizer2, 0, wxALL|wxALIGN_LEFT, 5);
    
    m_showIndentationGuideLinesEnable = new wxCheckBox(m_panel4, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_showIndentationGuideLinesEnable->SetValue(true);
    
    fgSizer2->Add(m_showIndentationGuideLinesEnable, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_showIndentationGuideLines = new wxCheckBox(m_panel4, wxID_ANY, _("Show indentation guidelines"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_showIndentationGuideLines->SetValue(false);
    m_showIndentationGuideLines->SetToolTip(_("Display horizontal guides for matching braces \"{\""));
    
    fgSizer2->Add(m_showIndentationGuideLines, 0, wxALL, 5);
    
    m_highlightCaretLineEnable = new wxCheckBox(m_panel4, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_highlightCaretLineEnable->SetValue(true);
    
    fgSizer2->Add(m_highlightCaretLineEnable, 0, wxALL, 5);
    
    m_highlightCaretLine = new wxCheckBox(m_panel4, wxID_ANY, _("Highlight caret line"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_highlightCaretLine->SetValue(false);
    m_highlightCaretLine->SetToolTip(_("Set a different background colour for the line containing the caret"));
    
    fgSizer2->Add(m_highlightCaretLine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_checkBoxTrimLineEnable = new wxCheckBox(m_panel4, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_checkBoxTrimLineEnable->SetValue(true);
    
    fgSizer2->Add(m_checkBoxTrimLineEnable, 0, wxALL, 5);
    
    m_checkBoxTrimLine = new wxCheckBox(m_panel4, wxID_ANY, _("When saving files, trim empty lines"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxTrimLine->SetValue(false);
    
    fgSizer2->Add(m_checkBoxTrimLine, 0, wxALL, 5);
    
    m_checkBoxAppendLFEnable = new wxCheckBox(m_panel4, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_checkBoxAppendLFEnable->SetValue(true);
    
    fgSizer2->Add(m_checkBoxAppendLFEnable, 0, wxALL, 5);
    
    m_checkBoxAppendLF = new wxCheckBox(m_panel4, wxID_ANY, _("If missing, append EOL at end of file"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxAppendLF->SetValue(false);
    m_checkBoxAppendLF->SetToolTip(_("Make sure the file finishes with an end-of-line"));
    
    fgSizer2->Add(m_checkBoxAppendLF, 0, wxALL, 5);
    
    wxFlexGridSizer* flexGridSizer15 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer15->SetFlexibleDirection( wxBOTH );
    flexGridSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer15->AddGrowableCol(2);
    
    boxSizer5->Add(flexGridSizer15, 1, wxALL|wxEXPAND|wxALIGN_LEFT, 5);
    
    m_whitespaceStyleEnable = new wxCheckBox(m_panel4, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_whitespaceStyleEnable->SetValue(true);
    
    flexGridSizer15->Add(m_whitespaceStyleEnable, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticTextwhitespaceStyle = new wxStaticText(m_panel4, wxID_ANY, _("Whitespace visibility:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    flexGridSizer15->Add(m_staticTextwhitespaceStyle, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxArrayString m_whitespaceStyleArr;
    m_whitespaceStyle = new wxChoice(m_panel4, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), m_whitespaceStyleArr, 0);
    
    flexGridSizer15->Add(m_whitespaceStyle, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_choiceEOLEnable = new wxCheckBox(m_panel4, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_choiceEOLEnable->SetValue(true);
    
    flexGridSizer15->Add(m_choiceEOLEnable, 0, wxALL, 5);
    
    m_EOLstatic = new wxStaticText(m_panel4, wxID_ANY, _("EOL Mode:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    flexGridSizer15->Add(m_EOLstatic, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxArrayString m_choiceEOLArr;
    m_choiceEOL = new wxChoice(m_panel4, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), m_choiceEOLArr, 0);
    m_choiceEOL->SetToolTip(_("Set the editor's EOL mode (End Of Line). When set to 'Default' CodeLite will set the EOL according to the hosting OS"));
    
    flexGridSizer15->Add(m_choiceEOL, 0, wxALL|wxEXPAND, 5);
    
    m_fileEncodingEnable = new wxCheckBox(m_panel4, wxID_ANY, _("Use global setting"), wxDefaultPosition, wxSize(-1, -1), wxALIGN_RIGHT);
    m_fileEncodingEnable->SetValue(true);
    
    flexGridSizer15->Add(m_fileEncodingEnable, 0, wxALL, 5);
    
    m_staticTextfileEncoding = new wxStaticText(m_panel4, wxID_ANY, _("File font encoding"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    flexGridSizer15->Add(m_staticTextfileEncoding, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    wxArrayString m_fileEncodingArr;
    m_fileEncoding = new wxChoice(m_panel4, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), m_fileEncodingArr, 0);
    
    flexGridSizer15->Add(m_fileEncoding, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* bSizer4 = new wxBoxSizer(wxHORIZONTAL);
    
    mainSizer->Add(bSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_stdBtnSizer17 = new wxStdDialogButtonSizer();
    
    bSizer4->Add(m_stdBtnSizer17, 0, wxALL, 5);
    
    m_button19 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button19->SetDefault();
    m_stdBtnSizer17->AddButton(m_button19);
    
    m_button21 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer17->AddButton(m_button21);
    m_stdBtnSizer17->Realize();
    
    m_treebook1->ExpandNode( 0, true );
    m_treebook1->ExpandNode( 1, true );
    m_treebook1->ExpandNode( 2, true );
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre();
    // Connect events
    m_indentsUsesTabsEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::indentsUsesTabsUpdateUI), NULL, this);
    m_tabWidthEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::tabWidthUpdateUI), NULL, this);
    m_indentWidthEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::indentWidthUpdateUI), NULL, this);
    m_displayBookmarkMarginEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::displayBookmarkMarginUpdateUI), NULL, this);
    m_checkBoxDisplayFoldMarginEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxDisplayFoldMarginUpdateUI), NULL, this);
    m_checkBoxHideChangeMarkerMarginEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxHideChangeMarkerMarginUpdateUI), NULL, this);
    m_displayLineNumbersEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::displayLineNumbersUpdateUI), NULL, this);
    m_showIndentationGuideLinesEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::showIndentationGuideLinesUpdateUI), NULL, this);
    m_highlightCaretLineEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::highlightCaretLineUpdateUI), NULL, this);
    m_checkBoxTrimLineEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxTrimLineUpdateUI), NULL, this);
    m_checkBoxAppendLFEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxAppendLFUpdateUI), NULL, this);
    m_whitespaceStyleEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::whitespaceStyleUpdateUI), NULL, this);
    m_choiceEOLEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::choiceEOLUpdateUI), NULL, this);
    m_fileEncodingEnable->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::fileEncodingUpdateUI), NULL, this);
    m_button19->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LocalEditorSettingsbase::OnOK), NULL, this);
    
}

LocalEditorSettingsbase::~LocalEditorSettingsbase()
{
    m_indentsUsesTabsEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::indentsUsesTabsUpdateUI), NULL, this);
    m_tabWidthEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::tabWidthUpdateUI), NULL, this);
    m_indentWidthEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::indentWidthUpdateUI), NULL, this);
    m_displayBookmarkMarginEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::displayBookmarkMarginUpdateUI), NULL, this);
    m_checkBoxDisplayFoldMarginEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxDisplayFoldMarginUpdateUI), NULL, this);
    m_checkBoxHideChangeMarkerMarginEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxHideChangeMarkerMarginUpdateUI), NULL, this);
    m_displayLineNumbersEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::displayLineNumbersUpdateUI), NULL, this);
    m_showIndentationGuideLinesEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::showIndentationGuideLinesUpdateUI), NULL, this);
    m_highlightCaretLineEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::highlightCaretLineUpdateUI), NULL, this);
    m_checkBoxTrimLineEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxTrimLineUpdateUI), NULL, this);
    m_checkBoxAppendLFEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::checkBoxAppendLFUpdateUI), NULL, this);
    m_whitespaceStyleEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::whitespaceStyleUpdateUI), NULL, this);
    m_choiceEOLEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::choiceEOLUpdateUI), NULL, this);
    m_fileEncodingEnable->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LocalEditorSettingsbase::fileEncodingUpdateUI), NULL, this);
    m_button19->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LocalEditorSettingsbase::OnOK), NULL, this);
    
}
