//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 The CodeLite Team
// file name            : openwindowspanelbase.cpp
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
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "openwindowspanelbase.h"


// Declare the bitmap loading function
extern void wxCrafterKq0OgDInitBitmapResources();

static bool bBitmapLoaded = false;


OpenWindowsPanelBase::OpenWindowsPanelBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterKq0OgDInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    m_toolbarTabs = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTB_FLAT);
    m_toolbarTabs->SetToolBitmapSize(wxSize(16,16));
    
    mainSizer->Add(m_toolbarTabs, 0, wxEXPAND, 0);
    
    m_toolbarTabs->AddTool(XRCID("TabsSortTool"), wxT(""), wxXmlResource::Get()->LoadBitmap(wxT("sort")), wxNullBitmap, wxITEM_CHECK, _("If checked, sort alphabetically. Otherwise display in the same order as the editors."), wxT(""), NULL);
    m_toolbarTabs->Realize();
    
    wxArrayString m_fileListArr;
    m_fileList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), m_fileListArr, wxLB_EXTENDED|wxWANTS_CHARS);
    
    mainSizer->Add(m_fileList, 1, wxALL|wxEXPAND, 0);
    
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    this->Connect(XRCID("TabsSortTool"), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(OpenWindowsPanelBase::OnSortItems), NULL, this);
    this->Connect(XRCID("TabsSortTool"), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(OpenWindowsPanelBase::OnSortItemsUpdateUI), NULL, this);
    m_fileList->Connect(wxEVT_CHAR, wxKeyEventHandler(OpenWindowsPanelBase::OnChar), NULL, this);
    m_fileList->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(OpenWindowsPanelBase::OnKeyDown), NULL, this);
    m_fileList->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(OpenWindowsPanelBase::OnItemSelected), NULL, this);
    m_fileList->Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(OpenWindowsPanelBase::OnItemDClicked), NULL, this);
    m_fileList->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(OpenWindowsPanelBase::OnRightDown), NULL, this);
    
}

OpenWindowsPanelBase::~OpenWindowsPanelBase()
{
    this->Disconnect(XRCID("TabsSortTool"), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(OpenWindowsPanelBase::OnSortItems), NULL, this);
    this->Disconnect(XRCID("TabsSortTool"), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(OpenWindowsPanelBase::OnSortItemsUpdateUI), NULL, this);
    m_fileList->Disconnect(wxEVT_CHAR, wxKeyEventHandler(OpenWindowsPanelBase::OnChar), NULL, this);
    m_fileList->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(OpenWindowsPanelBase::OnKeyDown), NULL, this);
    m_fileList->Disconnect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(OpenWindowsPanelBase::OnItemSelected), NULL, this);
    m_fileList->Disconnect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(OpenWindowsPanelBase::OnItemDClicked), NULL, this);
    m_fileList->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(OpenWindowsPanelBase::OnRightDown), NULL, this);
    
}
