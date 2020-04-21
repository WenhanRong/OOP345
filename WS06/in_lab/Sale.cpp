#include<fstream>
#include <iomanip>
#include "Sale.h"

extern int FW;

sict::Sale::Sale(const char * n)
{
	std::ifstream f;
	f.open(n, std::ifstream::in);

	if (!f.good()) {
		throw std::string("Error");
	}

	iProduct * temp;

	while ((temp = readRecord(f))) {
		ip.push_back(temp);
	}
	
}

 

void sict::Sale::display(std::ostream & os) const
{
	double sum = 0;

	os << std::setw(FW) << "\nProduct No" << std::setw(FW) << "Cost" << std::endl;
	for (auto i : ip) {
		os << *i;
		sum += i->price();
	}

	os << std::setw(FW) << "Total" << std::setw(FW) << sum << std::endl;
}