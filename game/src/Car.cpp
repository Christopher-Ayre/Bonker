#include <Car.h>

Car::Car(const int carSpeed, TravelDirection travelDirection, const int roadLength, Vector2 position, Vector2 size) :
	m_carSpeed(carSpeed),
	m_travelDirection(travelDirection),
	m_roadLength(roadLength),
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
	if (m_travelDirection == LEFT)
	{
		//Move the car.
		m_position.x = m_position.x - m_carSpeed;

		//Reset if whe have driven off the edge.
		if ((m_position.x + m_size.x) <= 0)
		{
			m_position.x = static_cast<float>(m_roadLength);
		}
	}
	else if (m_travelDirection == RIGHT)
	{
		//Move the car.
		m_position.x = m_position.x + m_carSpeed;

		//Reset if driven off edge.
		if ((m_position.x - m_size.x) >= static_cast<float>(m_roadLength))
		{
			m_position.x = 0 - m_size.x;
		}
	}
}
