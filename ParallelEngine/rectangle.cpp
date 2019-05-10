#include "rectangle.h"

template <class T>
Rectangle<T>::Rectangle(Vector2<T> rectTopLeft, Vector2<T> rectTopRight, Vector2<T> rectBottomLeft, Vector2<T> rectBottomRight) {
	width = rectTopRight.getx() - rectTopLeft.getx();
	height = rectBottomLeft.gety() - rectTopLeft.gety();
	x = rectTopLeft.getx();
	y = rectTopLeft.gety();
}

template <class T>
Rectangle<T>::~Rectangle() {}

template <class T>
bool Rectangle<T>::contains(const Vector2<T> & point) const {
	T minx = x;
	T miny = y;
	T maxx = x + width;
	T maxy = y + height;
	return (point.getx() > minx && point.gety() > miny
		&& point.getx() < maxx && point.gety() < maxy);
}

template <class T>
bool Rectangle<T>::intersects(const Rectangle<T> & other) const {
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