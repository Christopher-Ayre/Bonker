#include <GameWorld.h>

GameWorld::GameWorld(const int screenWidth, const int screenHeight):
	m_screenWidth(screenWidth),
	m_screenHeight(screenHeight)
{
	auto level1 = std::make_unique<Level>();
	level1->sm_roads.push_back(std::make_unique<Road>(80, 100, m_screenWidth, 1, 10));
	level1->sm_roads.push_back(std::make_unique<Road>(280, 100, m_screenWidth, 2, 20));
	level1->sm_roads.push_back(std::make_unique<Road>(480, 100, m_screenWidth, 3, 30));
	m_levels.push_back(std::move(level1));
}

void GameWorld::draw()
{
	for (auto &road : m_levels[0]->sm_roads)
	{
		road->Draw();
	}
}

void GameWorld::tick()
{
	for (auto &road : m_levels[0]->sm_roads)
	{
		road->Tick();
	}
}