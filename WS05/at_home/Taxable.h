/*************************************************************************
// OOP345SFF Workshop 5 at home
// File: Taxable.h
// Version: 1
// Date: 2019-02-28
// Author: Alisa Tam
// Description: Taxable module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict {
	class Taxable {
	private:
		float rate = 0.0f;
	public:
		inline Taxable() {};
		inline Taxable(const float r) {
			rate = r;
		}

		inline float operator()(float price) {
			return price * (1 + rate);
		}


	};

	
}

#endif
