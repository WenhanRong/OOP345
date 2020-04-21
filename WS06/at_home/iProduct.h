/*************************************************************************
// OOP345SFF Workshop 6 at home
// File: iProduct.h
// Version: 1
// Date: 2019-03-24
// Author: Alisa Tam
// Description: Interface for other derived classes
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

#include<iostream>

namespace sict {

	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& ) const = 0;

	};


}

inline std::ostream& operator<<(std::ostream& os, const sict::iProduct& p)
{
	p.display(os);
	os << std::endl;

	return os;
}

//            sict::iProduct* readRecord(std::ifstream& file);



#endif