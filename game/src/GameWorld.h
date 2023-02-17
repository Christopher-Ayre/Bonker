#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include <Road.h>
#include <Bonk.h>

typedef struct Level{
	std::vector<std::unique_ptr<Road>> sm_roads;
	std::shared_ptr<std::vector<Car>> sm_cars;
} Level;

class GameWorld {
public:
	GameWorld(const int screenWidth, const int screenHeight);
	void draw();
	void tick();
	bool IsGameOver() { return m_gameOver; };
private:
	const int m_screenWidth;
	const int m_screenHeight;
	std::vector<std::unique_ptr<Level>> m_levels{};
	std::unique_ptr<Bonk> m_bonk;
	bool m_gameOver;
};