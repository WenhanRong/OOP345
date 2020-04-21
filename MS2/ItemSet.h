/*************************************************************************
// OOP345SFF Milestone 2
// File: ItemSet.h
// Version: 1.0
// Date: 2019-04-10
// Author: Alisa Tam
// Description: header file for ItemSet
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include <string>

namespace sict {

	class ItemSet {
	private:

		std::string m_name;
		std::string m_description;
		unsigned int m_serialNumber;
		unsigned int m_quantity;
		static size_t m_widthField;

	public:

		ItemSet(const std::string & string);
		const std::string & getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet & operator --();
		void display(std::ostream & os, bool full) const;

	};



}

#endif