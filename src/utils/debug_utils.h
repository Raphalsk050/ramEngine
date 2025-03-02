#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <btBulletDynamicsCommon.h>

class DebugUtils {
public:
    // Desenha um wired cube baseado em um btBoxShape e sua transformação
    static void drawWiredCube(const btBoxShape* boxShape, const btTransform& transform);

    // Desenha um filled cube baseado em um btBoxShape e sua transformação
    static void drawFilledCube(const btBoxShape* boxShape, const btTransform& transform);

    // Desenha uma wired sphere baseado em um btSphereShape e sua transformação
    static void drawWiredSphere(const btSphereShape* sphereShape, const btTransform& transform);

    // Desenha um wired plane baseado em um btStaticPlaneShape e sua transformação
    static void drawWiredPlane(const btStaticPlaneShape* planeShape, const btTransform& transform);

    // Desenha um plano preenchido baseado em um btStaticPlaneShape e sua transformação
    static void drawFilledPlane(const btStaticPlaneShape* planeShape, const btTransform& transform);
};

#endif // DEBUG_UTILS_H