/*************************************************************************
// OOP345SFF Workshop 6 at home
// File: Taxable.h
// Version: 1
// Date: 2019-03-24
// Author: Alisa Tam
// Description: Taxable class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

#include "Product.h"

namespace sict {
	class TaxableProduct : public Product {
	private:
		enum { HST, PST, NUM_TAX_CODE };
		int tax;
		static const double rate[NUM_TAX_CODE];
		static const char * rate_stl[NUM_TAX_CODE];
	public:
		TaxableProduct(int, double, char);
		virtual double price() const override;
		virtual void display(std::ostream&) const override;
		
		
	};

	iProduct * readRecord(std::ifstream & file);
	
}

#endif
