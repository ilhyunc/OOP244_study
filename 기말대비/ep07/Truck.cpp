#include "Truck.h"

using namespace std;
namespace sdds {
	Truck::Truck(const char* plateNo, int builtYear, double cargo, const char* address) : MotorVehicle(plateNo, builtYear)
	{
		m_currCargo = 0;
		m_maxCargo = cargo;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		double temp = m_currCargo;
		if (m_currCargo < m_maxCargo)
		{
			m_currCargo += cargo;

			if (m_currCargo > m_maxCargo)
			{
				m_currCargo = m_maxCargo;
			}
		}

		return temp != m_currCargo;
	}

	bool Truck::unloadCargo()
	{
		double temp = m_currCargo;

		m_currCargo = 0;

		return temp != m_currCargo;
	}

	ostream& Truck::write(ostream& os) const
	{
		MotorVehicle::write(os) << " | " << m_currCargo << '/' << m_maxCargo;

		return os;
	}

	istream& Truck::read(istream& is)
	{
		MotorVehicle::read(is);

		cout << "Capacity: ";
		is >> m_maxCargo;

		cout << "Cargo: ";
		is >> m_currCargo;

		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& truck)
	{
		return truck.write(os);
	}

	std::istream& operator>>(std::istream& is, Truck& truck)
	{
		return truck.read(is);
	}
}