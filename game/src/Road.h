#pragma once
#include <IRenderable.h>
#include <vector>
#include <memory>
#include <Car.h>

class Road: IRenderable{
public:
	Road(const int yPosition, const int width, const int length, const int numCars, const int carSpeed, std::shared_ptr<std::vector<Car>> m_carList );
	void Draw() override;
	void Tick();
private:
	const int m_yPosition;
	const int m_width;
	const int m_length;
	const int m_numCars;
	const int m_carSpeed;
	std::shared_ptr<std::vector<Car>> m_carList{};
};
