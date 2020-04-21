

#include<iomanip>
#include<fstream>
#include "Product.h"

extern int FW;

sict::Product::Product(int n, double p) : m_productNum(n), m_price(p)
{

}

double sict::Product::price() const
{
	return m_price;
}

void sict::Product::display(std::ostream & os) const
{
	
	os << std::setw(FW) << m_productNum << std::setfill(' ') << std::setw(FW) << std::fixed << std::setprecision(2) << m_price << std::endl;

}

sict::iProduct* readRecord(std::ifstream& file) {
	
	int a;
	double b;

	file >> a >> b;

	if (!file.good()) {
		return nullptr;
	}

	
	char buff[128];

	file.getline(buff, 128);
	
	return new sict::Product(a, b);
	

}



