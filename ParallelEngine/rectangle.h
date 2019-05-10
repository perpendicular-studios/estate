#ifndef RECT_H
#define RECT_H
#include "vec2.h"

template <class T>
class Rectangle {
public:
	Rectangle(Vector2<T> rectTopLeft, Vector2<T> rectTopRight, Vector2<T> rectBottomLeft, Vector2<T> rectBottomRight);
	Rectangle(Vector2<T> pos, T w, T h) : width(w), height(h), x(pos.getx()), y(pos.gety()) {}
	Rectangle(T x_d, T y_d, T w, T h) : width(w), height(h), x(x_d), y(y_d) {}
	~Rectangle();

	bool contains(const Vector2<T> & point) const;
	bool intersects(const Rectangle<T> & other) const;
private:
	T width, height;
	T x, y;
};

typedef Rectangle<int> IntRect;
typedef Rectangle<float> FloatRect;

#endif