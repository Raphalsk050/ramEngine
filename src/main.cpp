#include "engine/engine.h"
#include "window/glfw_window.h"
#include <memory>
#include <ostream>
#include <iostream>

int main() {
    try {
        auto window = std::make_unique<ramengine::GlfwWindow>();
        ramengine::Engine engine(std::move(window));
        engine.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}