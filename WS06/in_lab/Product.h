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

	std::ostream & operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);


}
#endif
