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
		std::cout << "Engine running...\n";
		float deltaTime = 1.0f / 60.0f;

		btTransform groundTransform;
		groundTransform.setIdentity();
		groundTransform.setOrigin(btVector3(0, 0, 0));
		btVector3 localInertia(0, 0, 0);
		auto *groundShape = new btBoxShape(btVector3(btScalar(2.), btScalar(2.), btScalar(2.)));
		auto *myMotionState = new btDefaultMotionState(groundTransform);
		btRigidBody::btRigidBodyConstructionInfo cInfo(1.0f, myMotionState, groundShape, localInertia);
		btRigidBody *rigid_body = new btRigidBody(cInfo);

		// Configurações iniciais do OpenGL
		glEnable(GL_DEPTH_TEST);  // Ativa teste de profundidade
		SetupProjection();
		setupView();

		while (window_->isOpen()) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Limpa a tela

			physicsWorld_.update(deltaTime);
			camera_.update(*input_, deltaTime); // Atualiza a câmera
			camera_.apply(); // Aplica a transformação da câmera

			auto collision_shape = dynamic_cast<btBoxShape *>(rigid_body->getCollisionShape());
			DebugUtils::drawWiredCube(collision_shape, rigid_body->getWorldTransform());


			window_->update();  // Atualiza a janela
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
		gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);// Vetor "up" que define o "topo" da câmera
	}
} // namespace ramengine
