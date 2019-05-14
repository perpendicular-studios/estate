#ifndef RECT_H
#define RECT_H
#include "vec2.h"

template <class T>
class Rectangle {
public:
	Rectangle(Vector2<T> rectTopLeft, Vector2<T> rectTopRight, Vector2<T> rectBottomLeft, Vector2<T> rectBottomRight) {
		width = rectTopRight.getx() - rectTopLeft.getx();
		height = rectBottomLeft.gety() - rectTopLeft.gety();
		x = rectTopLeft.getx();
		y = rectTopLeft.gety();
	}

	Rectangle(Vector2<T> pos, T w, T h) : width(w), height(h), x(pos.getx()), y(pos.gety()) {}
	Rectangle(T x_d, T y_d, T w, T h) : width(w), height(h), x(x_d), y(y_d) {}
	~Rectangle() {}

	bool contains(const Vector2<T> & point) const {
		T minx = x;
		T miny = y;
		T maxx = x + width;
		T maxy = y + height;
		return (

			point.x > this->x &&
			point.y > this->y &&
			point.x < (this->x + this->width) &&
			point.y < (this->y + this->height)
			
			);
	}

	bool contains(const Rectangle<T> & other) const {
		return (
			
			this->x <= other.x &&
			(this->x + this->width) >= (other.x + other.width) &&
			this->y <= other.y &&
			(this->y + this->height) >= (other.y + other.height)
			
			);
	}

	bool intersects(const Rectangle<T> & other) const {
		T l1x = x;
		T l1y = y;

		T l2x = other.x;
		T l2y = other.y;

		T r1x = x + width;
		T r1y = y + height;

		T r2x = other.x + other.width;
		T r2y = other.y + other.height;

		if (l1x > r2x || l2x > r1x) return false;
		if (l1y < r2y || l2y < r1y) return false;
		return true;
	}
private:
	T width, height;
	T x, y;
};

#endif