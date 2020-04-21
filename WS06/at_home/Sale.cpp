/*************************************************************************
// OOP345SFF Workshop 6 at home
// File: Sale.cpp
// Version: 1
// Date: 2019-03-24
// Author: Alisa Tam
// Description: Implementation for Sale
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include <fstream>
#include <iomanip>
#include <string>
#include "Sale.h"
#include "Product.h"

extern int FW;

sict::Sale::Sale(const char * n)
{
	std::ifstream f;
	f.open(n, std::ifstream::in);

	if (!f.good()) {
		throw std::string("Error");
	}

	iProduct * temp;

	while ((temp = sict::readRecord(f))) {
		ip.push_back(temp);
	}
	
}

void sict::Sale::display(std::ostream & os) const
{
	double sum = 0;
	os << std::endl;
	os << std::setw(FW) << "Product No" << std::right << std::setw(FW) << "Cost" << ' ' << "Taxable" << std::endl;
	for (auto i : ip) {
		os << *i;
		sum += i->price();
	}

	os << std::setw(FW) << "Total" << std::setw(FW) << sum << std::endl;
}