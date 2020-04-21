/*************************************************************************
// OOP345SFF Workshop 6 at home
// File: Product.h
// Version: 1
// Date: 2019-03-24
// Author: Alisa Tam
// Description: Product class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include "iProduct.h"

namespace sict {

	class Product : public iProduct {
	private:
		int m_productNum;
		double m_price;

	public:
		Product(int, double);
		virtual double price() const override;
		virtual void display(std::ostream& os) const override;

	};

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


	//std::ostream & operator<<(std::ostream& os, const iProduct& p);
	//iProduct* readRecord(std::ifstream& file);


}
#endif
