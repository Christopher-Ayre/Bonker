#pragma once
#include <raylib.h>
#include <cmath>

class Collidable {
public:
	Collidable(Vector2 position, Vector2 size) :m_position(position), m_size(size) {};
	virtual void OnCollision(Collidable& otherObject) = 0;
	
	bool IsCollidingWith(Collidable& otherObject);

protected:
	Vector2 m_position;
	Vector2 m_size;
};
