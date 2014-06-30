//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 The CodeLite Team
// file name            : zn_config_item.cpp
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

#include "zn_config_item.h"

znConfigItem::znConfigItem()
    : clConfigItem("ZoomNavigator")
    , m_highlightColour("LIGHT GREY")
    , m_enabled(false)
    , m_zoomFactor(-10)
{
}

znConfigItem::~znConfigItem()
{
}

void znConfigItem::FromJSON(const JSONElement& json)
{
    m_highlightColour = json.namedObject("m_highlightColour").toString();
    m_enabled         = json.namedObject("m_enabled").toBool();
    m_zoomFactor      = json.namedObject("m_zoomFactor").toInt(-10);
}

JSONElement znConfigItem::ToJSON() const
{
    JSONElement element = JSONElement::createObject(GetName());
    element.addProperty("m_highlightColour", m_highlightColour);
    element.addProperty("m_enabled", m_enabled);
    element.addProperty("m_zoomFactor", m_zoomFactor);
    return element;
}
