#ifndef GLFW_INPUT_H
#define GLFW_INPUT_H

#include "input.h"
#include <GLFW/glfw3.h>

namespace ramengine {

	class GlfwInput : public Input {
	public:
		GlfwInput(GLFWwindow* window);
		~GlfwInput() override = default;
		bool isKeyPressed(int key) const override;
		bool isMouseButtonPressed(int button) const override;
		void getMousePosition(double &x, double &y) const override;
		void getMouseDelta(double &dx, double &dy) const override;

	private:
		GLFWwindow* window_;
		mutable double lastX_ = 0.0;
		mutable double lastY_ = 0.0;  // Para rastrear o movimento anterior do mouse
	};

}  // namespace ramengine

#endif  // GLFW_INPUT_H