#pragma once
#include <IRenderable.h>
#include <vector>
#include <memory>
#include <Car.h>

class Road: IRenderable{
public:
	Road(const int yPosition, const int width, const int length, const int numCars, const int carSpeed);
	void Draw() override;
	void Tick();
private:
	const int m_yPosition;
	const int m_width;
	const int m_length;
	const int m_numCars;
	const int m_carSpeed;
	std::vector<std::unique_ptr<Car>> m_carList{};
};
