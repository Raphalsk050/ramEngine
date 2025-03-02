#ifndef WINDOW_H
#define WINDOW_H

namespace ramengine {

class Window {
public:
    virtual ~Window() = default;
    virtual bool initialize(int width, int height, const char* title) = 0;
    virtual void update() = 0;
    virtual void close() = 0;
    virtual bool isOpen() const = 0;
};

}  // namespace ramengine

#endif