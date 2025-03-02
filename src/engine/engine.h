#ifndef ENGINE_H
#define ENGINE_H

#include "../window/window.h"
#include "../physics/physics_world.h"
#include <memory>

namespace ramengine {

class Engine {
public:
    Engine(std::unique_ptr<Window> window);
    void run();

private:
    std::unique_ptr<Window> window_;
    PhysicsWorld physicsWorld_;
};

}  // namespace ramengine

#endif