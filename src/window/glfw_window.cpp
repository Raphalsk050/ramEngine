#include "glfw_window.h"
#include <stdexcept>

namespace ramengine {

GlfwWindow::GlfwWindow() : window_(nullptr) {}

GlfwWindow::~GlfwWindow() {
    close();
}

bool GlfwWindow::initialize(int width, int height, const char* title) {
    if (!glfwInit()) {
        return false;
    }

    window_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window_) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window_);
    return true;
}

void GlfwWindow::update() {
    if (window_) {
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}

void GlfwWindow::close() {
    if (window_) {
        glfwDestroyWindow(window_);
        window_ = nullptr;
    }
    glfwTerminate();
}

bool GlfwWindow::isOpen() const {
    return window_ && !glfwWindowShouldClose(window_);
}

}  // namespace ramengine