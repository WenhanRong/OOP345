
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

	return os;
}

sict::iProduct* readRecord(std::ifstream& file);



#endif