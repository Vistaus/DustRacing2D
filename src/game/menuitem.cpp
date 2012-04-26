// This file is part of Dust Racing (DustRAC).
// Copyright (C) 2012 Jussi Lind <jussi.lind@iki.fi>
//
// DustRAC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// DustRAC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DustRAC. If not, see <http://www.gnu.org/licenses/>.

#include "menuitem.hpp"
#include "menuitemview.hpp"
#include "menu.hpp"
#include "menumanager.hpp"

MenuItem::MenuItem(int width, int height, std::string text)
  : m_text(text)
  , m_pView(nullptr)
  , m_focused(false)
  , m_width(width)
  , m_height(height)
  , m_lMargin(1)
  , m_rMargin(1)
  , m_tMargin(1)
  , m_bMargin(1)
{
}

int MenuItem::width() const
{
    return m_width + m_lMargin + m_rMargin;
}

int MenuItem::height() const
{
    return m_height + m_tMargin + m_bMargin;
}

void MenuItem::setView(MenuItemView * menuItemView, bool takeOwnership)
{
    m_pView = menuItemView;

    if (takeOwnership)
    {
        m_pOwnedView = std::shared_ptr<MenuItemView>(menuItemView);
    }
}

MenuItemView * MenuItem::view()
{
    return m_pView;
}

void MenuItem::onLeft()
{
}

void MenuItem::onRight()
{
}

void MenuItem::onSelect()
{
}

void MenuItem::setFocused(bool focused)
{
    m_focused = focused;
}

void MenuItem::setContentsMargins(int left, int right, int top, int bottom)
{
    m_lMargin = left;
    m_rMargin = right;
    m_tMargin = top;
    m_bMargin = bottom;
}

void MenuItem::getContentsMargins(int & left, int & right, int & top, int & bottom) const
{
    left   = m_lMargin;
    right  = m_rMargin;
    top    = m_tMargin;
    bottom = m_bMargin;
}

bool MenuItem::focused() const
{
    return m_focused;
}

void MenuItem::render(int x1, int y1, int x2, int y2)
{
    if (m_pView)
    {
        m_pView->render(x1, y1, x2, y2);
    }
}

const std::string & MenuItem::text() const
{
    return m_text;
}

MenuItem::~MenuItem()
{
}
