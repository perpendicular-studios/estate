#ifndef VEC2_H
#define VEC2_H

template <class T>
class Vector2 {
public:
	Vector2() : x(0), y(0) {}
	Vector2(T x_d, T y_d) : x(x_d), y(y_d) {}
	~Vector2() {}
	T x, y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;

#endif