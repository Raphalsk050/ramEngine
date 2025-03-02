#include "camera.h"
#include <cmath>
#include <iostream>
#include <ostream>

namespace ramengine {

Camera::Camera() : position_(btVector3(0.0f, 5.0f, 5.0f)) {
    // Posição inicial: acima e atrás do chão
}

void Camera::update(const Input& input, float deltaTime) {
    double dx = 0.0, dy = 0.0;
    input.getMouseDelta(dx, dy);  // Obtém o delta do mouse


    updateRotation(dx, dy);  // Atualiza a rotação com base no mouse
    updatePosition(input, deltaTime);  // Atualiza a posição (opcional, com teclas)
}

void Camera::apply() const {
    btMatrix3x3 rotMatrix(rotation_);
    btVector3 forward = -btVector3(rotMatrix[0][2], rotMatrix[1][2], rotMatrix[2][2]);
    btVector3 up = btVector3(rotMatrix[0][1], rotMatrix[1][1], rotMatrix[2][1]);
    btVector3 lookAt = position_ + forward;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //std::cout << "Camera pos: " << position_.x() << "," << position_.y() << "," << position_.z() << std::endl;

    gluLookAt(position_.x(), position_.y(), position_.z(),
              lookAt.x(), lookAt.y(), lookAt.z(),
              up.x(), up.y(), up.z());
}

void Camera::updateRotation(double dx, double dy) {
    yaw_ += dx * mouseSensitivity_;
    pitch_ += dy * mouseSensitivity_;

    //std::cout << "yaw_: " << yaw_ << ", pitch_: " << pitch_ << std::endl;


    rotation_ = btQuaternion(btVector3(0, 1, 0), yaw_ * 3.14159f / 180.0f) *
                btQuaternion(btVector3(1, 0, 0), pitch_ * 3.14159f / 180.0f);
}

void Camera::updatePosition(const Input& input, float deltaTime) {
    btMatrix3x3 rotMatrix(rotation_);
    btVector3 forward = -btVector3(rotMatrix[0][2], rotMatrix[1][2], rotMatrix[2][2]);
    btVector3 right = btVector3(rotMatrix[0][0], rotMatrix[1][0], rotMatrix[2][0]);

    if (input.isKeyPressed(GLFW_KEY_W)) {
        position_ += forward * movementSpeed_ * deltaTime;
    }
    if (input.isKeyPressed(GLFW_KEY_S)) {
        position_ -= forward * movementSpeed_ * deltaTime;
    }
    if (input.isKeyPressed(GLFW_KEY_A)) {
        position_ -= right * movementSpeed_ * deltaTime;
    }
    if (input.isKeyPressed(GLFW_KEY_D)) {
        position_ += right * movementSpeed_ * deltaTime;
    }
}

}  // namespace ramengine