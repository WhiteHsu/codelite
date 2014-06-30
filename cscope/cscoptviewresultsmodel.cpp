//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 The CodeLite Team
// file name            : cscoptviewresultsmodel.cpp
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

#include "cscoptviewresultsmodel.h"
#include <wx/dvrenderers.h>
#include <wx/variant.h>

//////////////////////////////////////////
// Implementation
//////////////////////////////////////////

// -------------------------------------------------
// Help method
// -------------------------------------------------
wxVariant CScoptViewResultsModel::CreateIconTextVariant(const wxString &text, const wxBitmap& bmp)
{
    wxIcon icn;
    icn.CopyFromBitmap( bmp);
    wxDataViewIconText ict(text, icn);
    wxVariant v;
    v << ict;
    return v;
}

// -------------------------------------------------
// The model class
// -------------------------------------------------

CScoptViewResultsModel::CScoptViewResultsModel()
    : m_colCount(0)
{
}

CScoptViewResultsModel::~CScoptViewResultsModel()
{
    for(size_t i=0; i<m_data.size(); ++i) {
        delete m_data.at(i);
    }
    m_data.clear();
}

unsigned int CScoptViewResultsModel::GetChildren(const wxDataViewItem& item, wxDataViewItemArray& children) const
{
    if(item.GetID() == NULL) {
        // Root
        for(size_t i=0; i<m_data.size(); ++i) {
            children.Add( wxDataViewItem( m_data.at(i) ) );
        }
        return children.size();
    }

    children.Clear();
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.m_pItem);
    if ( node ) {
        for(size_t i=0; i<node->GetChildren().size(); ++i) {
            children.Add( wxDataViewItem( node->GetChildren().at(i) ) );
        }
    }
    return children.GetCount();
}

unsigned int CScoptViewResultsModel::GetColumnCount() const
{
    return m_colCount;
}

wxString CScoptViewResultsModel::GetColumnType(unsigned int col) const
{
    if ( !m_data.empty() && m_data.at(0)->GetData().size() > col ) {
        return m_data.at(0)->GetData().at(col).GetType();
    }
    return "string";
}

wxDataViewItem CScoptViewResultsModel::GetParent(const wxDataViewItem& item) const
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.m_pItem);
    if ( node ) {
        return wxDataViewItem(node->GetParent());
    }
    return wxDataViewItem(NULL);
}

bool CScoptViewResultsModel::IsContainer(const wxDataViewItem& item) const
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.m_pItem);
    if ( node ) {
        return node->IsContainer();
    }
    return false;
}

void CScoptViewResultsModel::GetValue(wxVariant& variant, const wxDataViewItem& item, unsigned int col) const
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.m_pItem);
    if ( node && node->GetData().size() > col ) {
        variant = node->GetData().at(col);
    }
}
wxDataViewItem CScoptViewResultsModel::DoAppendItem(const wxDataViewItem& parent, const wxVector<wxVariant>& data, bool isContainer, wxClientData *clientData)
{
    CScoptViewResultsModel_Item* parentNode = reinterpret_cast<CScoptViewResultsModel_Item*>(parent.m_pItem);
    DoChangeItemType(parent, true);
    
    CScoptViewResultsModel_Item* child = new CScoptViewResultsModel_Item();
    child->SetIsContainer(isContainer);
    child->SetClientObject( clientData );
    child->SetData( data );
    if ( parentNode ) {
        parentNode->AddChild( child );

    } else {
        m_data.push_back( child );
    }

    return wxDataViewItem(child);
}

wxDataViewItem CScoptViewResultsModel::DoInsertItem(const wxDataViewItem& insertBeforeMe, const wxVector<wxVariant>& data, bool isContainer, wxClientData *clientData)
{
    CScoptViewResultsModel_Item* child = new CScoptViewResultsModel_Item();
    child->SetIsContainer(isContainer);
    child->SetClientObject( clientData );
    child->SetData( data );

    // find the location where to insert the new item
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(insertBeforeMe.m_pItem);
    if ( !node )
        return wxDataViewItem();

    wxVector<CScoptViewResultsModel_Item*>::iterator where = std::find(m_data.begin(), m_data.end(), node);

    if ( where !=  m_data.end() ) {
        // top level item
        m_data.insert( where, child );

    } else {

        if ( !node->GetParent() )
            return wxDataViewItem();

        child->SetParent(node->GetParent());
        where = std::find(node->GetParent()->GetChildren().begin(), node->GetParent()->GetChildren().end(), node);
        if ( where == node->GetParent()->GetChildren().end() ) {
            node->GetParent()->GetChildren().push_back( child );

        } else {
            node->GetParent()->GetChildren().insert(where, child);

        }
    }

    return wxDataViewItem(child);
}

wxDataViewItem CScoptViewResultsModel::AppendItem(const wxDataViewItem &parent, const wxVector<wxVariant>& data, wxClientData *clientData)
{
    wxDataViewItem ch = DoAppendItem(parent, data, false, clientData);
    ItemAdded(parent, ch);
    return ch;
}

wxDataViewItemArray CScoptViewResultsModel::AppendItems(const wxDataViewItem &parent, const wxVector<wxVector<wxVariant> >& data)
{
    wxDataViewItemArray items;
    for(size_t i=0; i<data.size(); ++i) {
        items.push_back( DoAppendItem(parent, data.at(i), false, NULL) );
    }
    ItemsAdded(parent, items);
    return items;
}

bool CScoptViewResultsModel::SetValue(const wxVariant& variant, const wxDataViewItem& item, unsigned int col)
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.m_pItem);
    if ( node && node->GetData().size() > col ) {
        node->GetData().at(col) = variant;
    }
    return true;
}

void CScoptViewResultsModel::DeleteItem(const wxDataViewItem& item)
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.m_pItem);
    if ( node ) {
        
        CScoptViewResultsModel_Item* parent = node->GetParent();
        wxDataViewItem parentItem(parent);
        ItemDeleted(parentItem, item);
        
        // this will also remove it from its model parent children list
        if ( parent == NULL ) {
            // root item, remove it from the roots array
            wxVector<CScoptViewResultsModel_Item*>::iterator where = std::find(m_data.begin(), m_data.end(), node);
            if ( where != m_data.end() ) {
                m_data.erase(where);
            }
        }
        
        // If there are no more children, change the item back to 'normal'
        if ( parent && parent->GetChildren().empty() )
            DoChangeItemType(parentItem, false);
            
        delete node;
    }
    
    if ( IsEmpty() )
        Cleared();
}

void CScoptViewResultsModel::DeleteItems(const wxDataViewItem& parent, const wxDataViewItemArray& items)
{
    // sanity
    for(size_t i=0; i<items.GetCount(); ++i) {
        CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(items.Item(i).m_pItem);
        wxUnusedVar(node);
        wxASSERT(node && node->GetParent() == parent.m_pItem);
        DeleteItem(items.Item(i));
    }
}

void CScoptViewResultsModel::Clear()
{
    wxVector<CScoptViewResultsModel_Item*> roots = m_data;
    wxVector<CScoptViewResultsModel_Item*>::iterator iter = roots.begin();
    for(; iter != roots.end(); ++iter) {
        DeleteItem( wxDataViewItem(*iter) );
    }
    Cleared();
}

bool CScoptViewResultsModel::IsEmpty() const
{
    return m_data.empty();
}

wxClientData* CScoptViewResultsModel::GetClientObject(const wxDataViewItem& item) const
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.GetID());
    if ( node ) {
        return node->GetClientObject();
    }
    return NULL;
}

void CScoptViewResultsModel::SetClientObject(const wxDataViewItem& item, wxClientData *data)
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.GetID());
    if ( node ) {
        node->SetClientObject(data);
    }
}

void CScoptViewResultsModel::UpdateItem(const wxDataViewItem& item, const wxVector<wxVariant>& data)
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.GetID());
    if ( node ) {
        node->SetData( data );
        ItemChanged( item );
    }
}

wxDataViewItem CScoptViewResultsModel::InsertItem(const wxDataViewItem& insertBeforeMe, const wxVector<wxVariant>& data, wxClientData *clientData)
{
    wxDataViewItem ch = DoInsertItem(insertBeforeMe, data, false, clientData);
    if ( ch.IsOk() ) {
        CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(ch.GetID());
        ItemAdded(wxDataViewItem(node->GetParent()), ch);
    }
    return ch;
}

wxVector<wxVariant> CScoptViewResultsModel::GetItemColumnsData(const wxDataViewItem& item) const
{
    if ( !item.IsOk() )
        return wxVector<wxVariant>();

    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.GetID());
    if ( !node ) {
        return wxVector<wxVariant>();
    }
    return node->GetData();
}

bool CScoptViewResultsModel::HasChildren(const wxDataViewItem& item) const
{
    if ( !item.IsOk() )
        return false;

    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.GetID());
    if ( !node ) {
        return false;
    }
    return !node->GetChildren().empty();
}

void CScoptViewResultsModel::DoChangeItemType(const wxDataViewItem& item, bool changeToContainer)
{
    CScoptViewResultsModel_Item* node = reinterpret_cast<CScoptViewResultsModel_Item*>(item.GetID());
    if ( !node )
        return;
    
    if ( ( changeToContainer && !node->IsContainer())  || // change an item from non-container to container type
         ( !changeToContainer && node->IsContainer()) ) { // change an item from container to non-container type
#if defined(__WXGTK__) || defined(__WXMAC__)
        // change the item to container type:
        // 1st we need to delete it
        ItemDeleted(wxDataViewItem(node->GetParent()), item);
        
        // update the node type
        node->SetIsContainer(changeToContainer);
        ItemAdded(wxDataViewItem(node->GetParent()), item);
#else
        node->SetIsContainer(changeToContainer);
#endif
    }
}
