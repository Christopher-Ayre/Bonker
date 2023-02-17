#include <Bonk.h>

Bonk::Bonk(Vector2 position, Vector2 size) :
	Collidable(position, size)
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

void Bonk::OnCollision(Collidable& otherObject)
{
	throw int(-1);
}
