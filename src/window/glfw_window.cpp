#include "glfw_window.h"

#include <iostream>
#include <stdexcept>

namespace ramengine {

GlfwWindow::GlfwWindow() : window_(nullptr) {}

GlfwWindow::~GlfwWindow() {
    close();
}

    bool GlfwWindow::initialize(int width, int height, const char* title) {
    if (!glfwInit()) {
        std::cerr << "Erro ao inicializar GLFW" << std::endl;
        return false;
    }

    // Configura o OpenGL para versão 4.6 com perfil de compatibilidade
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE); // Desativa compatibilidade futura

    window_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window_) {
        std::cerr << "Erro ao criar janela GLFW" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window_);
    std::cout << "Versão do OpenGL: " << glGetString(GL_VERSION) << std::endl;

    return true;
}

void GlfwWindow::update() {
    if (window_) {
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}

GLFWwindow* GlfwWindow::getGLFWwindow()
{
	return glfwGetCurrentContext();
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