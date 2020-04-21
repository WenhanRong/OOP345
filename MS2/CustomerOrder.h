/*************************************************************************
// OOP345SFF Milestone 2
// File: CustomerOrder.h
// Version: 1.0
// Date: 2019-04-10
// Author: Alisa Tam
// Description: Header file for Customer Order
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/



#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H

#include <string>
#include <new>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	struct ItemInfo
	{
		std::string m_itemName;
		unsigned int m_serialNumber = 0;
		bool m_fillState = false;

		ItemInfo(std::string src) : m_itemName(src) {};
	};

	class CustomerOrder {
	private:

		std::string m_name;
		std::string m_product;
		unsigned int m_cntItem;
		ItemInfo** m_lstItem;
		static size_t m_widthField;


	public:

		CustomerOrder();
		CustomerOrder(std::string & m);
		CustomerOrder(const CustomerOrder &); //copy constructor, throws error if anyone calls operator=
		CustomerOrder(CustomerOrder &&)noexcept;//move constructor
		CustomerOrder & operator=(CustomerOrder &&);
		CustomerOrder & operator=(const CustomerOrder &) = delete;
		~CustomerOrder();
		bool isItemFilled(std::string) const;
		bool isFilled() const;
		void fillItem(ItemSet & item, std::ostream & os);
		void display(std::ostream &) const;
		std::string getNameProduct() const;



	};

}

#endif


