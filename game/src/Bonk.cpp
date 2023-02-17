#include <Bonk.h>

Bonk::Bonk(Vector2 position, Vector2 size) :
	ICollidable(position, size)
{
}

void Bonk::Draw()
{
	DrawRectangleV(m_position, m_size, BLUE);
}

void Bonk::Tick()
{
	if (IsKeyDown(KEY_D)) m_position.x += 2;
	if (IsKeyDown(KEY_A)) m_position.x -= 2;
	if (IsKeyDown(KEY_W)) m_position.y -= 2;
	if (IsKeyDown(KEY_S)) m_position.y += 2;
}

bool Bonk::IsCollidingWith(ICollidable& otherObject) 
{
	return false;
}

void Bonk::OnCollision(ICollidable& otherObject)
{
	throw int(-1);
}
