#pragma once
class ICollidable {
public:
	ICollidable(Vector2 position, Vector2 size) :m_position(position), m_size(size) {};
	virtual bool IsCollidingWith(ICollidable& otherObject) = 0;
	virtual void OnCollision(ICollidable& otherObject) = 0;
protected:
	Vector2 m_position;
	Vector2 m_size;
};
