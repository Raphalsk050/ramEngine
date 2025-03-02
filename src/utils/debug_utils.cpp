#include "debug_utils.h"
#include <GLFW/glfw3.h>

void DebugUtils::drawWiredCube(const btBoxShape *boxShape, const btTransform &transform) {
	// Obtém as semi-extensões do cubo (half-extents)
	btVector3 halfExtents = boxShape->getHalfExtentsWithMargin();
	glColor3f(1.0f, 0.0f, 0.0f); // Vermelho
	// Define os 8 vértices do cubo em coordenadas locais
	btVector3 vertices[8] = {
		btVector3(-halfExtents.x(), -halfExtents.y(), -halfExtents.z()),
		btVector3(halfExtents.x(), -halfExtents.y(), -halfExtents.z()),
		btVector3(halfExtents.x(), halfExtents.y(), -halfExtents.z()),
		btVector3(-halfExtents.x(), halfExtents.y(), -halfExtents.z()),
		btVector3(-halfExtents.x(), -halfExtents.y(), halfExtents.z()),
		btVector3(halfExtents.x(), -halfExtents.y(), halfExtents.z()),
		btVector3(halfExtents.x(), halfExtents.y(), halfExtents.z()),
		btVector3(-halfExtents.x(), halfExtents.y(), halfExtents.z())
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

void DebugUtils::drawFilledCube(const btBoxShape *boxShape, const btTransform &transform) {
	// Obtém as semi-extensões do cubo (half-extents)
	btVector3 halfExtents = boxShape->getHalfExtentsWithMargin();

	// Define os 8 vértices do cubo em coordenadas locais
	btVector3 vertices[8] = {
		btVector3(-halfExtents.x(), -halfExtents.y(), -halfExtents.z()), // 0: Canto inferior esquerdo traseiro
		btVector3(halfExtents.x(), -halfExtents.y(), -halfExtents.z()), // 1: Canto inferior direito traseiro
		btVector3(halfExtents.x(), halfExtents.y(), -halfExtents.z()), // 2: Canto superior direito traseiro
		btVector3(-halfExtents.x(), halfExtents.y(), -halfExtents.z()), // 3: Canto superior esquerdo traseiro
		btVector3(-halfExtents.x(), -halfExtents.y(), halfExtents.z()), // 4: Canto inferior esquerdo frontal
		btVector3(halfExtents.x(), -halfExtents.y(), halfExtents.z()), // 5: Canto inferior direito frontal
		btVector3(halfExtents.x(), halfExtents.y(), halfExtents.z()), // 6: Canto superior direito frontal
		btVector3(-halfExtents.x(), halfExtents.y(), halfExtents.z()) // 7: Canto superior esquerdo frontal
	};

	// Aplica a transformação do mundo (posição e rotação) aos vértices
	for (int i = 0; i < 8; ++i) {
		vertices[i] = transform * vertices[i];
	}

	// Define a cor (azul, por exemplo, para diferenciar do cubo vermelho e plano verde)
	glColor3f(1.0f, 0.0f, 0.0f); // vermelho

	// Desenha as 6 faces do cubo preenchidas usando GL_QUADS
	glBegin(GL_QUADS);

	// Face frontal (Z positivo)
	glVertex3f(vertices[4].x(), vertices[4].y(), vertices[4].z()); // 4
	glVertex3f(vertices[5].x(), vertices[5].y(), vertices[5].z()); // 5
	glVertex3f(vertices[6].x(), vertices[6].y(), vertices[6].z()); // 6
	glVertex3f(vertices[7].x(), vertices[7].y(), vertices[7].z()); // 7

	// Face traseira (Z negativo)
	glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z()); // 0
	glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z()); // 1
	glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z()); // 2
	glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z()); // 3

	// Face direita (X positivo)
	glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z()); // 1
	glVertex3f(vertices[5].x(), vertices[5].y(), vertices[5].z()); // 5
	glVertex3f(vertices[6].x(), vertices[6].y(), vertices[6].z()); // 6
	glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z()); // 2

	// Face esquerda (X negativo)
	glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z()); // 0
	glVertex3f(vertices[4].x(), vertices[4].y(), vertices[4].z()); // 4
	glVertex3f(vertices[7].x(), vertices[7].y(), vertices[7].z()); // 7
	glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z()); // 3

	// Face superior (Y positivo)
	glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z()); // 3
	glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z()); // 2
	glVertex3f(vertices[6].x(), vertices[6].y(), vertices[6].z()); // 6
	glVertex3f(vertices[7].x(), vertices[7].y(), vertices[7].z()); // 7

	// Face inferior (Y negativo)
	glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z()); // 0
	glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z()); // 1
	glVertex3f(vertices[5].x(), vertices[5].y(), vertices[5].z()); // 5
	glVertex3f(vertices[4].x(), vertices[4].y(), vertices[4].z()); // 4

	glEnd();
}

void DebugUtils::drawWiredSphere(const btSphereShape *sphereShape, const btTransform &transform) {
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

void DebugUtils::drawWiredPlane(const btStaticPlaneShape *planeShape, const btTransform &transform) {
	// Obtém o vetor normal e offset do plano
	btVector3 planeNormal = planeShape->getPlaneNormal();
	btScalar planeConstant = planeShape->getPlaneConstant();

	// Aplica a transformação do mundo (posição e rotação)
	btTransform worldTransform = transform;
	btVector3 planeOrigin = worldTransform.getOrigin();
	btMatrix3x3 rotation = worldTransform.getBasis();

	// Normal do plano no espaço mundial
	btVector3 worldNormal = rotation * planeNormal;

	// Encontra dois vetores ortogonais ao normal para criar o plano (base e direção)
	btVector3 right, up;
	if (fabs(worldNormal.y()) > 0.9) {
		// Se o normal é quase vertical (eixo Y)
		right = btVector3(1, 0, 0); // Usa X como base
		up = btVector3(0, 0, 1); // Usa Z como direção
	} else {
		right = btVector3(0, 1, 0); // Usa Y como base
		up = btVector3(0, 0, 1); // Usa Z como direção
	}

	// Normaliza os vetores para garantir comprimento 1
	right = right.normalize();
	up = up.normalize();

	// Define o tamanho do wireframe (ex.: 10x10 unidades para visualização)
	btScalar size = 10.0f;

	// Calcula os 4 vértices do quadrado no plano
	btVector3 vertices[4];
	vertices[0] = planeOrigin + (right * (-size) + up * (-size)); // Canto inferior esquerdo
	vertices[1] = planeOrigin + (right * size + up * (-size)); // Canto inferior direito
	vertices[2] = planeOrigin + (right * size + up * size); // Canto superior direito
	vertices[3] = planeOrigin + (right * (-size) + up * size); // Canto superior esquerdo

	// Define a cor (verde, por exemplo, para diferenciar do cubo)
	glColor3f(0.0f, 1.0f, 0.0f);

	// Desenha o quadrado como linhas (wireframe)
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 4; ++i) {
		glVertex3f(vertices[i].x(), vertices[i].y(), vertices[i].z());
	}
	glEnd();
}

void DebugUtils::drawFilledPlane(const btStaticPlaneShape *planeShape, const btTransform &transform) {
	// Obtém o vetor normal e offset do plano
	btVector3 planeNormal = planeShape->getPlaneNormal();
	btScalar planeConstant = planeShape->getPlaneConstant();

	// Aplica a transformação do mundo (posição e rotação)
	btTransform worldTransform = transform;
	btVector3 planeOrigin = worldTransform.getOrigin();
	btMatrix3x3 rotation = worldTransform.getBasis();

	// Normal do plano no espaço mundial
	btVector3 worldNormal = rotation * planeNormal;

	// Encontra dois vetores ortogonais ao normal para criar o plano (base e direção)
	btVector3 right, up;
	if (fabs(worldNormal.y()) > 0.9) {
		// Se o normal é quase vertical (eixo Y)
		right = btVector3(1, 0, 0); // Usa X como base
		up = btVector3(0, 0, 1); // Usa Z como direção
	} else {
		right = btVector3(0, 1, 0); // Usa Y como base
		up = btVector3(0, 0, 1); // Usa Z como direção
	}

	// Normaliza os vetores para garantir comprimento 1
	right = right.normalize();
	up = up.normalize();

	// Define o tamanho do plano preenchido (ex.: 10x10 unidades para visualização)
	btScalar size = 200.0;

	// Calcula os 4 vértices do quadrado no plano
	btVector3 vertices[4];
	vertices[0] = planeOrigin + (right * (-size) + up * (-size)); // Canto inferior esquerdo
	vertices[1] = planeOrigin + (right * size + up * (-size)); // Canto inferior direito
	vertices[2] = planeOrigin + (right * size + up * size); // Canto superior direito
	vertices[3] = planeOrigin + (right * (-size) + up * size); // Canto superior esquerdo

	// Define a cor (verde, por exemplo, para diferenciar do cubo)
	glColor3f(0.0f, 1.0f, 0.0f);

	// Desenha o quadrado preenchido usando GL_QUADS
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; ++i) {
		glVertex3f(vertices[i].x(), vertices[i].y(), vertices[i].z());
	}
	glEnd();
}
