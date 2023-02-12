#include <Car.h>

Car::Car(const int carSpeed, const int roadLength, Vector2 position, Vector2 size) :
	m_carSpeed(carSpeed),
	m_resetPoint(roadLength),
	ICollidable(position, size)
{

}

bool Car::IsCollidingWith(ICollidable& otherObject) 
{
	return false;
}

void Car::OnCollision(ICollidable& otherObject)
{
	throw int(-1);
}

void Car::Draw()
{
	DrawRectangleV( m_position, m_size, WHITE);		
}

void Car::Tick()
{
	//Move the car left.
	m_position.x = m_position.x - m_carSpeed;

	//Reset if whe have driven off the edge.
	if ((m_position.x + m_size.x) <= 0)
	{
		m_position.x = m_resetPoint;
	}
}
