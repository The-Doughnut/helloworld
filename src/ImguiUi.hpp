#ifndef _IMGUI_UI_HPP
#define _IMGUI_UI_HPP

#include <SDL.h>

#include "Ui.hpp"
#include "Editor.hpp"

struct ImguiUi : Ui {
    Editor& m_editor;
    SDL_GLContext m_gl_context;
    SDL_Window* m_window;

    ImguiUi(Editor& e);
    virtual ~ImguiUi();

    virtual void update();
};

#endif
