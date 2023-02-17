#include <GameWorld.h>

GameWorld::GameWorld(const int screenWidth, const int screenHeight):
	m_screenWidth(screenWidth),
	m_screenHeight(screenHeight),
	m_gameOver(false)
{
	Vector2 bonkSize{20,20};
	Vector2 bonkPosition{(m_screenWidth + bonkSize.x)/2 , m_screenHeight - bonkSize.y};
	m_bonk = std::make_unique<Bonk>(bonkPosition, bonkSize);

	auto level1 = std::make_unique<Level>();


	const int buffer = 20;
	Vector2 size = { 100, 100 - buffer };
	Vector2 pos = { 1000, 80 + (buffer/2) }; // Adding half the buffer centers the car in the road.
	
	//Setup Cars
	std::vector<Car> cars{ Car(10, LEFT, m_screenWidth, pos, size) };
	auto carList = std::make_shared<std::vector<Car>>(std::move(cars));
	auto emptyCarList = std::make_shared<std::vector<Car>>();

	level1->sm_cars = carList;
	level1->sm_roads.push_back(std::make_unique<Road>(80, 100, m_screenWidth, 1, 10, carList));
	level1->sm_roads.push_back(std::make_unique<Road>(280, 100, m_screenWidth, 2, 20, emptyCarList));
	level1->sm_roads.push_back(std::make_unique<Road>(480, 100, m_screenWidth, 3, 30, emptyCarList));
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
	int currentLevel = 0;

	for (auto &road : m_levels[currentLevel]->sm_roads)
	{
		road->Tick();
	}

	for (auto& car : *(m_levels[currentLevel]->sm_cars))
	{
		if (car.IsCollidingWith(*m_bonk))
		{
			m_gameOver = true;
		}
	}

	m_bonk->Tick();
}