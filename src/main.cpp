#include <iostream>
#include <memory>

#include "Editor.hpp"
#include "Ui.hpp"
#include "ImguiUi.hpp"

std::unique_ptr<Ui> getDesiredUI(Editor& e) {
    return std::make_unique<ImguiUi>(e);
}

int main() {
    auto editor = Editor();
    auto ui = getDesiredUI(editor);

    while (editor.is_active) {
        return 5;
    }

    return 0;
}
