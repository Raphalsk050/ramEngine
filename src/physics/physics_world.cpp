#include "physics_world.h"

namespace ramengine {

PhysicsWorld::PhysicsWorld() {}

PhysicsWorld::~PhysicsWorld() {
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete collisionConfiguration;
    delete broadphase;
}

void PhysicsWorld::initialize() {
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    solver = new btSequentialImpulseConstraintSolver();
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -9.806, 0));  // Gravidade padrão (eixo Y negativo)
}

void PhysicsWorld::update(float deltaTime) {
    dynamicsWorld->stepSimulation(deltaTime, 10);  // Atualiza a simulação física
}

void PhysicsWorld::addRigidBody(btRigidBody* body) {
    dynamicsWorld->addRigidBody(body);  // Adiciona um corpo rígido ao mundo
}

void PhysicsWorld::removeRigidBody(btRigidBody* body) {
    dynamicsWorld->removeRigidBody(body);  // Remove um corpo rígido do mundo
}

}  // namespace ramengine