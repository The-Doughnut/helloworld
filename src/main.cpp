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

    std::cerr << "hello\n";

    while (editor.is_active)
        ui->update();

    return 0;
}
