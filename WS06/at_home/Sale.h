/*************************************************************************
// OOP345SFF Workshop 6 at home
// File: Sale.h
// Version: 1
// Date: 2019-03-24
// Author: Alisa Tam
// Description: Sale header file
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_SALE_H
#define SICT_SALE_H
#include <vector>
#include "iProduct.h"


namespace sict {

	class Sale {
	private:
		std::vector <iProduct*>ip;

	public:
		Sale(const char* n);
		void display(std::ostream&) const;
		

	};


}
#endif
