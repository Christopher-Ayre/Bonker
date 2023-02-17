#pragma once
#include <vector>
#include <raylib.h>
#include <Collidable.h>

enum TravelDirection
{
	LEFT,
	RIGHT
};


class Car : public Collidable {
public:
	Car(const int carSpeed, TravelDirection direction, const int roadLength, Vector2 position, Vector2 size);
	void OnCollision(Collidable& otherObject) override;

	void Draw();
	void Tick();
private:
	const int m_carSpeed;
	const int m_roadLength;
	TravelDirection m_travelDirection;
};

