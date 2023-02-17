#include <GameWorld.h>

GameWorld::GameWorld(const int screenWidth, const int screenHeight):
	m_screenWidth(screenWidth),
	m_screenHeight(screenHeight)
{
	Vector2 bonkSize{20,20};
	Vector2 bonkPosition{(m_screenWidth + bonkSize.x)/2 , m_screenHeight - bonkSize.y};
	m_bonk = std::make_unique<Bonk>(bonkPosition, bonkSize);

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

	m_bonk->Draw();
}

void GameWorld::tick()
{
	for (auto &road : m_levels[0]->sm_roads)
	{
		road->Tick();
	}

	m_bonk->Tick();
}