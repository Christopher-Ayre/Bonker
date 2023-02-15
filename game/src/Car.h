#pragma once
#include <vector>
#include <raylib.h>
#include <ICollidable.h>

enum TravelDirection
{
	LEFT,
	RIGHT
};


class Car : public ICollidable {
public:
	Car(const int carSpeed, TravelDirection direction, const int roadLength, Vector2 position, Vector2 size);
	bool IsCollidingWith(ICollidable& otherObject) override;
	void OnCollision(ICollidable& otherObject) override;

	void Draw();
	void Tick();
private:
	const int m_carSpeed;
	const int m_roadLength;
	TravelDirection m_travelDirection;
};

