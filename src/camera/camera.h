#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include <GLFW/glfw3.h>

#include "../input/input.h"
#include <GL/glu.h>
#include <btBulletDynamicsCommon.h>


namespace ramengine {
	struct CameraLimits {
		static constexpr float YAW_MIN = -360.0f; // Limite mínimo para yaw (pode ser ilimitado)
		static constexpr float YAW_MAX = 360.0f; // Limite máximo para yaw (pode ser ilimitado)
		static constexpr float PITCH_MIN = -89.0f; // Limite mínimo para pitch
		static constexpr float PITCH_MAX = 89.0f; // Limite máximo para pitch
	};

	class Camera {
	public:
		Camera();

		void update(const Input &input, float deltaTime); // Atualiza a câmera com base nos inputs
		void apply() const; // Aplica a transformação da câmera ao OpenGL

	private:
		btVector3 position_; // Posição da câmera
		btQuaternion rotation_; // Rotação da câmera (como quaternion)
		double yaw_ = -90.0f; // Ângulo horizontal (yaw)
		double pitch_ = 0.0f; // Ângulo vertical (pitch)
		float movementSpeed_ = 5.0f; // Velocidade de movimento
		float mouseSensitivity_ = 0.5f; // Sensibilidade do mouse

		void updateRotation(double dx, double dy);

		void updatePosition(const Input &input, float deltaTime);
	};
} // namespace ramengine

#endif  // CAMERA_H
