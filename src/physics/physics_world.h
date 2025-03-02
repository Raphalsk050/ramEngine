#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <btBulletDynamicsCommon.h>

namespace ramengine {

class PhysicsWorld {
public:
    PhysicsWorld();
    ~PhysicsWorld();

    void initialize();
    void update(float deltaTime);
    void addRigidBody(btRigidBody* body);
    void removeRigidBody(btRigidBody* body);

private:
    btBroadphaseInterface* broadphase;
    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
};

}  // namespace ramengine

#endif  // PHYSICS_WORLD_H