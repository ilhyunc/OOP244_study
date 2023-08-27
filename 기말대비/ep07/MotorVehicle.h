#pragma once
#include <iostream>

using namespace std;
namespace sdds {
	class MotorVehicle
	{
		char m_plateNo[9];
		char m_address[64];
		int m_builtYear;
	public:
		MotorVehicle(const char* plateNo, int bulitYear);
		void moveTo(const char* address);
		ostream& write(ostream& os) const;
		istream& read(istream& is);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& is, MotorVehicle& vehicle);
}