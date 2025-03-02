#include "engine.h"
#include <btBulletDynamicsCommon.h>
#include "../utils/debug_utils.h"
#include <GL/gl.h>  // Funções básicas do OpenGL
#include <GL/glu.h> // Funções utilitárias como gluPerspective e gluLookAt
#include <iostream>

#include "src/input/glfw_input.h"


namespace ramengine {
	Engine::Engine(std::unique_ptr<Window> window) : window_(std::move(window)) {
		if (!window_->initialize(1920, 1080, "RamEngine")) {
			throw std::runtime_error("Failed to initialize window");
		}
		physicsWorld_.initialize();
		input_ = std::make_unique<GlfwInput>(window_->getGLFWwindow());
	}

	void Engine::run() {
		float deltaTime = 1.0f / 60.0f;

		// static floor
		btTransform groundPlaneTransform;
		groundPlaneTransform.setIdentity();
		groundPlaneTransform.setOrigin(btVector3(0, -2, 0)); // Chão a Y = -2
		btStaticPlaneShape* groundPlaneShape = new btStaticPlaneShape(btVector3(0, 1, 0), 0); // Plana no eixo Y
		btDefaultMotionState* groundMotionState = new btDefaultMotionState(groundPlaneTransform);
		btRigidBody::btRigidBodyConstructionInfo groundInfo(0.0f, groundMotionState, groundPlaneShape, btVector3(0, 0, 0));
		btRigidBody* groundBody = new btRigidBody(groundInfo);
		groundBody->setCollisionFlags(groundBody->getCollisionFlags() | btCollisionObject::CF_STATIC_OBJECT);

		// dynamic cube
		btTransform cube_transform;
		cube_transform.setIdentity();
		cube_transform.setOrigin(btVector3(20, 20, 0));
		auto collision_shape = new btBoxShape(btVector3(btScalar(2.), btScalar(2.), btScalar(2.)));
		btVector3 localInertia(0, 0, 0);
		collision_shape->calculateLocalInertia(10.0f, localInertia);
		auto *myMotionState = new btDefaultMotionState(cube_transform);
		btRigidBody::btRigidBodyConstructionInfo cInfo(10.0f, myMotionState, collision_shape, localInertia);
		btRigidBody *rigid_body = new btRigidBody(cInfo);


		physicsWorld_.addRigidBody(groundBody);
		physicsWorld_.addRigidBody(rigid_body);

		// Configurações iniciais do OpenGL
		glEnable(GL_DEPTH_TEST); // Ativa teste de profundidade
		SetupProjection();
		setupView();

		while (window_->isOpen()) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa a tela
			physicsWorld_.update(deltaTime);
			std::cout << "Atualizando física com deltaTime: " << deltaTime << std::endl;

			camera_.update(*input_, deltaTime); // Atualiza a câmera
			camera_.apply(); // Aplica a transformação da câmera

			DebugUtils::drawFilledCube(collision_shape, rigid_body->getWorldTransform());
			DebugUtils::drawFilledPlane(groundPlaneShape, groundBody->getWorldTransform());

			auto position = rigid_body->getWorldTransform().getOrigin();
			std::cout << "X:" << position.getX() << " Y:" << position.getY() << " Z:" << position.getZ() << std::endl;

			window_->update(); // Atualiza a janela
		}
	}

	void Engine::SetupProjection() {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, 1920.0f / 1080.0f, 0.1f, 100.0f);
	}

	void Engine::setupView() {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // Vetor "up" que define o "topo" da câmera
	}
} // namespace ramengine
