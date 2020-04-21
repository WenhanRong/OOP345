/*************************************************************************
// OOP345SFF Milestone 1
// File: ItemSet.cpp
// Version: 1.0
// Date: 2019-04-03
// Author: Alisa Tam
// Description: Implementation file for ItemSet
// 
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include<iomanip>
#include "ItemSet.h"
#include "Utilities.h"

size_t sict::ItemSet::m_widthField = 1;

sict::ItemSet::ItemSet(const std::string & string)
{

	int field = 0;
	size_t np = 0;
	bool more = true;

	Utilities utilities;

	std::string name, serial, qty, desc;

	while (more) {
		switch (field++) {
		case 0: name = utilities.extractToken(string, np);
			break;
		case 1: serial = utilities.extractToken(string, np);
			break;
		case 2: qty = utilities.extractToken(string, np);
			break;
		case 3: desc = utilities.extractToken(string, np);
			break;
		default: return;
		}

		m_name = name;
		m_description = desc;
		m_quantity = atoi(qty.c_str());
		m_serialNumber = atoi(serial.c_str());


		if (name.length() > m_widthField) {
			m_widthField = name.length();
		}
		if (qty.length() > m_widthField) {
			m_widthField = qty.length();
		}

	}

}

const std::string & sict::ItemSet::getName() const
{
	return this->m_name;
}

const unsigned int sict::ItemSet::getSerialNumber() const
{
	return this->m_serialNumber;
}

const unsigned int sict::ItemSet::getQuantity() const
{
	return this->m_quantity;
}

sict::ItemSet & sict::ItemSet::operator--()
{
	if (!(m_quantity <= 0)) {

		m_quantity -= 1;
		m_serialNumber += 1;
	}

	return *this;

}

void sict::ItemSet::display(std::ostream & os, bool full) const
{

	if (full) {
		os << std::setw(m_widthField) << std::left << m_name << " [" << std::setw(6) << std::right << std::setfill('0') <<
			m_serialNumber << "] " << "Quantity " << std::left << std::setfill(' ') << std::setw(m_widthField)
			<< m_quantity << std::left << std::setw(m_widthField) << "Description: " << m_description << std::endl;
	}
	else {
		os << std::setw(m_widthField) << std::left << m_name << " [" << std::setw(6) << std::right << std::setfill('0') <<
			m_serialNumber << "]" << std::setfill(' ') << std::endl;

	}

}

