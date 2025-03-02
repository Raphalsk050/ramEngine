#include "engine.h"
#include <btBulletDynamicsCommon.h>
#include <iostream>


namespace ramengine {


Engine::Engine(std::unique_ptr<Window> window) : window_(std::move(window)) {
    if (!window_->initialize(800, 600, "RamEngine")) {
        throw std::runtime_error("Failed to initialize window");
    }
	physicsWorld_.initialize();
}

void Engine::run() {
    std::cout << "Engine running...\n";
	float deltaTime = 1.0f / 60.0f;

    // rigidbody properties
    btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(0, 0, 0));
    btVector3 localInertia(0, 0, 0);
    btBoxShape* groundShape = new btBoxShape(btVector3(btScalar(10.), btScalar(0.1), btScalar(10.)));

    // create a new rigidbody
    btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
    btRigidBody::btRigidBodyConstructionInfo cInfo(1.0f, myMotionState, groundShape, localInertia);
    btRigidBody* rigid_body = new btRigidBody(cInfo);

	physicsWorld_.addRigidBody(rigid_body);
    while (window_->isOpen()) {
		physicsWorld_.update(deltaTime);
        std::cout << "position: " << std::to_string(rigid_body->getWorldTransform().getOrigin().getY()) << std::endl;
        window_->update();
    }
}

}  // namespace ramengine