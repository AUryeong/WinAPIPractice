#pragma once

typedef struct Vector2 {
	float x;
	float y;
	Vector2() : Vector2(0, 0) {}
	Vector2(float x, float y) : x(x), y(y) {}

	Vector2 operator+(const Vector2 other) const;
	Vector2 operator-(const Vector2 other) const;
	Vector2 operator*(const Vector2 other) const;
	Vector2 operator+=(Vector2 other);
	Vector2 operator-=(Vector2 other);
} Vector2;