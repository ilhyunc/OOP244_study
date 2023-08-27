#define _CRT_SECURE_NO_WARNINGS

#include "MotorVehicle.h"

#include <iomanip>

using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* plateNo, int bulitYear)
	{
		strcpy(m_plateNo, plateNo);
		m_builtYear = bulitYear;
		strcpy(m_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (address && m_address != address)//
		{
			cout << '|' << setw(8) << right << m_plateNo << "| |";
			cout << setw(20) << right << m_address << " ---> ";
			strcpy(m_address, address);
			cout << setw(20) << left << address << '|' << endl;

			cout << right;
		}
	}

	ostream& MotorVehicle::write(ostream& os) const
	{
		return os << "| " << m_builtYear << " | " << m_plateNo << " | " << m_address;
	}

	istream& MotorVehicle::read(istream& is)
	{
		cout << "Built year: ";
		is >> m_builtYear;
		is.ignore(1000, '\n');

		cout << "License plate: ";
		is.getline(m_plateNo, sizeof(m_plateNo) - 1);

		cout << "Current location: ";
		is.getline(m_address, sizeof(m_address) - 1);

		return is;
	}

	std::istream& operator>>(std::istream& is, MotorVehicle& vehicle)
	{
		return vehicle.read(is);
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle)
	{
		return vehicle.write(os);
	}



}
