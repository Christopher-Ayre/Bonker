#pragma once
#include <raylib.h>
#include <ICollidable.h>

class Bonk : public ICollidable {
public:
	Bonk(Vector2 position, Vector2 size);
	void Draw();
	void Tick();

	bool IsCollidingWith(ICollidable& otherObject) override;
	void OnCollision(ICollidable& otherObject) override;
};
