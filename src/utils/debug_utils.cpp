#include "debug_utils.h"
#include <GLFW/glfw3.h>

void DebugUtils::drawWiredCube(const btBoxShape* boxShape, const btTransform& transform) {
    // Obtém as semi-extensões do cubo (half-extents)
    btVector3 halfExtents = boxShape->getHalfExtentsWithMargin();
    glColor3f(1.0f, 0.0f, 0.0f); // Vermelho
    // Define os 8 vértices do cubo em coordenadas locais
    btVector3 vertices[8] = {
        btVector3(-halfExtents.x(), -halfExtents.y(), -halfExtents.z()),
        btVector3( halfExtents.x(), -halfExtents.y(), -halfExtents.z()),
        btVector3( halfExtents.x(),  halfExtents.y(), -halfExtents.z()),
        btVector3(-halfExtents.x(),  halfExtents.y(), -halfExtents.z()),
        btVector3(-halfExtents.x(), -halfExtents.y(),  halfExtents.z()),
        btVector3( halfExtents.x(), -halfExtents.y(),  halfExtents.z()),
        btVector3( halfExtents.x(),  halfExtents.y(),  halfExtents.z()),
        btVector3(-halfExtents.x(),  halfExtents.y(),  halfExtents.z())
    };

    // Aplica a transformação do mundo (posição e rotação) aos vértices
    for (int i = 0; i < 8; ++i) {
        vertices[i] = transform * vertices[i];
    }

    // Desenha as 12 arestas do cubo como linhas
    glBegin(GL_LINES);
    // Face frontal
    glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z());
    glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z());
    glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z());
    glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z());
    glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z());
    glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z());
    glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z());
    glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z());
    // Face traseira
    glVertex3f(vertices[4].x(), vertices[4].y(), vertices[4].z());
    glVertex3f(vertices[5].x(), vertices[5].y(), vertices[5].z());
    glVertex3f(vertices[5].x(), vertices[5].y(), vertices[5].z());
    glVertex3f(vertices[6].x(), vertices[6].y(), vertices[6].z());
    glVertex3f(vertices[6].x(), vertices[6].y(), vertices[6].z());
    glVertex3f(vertices[7].x(), vertices[7].y(), vertices[7].z());
    glVertex3f(vertices[7].x(), vertices[7].y(), vertices[7].z());
    glVertex3f(vertices[4].x(), vertices[4].y(), vertices[4].z());
    // Conexões entre as faces
    glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z());
    glVertex3f(vertices[4].x(), vertices[4].y(), vertices[4].z());
    glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z());
    glVertex3f(vertices[5].x(), vertices[5].y(), vertices[5].z());
    glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z());
    glVertex3f(vertices[6].x(), vertices[6].y(), vertices[6].z());
    glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z());
    glVertex3f(vertices[7].x(), vertices[7].y(), vertices[7].z());
    glEnd();
}

void DebugUtils::drawWiredSphere(const btSphereShape* sphereShape, const btTransform& transform) {
    // Obtém o raio da esfera e o centro (posição no mundo)
    btScalar radius = sphereShape->getRadius();
    btVector3 center = transform.getOrigin();

    // Desenha 3 círculos nos planos XY, XZ e YZ para simular o wireframe
    const int segments = 36; // Número de segmentos para aproximar o círculo

    // Círculo no plano XY
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        btScalar angle = i * 2.0f * 3.14159f / segments;
        btScalar x = center.x() + radius * cos(angle);
        btScalar y = center.y() + radius * sin(angle);
        glVertex3f(x, y, center.z());
    }
    glEnd();

    // Círculo no plano XZ
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        btScalar angle = i * 2.0f * 3.14159f / segments;
        btScalar x = center.x() + radius * cos(angle);
        btScalar z = center.z() + radius * sin(angle);
        glVertex3f(x, center.y(), z);
    }
    glEnd();

    // Círculo no plano YZ
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        btScalar angle = i * 2.0f * 3.14159f / segments;
        btScalar y = center.y() + radius * cos(angle);
        btScalar z = center.z() + radius * sin(angle);
        glVertex3f(center.x(), y, z);
    }
    glEnd();
}