#include <Collidable.h>

bool Collidable::IsCollidingWith(Collidable & otherObject)
{
	const float ourHalfWidth = m_size.x / 2.0f;
	const float ourHalfHeight = m_size.y / 2.0f;
	const Vector2 ourCenterPoint = Vector2{ m_position.x + ourHalfWidth, m_position.y + ourHalfHeight };

	const float theirHalfWidth = otherObject.m_size.x / 2.0f;
	const float theirHalfHeight = otherObject.m_size.y / 2.0f;
	const Vector2 theirCenterPoint = Vector2{ otherObject.m_position.x + theirHalfWidth, otherObject.m_position.y + theirHalfHeight };

	// Calculate the distance between the centers of the two rectangles along the x and y axes
	float deltaX = std::abs(ourCenterPoint.x - theirCenterPoint.x);
	float deltaY = std::abs(ourCenterPoint.y - theirCenterPoint.y);

	// Calculate the minimum distance for a collision to occur along the x and y axes
	float minDistanceX = ourHalfWidth + theirHalfWidth;
	float minDistanceY = ourHalfHeight + theirHalfHeight;

	if (deltaX < minDistanceX && deltaY < minDistanceY)
	{
		return true;
	}

	return false;
};