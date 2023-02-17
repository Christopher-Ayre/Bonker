#pragma once
#include <raylib.h>
#include <Collidable.h>

class Bonk : public Collidable {
public:
	Bonk(Vector2 position, Vector2 size);
	void Draw();
	void Tick();

	void OnCollision(Collidable& otherObject) override;
};
