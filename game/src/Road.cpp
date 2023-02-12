#include <Road.h>

Road::Road(const int yPosition, const int width, const int length, const int numCars, const int carSpeed) :
	m_yPosition(yPosition),
	m_width(width),
	m_length(length),
	m_numCars(numCars),
	m_carSpeed(carSpeed)
{
	const int buffer = 20;
	Vector2 size = { 100, m_width - buffer };
	Vector2 pos = { 1000, m_yPosition + (buffer/2)}; // Adding half the buffer centers the car in the road.
	m_carList.push_back(std::make_unique<Car>(m_carSpeed, m_length, pos, size )); // Needs to know about the road length so it can reset itself when it reaches the left edge
};

void Road::Draw()
{
	DrawRectangleV({ 0, static_cast<float>(m_yPosition) }, { static_cast<float>(m_length), static_cast<float>(m_width) }, BLACK);
	for (auto &car : m_carList)
	{
		car->Draw();
	}
}

void Road::Tick()
{
	//Move cars and check for collision here
	for (auto& car : m_carList)
	{
		car->Tick();
	}
}