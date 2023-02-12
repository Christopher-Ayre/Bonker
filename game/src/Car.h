#pragma once
#include <vector>
#include <raylib.h>
#include <ICollidable.h>


class Car : public ICollidable{
public:
	Car(const int carSpeed, const int roadLength, Vector2 position, Vector2 size);
	bool IsCollidingWith(ICollidable& otherObject) override;
	void OnCollision(ICollidable& otherObject) override;

	void Draw();
	void Tick();
private:
	const int m_carSpeed;
	const int m_resetPoint;
};
