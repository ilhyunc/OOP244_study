#pragma once

#include <iostream>

#include "MotorVehicle.h"

using namespace std;
namespace sdds {
	class Truck : public MotorVehicle
	{
		double m_maxCargo;
		double m_currCargo;
	public:
		Truck(const char* plateNo, int builtYear, double cargo, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os) const;
		istream& read(istream& is);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& truck);
	std::istream& operator>>(std::istream& is, Truck& truck);
}