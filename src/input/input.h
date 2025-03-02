#ifndef INPUT_H
#define INPUT_H

namespace ramengine {

	class Input {
	public:
		virtual ~Input() = default;
		[[nodiscard]] virtual bool isKeyPressed(int key) const = 0;  // Verifica se uma tecla está pressionada
		[[nodiscard]] virtual bool isMouseButtonPressed(int button) const = 0;  // Verifica se um botão do mouse está pressionado
		virtual void getMousePosition(double &x, double &y) const = 0;  // Obtém a posição atual do mouse
		virtual void getMouseDelta(double &dx, double &dy) const = 0;  // Obtém o delta de movimento do mouse (rotação)
	};

}  // namespace ramengine

#endif  // INPUT_H