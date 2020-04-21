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
