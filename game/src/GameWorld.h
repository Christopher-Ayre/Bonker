#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include <Road.h>

typedef struct Level{
	std::vector<std::unique_ptr<Road>> sm_roads;
} Level;

class GameWorld {
public:
	GameWorld(const int screenWidth, const int screenHeight);
	void draw();
	void tick();
private:
	const int m_screenWidth;
	const int m_screenHeight;
	std::vector<std::unique_ptr<Level>> m_levels{};
};