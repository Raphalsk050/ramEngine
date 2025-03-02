#ifndef ENGINE_H
#define ENGINE_H

#include "../window/window.h"
#include "../physics/physics_world.h"
#include "../camera/camera.h"
#include <memory>



namespace ramengine {

class Engine {
public:
    explicit Engine(std::unique_ptr<Window> window);
    void run();

private:
    std::unique_ptr<Window> window_;
    PhysicsWorld physicsWorld_;
    void SetupProjection();
    void setupView();
    std::unique_ptr<Input> input_;  // Input para capturar eventos
    Camera camera_;
};

}  // namespace ramengine

#endif