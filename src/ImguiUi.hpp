#ifndef _IMGUI_UI_HPP
#define _IMGUI_UI_HPP

#include "Ui.hpp"
#include "Editor.hpp"

struct ImguiUi : Ui {
    Editor& m_editor;

    ImguiUi(Editor& e);
    virtual ~ImguiUi();

    virtual void render();
};

#endif
