#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H

#include "window.h"
#include <GLFW/glfw3.h>

namespace ramengine {

class GlfwWindow : public Window {
public:
    GlfwWindow();
    ~GlfwWindow() override;
    bool initialize(int width, int height, const char* title) override;
    void update() override;
    void close() override;
    bool isOpen() const override;

private:
    GLFWwindow* window_;
};

}  // namespace ramengine

#endif