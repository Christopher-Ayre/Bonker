#include <Road.h>

using std::vector;
using std::shared_ptr;

Road::Road(const int yPosition, const int width, const int length, const int numCars, const int carSpeed, shared_ptr<vector<Car>> carList):
	m_yPosition(yPosition),
	m_width(width),
	m_length(length),
	m_numCars(numCars),
	m_carSpeed(carSpeed),
	m_carList(carList)
{};

void Road::Draw()
{
	DrawRectangleV({ 0, static_cast<float>(m_yPosition) }, { static_cast<float>(m_length), static_cast<float>(m_width) }, BLACK);
	for (auto &car : *m_carList)
	{
		car.Draw();
	}
}

void Road::Tick()
{
	//Move cars and check for collision here
	for (auto& car : *m_carList)
	{
		car.Tick();
	}
}