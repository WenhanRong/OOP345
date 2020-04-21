/*************************************************************************
// OOP345SFF Workshop 6 at home
// File: Product.cpp
// Version: 1
// Date: 2019-03-24
// Author: Alisa Tam
// Description: Implementation for product
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include<iomanip>
#include<fstream>
#include "Product.h"

extern int FW;
const double sict::TaxableProduct::rate[NUM_TAX_CODE] = { 1.13, 1.08 };
const char * sict::TaxableProduct::rate_stl[NUM_TAX_CODE] = { "HST", "PST" };



sict::Product::Product(int n, double p) : m_productNum(n), m_price(p)
{

}

double sict::Product::price() const
{
	return m_price;
}

void sict::Product::display(std::ostream & os) const
{
	
	os << std::setw(FW) << m_productNum << std::setfill(' ') << std::setw(FW) << std::fixed << std::setprecision(2) << m_price;

}

sict::TaxableProduct::TaxableProduct(int p_num, double price, char t) : Product(p_num, price)
{
	t == 'H' ? tax = HST : tax = PST;
}

double sict::TaxableProduct::price() const
{
	return Product::price() * rate[tax];
}

void sict::TaxableProduct::display(std::ostream & os) const
{
	Product::display(os);
	os << ' ' << rate_stl[tax];

}

sict::iProduct * sict::readRecord(std::ifstream & file)
{

	int a;
	double b;
	char c = '\0';

	file >> a >> b;

	if (!file.good()) {
		return nullptr;
	}

	if (file.peek() == ' ') {
		file >> c;
	}

	char buff[128];

	file.getline(buff, 128);

	if (c == 'H' || c == 'P') {
		return new sict::TaxableProduct(a, b, c);

	}

	if (c == '\0') {
		return new sict::Product(a, b);

	}

	else {
		return nullptr;
	}


	//return c ? (new sict::TaxableProduct(a, b, c)) : (new sict::Product(a, b));

}


//sict::iProduct* sict::readRecord(std::ifstream& file) {
//	
//	int a;
//	double b;
//
//	file >> a >> b;
//
//	if (!file.good()) {
//		return nullptr;
//	}
//
//	
//	char buff[128];
//
//	file.getline(buff, 128);
//	
//	return new sict::Product(a, b);
//	
//
//}
//
