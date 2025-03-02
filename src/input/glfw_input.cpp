#include "glfw_input.h"
#include <stdexcept>

namespace ramengine {

	GlfwInput::GlfwInput(GLFWwindow* window) : window_(window) {
		if (!window) {
			throw std::runtime_error("GLFW window is null");
		}
		glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  // Esconde o cursor e captura o movimento
		glfwGetCursorPos(window_, &lastX_, &lastY_);  // Inicializa a posição inicial
	}

	bool GlfwInput::isKeyPressed(int key) const {
		return glfwGetKey(window_, key) == GLFW_PRESS;
	}

	bool GlfwInput::isMouseButtonPressed(int button) const {
		return glfwGetMouseButton(window_, button) == GLFW_PRESS;
	}

	void GlfwInput::getMousePosition(double &x, double &y) const {
		glfwGetCursorPos(window_, &x, &y);
	}

	void GlfwInput::getMouseDelta(double &dx, double &dy) const {
		double currentX, currentY;

		glfwGetCursorPos(window_, &currentX, &currentY);

		dx = currentX - lastX_;
		dy = lastY_ - currentY;
		lastX_ = currentX;  // Atualiza a posição anterior
		lastY_ = currentY;
	}

}  // namespace ramengine