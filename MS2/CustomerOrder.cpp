/*************************************************************************
// OOP345SFF Milestone 2
// File: CustomerOrder.cpp
// Version: 1.0
// Date: 2019-04-10
// Author: Alisa Tam
// Description: implementation file for Customer Orders
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include<vector>
#include<iomanip>
#include <iostream>
#include "CustomerOrder.h"




size_t sict::CustomerOrder::m_widthField = 0;

sict::CustomerOrder::CustomerOrder()
{
	m_cntItem = 0u;
	m_lstItem = nullptr;
}

sict::CustomerOrder::CustomerOrder(std::string & m) : CustomerOrder()
{
	std::vector<std::string> items;
	sict::Utilities u;

	bool more = true;
	int field = 0;
	std::string name, product, cnt;
	size_t np = 0;

	while (more) {
		switch (field++) {
		case 0: name = u.extractToken(m, np);
			break;
		case 1: product = u.extractToken(m, np);
			break;
		default: items.push_back(u.extractToken(m, np));
			more = false;
			break;
		}
	}

	//more = false;

	if (field < 3) {

		return;

	}

	m_name = name;
	m_product = product;
	m_cntItem = items.size();

	m_lstItem = new ItemInfo *[m_cntItem];

	for (unsigned int i = 0; i < m_cntItem; ++i) {
		m_lstItem[i] = new ItemInfo(items[i]);
		if (items[i].length() > m_widthField) {
			m_widthField = items[i].length();
		}
	}

	if (name.length() > m_widthField) {
		m_widthField = name.length();
	}
	if (product.length() > m_widthField) {
		m_widthField = product.length();
	}
}

sict::CustomerOrder::CustomerOrder(const sict::CustomerOrder &)
{
	throw std::string("ERROR: Cannot make copies.");
}

sict::CustomerOrder::CustomerOrder(sict::CustomerOrder && rhs) noexcept : CustomerOrder()
{
	std::swap(m_name, rhs.m_name);
	std::swap(m_product, rhs.m_product);
	std::swap(m_cntItem, rhs.m_cntItem);
	std::swap(m_lstItem, rhs.m_lstItem);
	std::swap(m_widthField, rhs.m_widthField);
}


sict::CustomerOrder & sict::CustomerOrder::operator=(sict::CustomerOrder && rhs)
{
	if (this != &rhs) {
		std::swap(m_name, rhs.m_name);
		std::swap(m_product, rhs.m_product);
		std::swap(m_cntItem, rhs.m_cntItem);
		std::swap(m_lstItem, rhs.m_lstItem);
		std::swap(m_widthField, rhs.m_widthField);
	}

	return *this;
}

sict::CustomerOrder::~CustomerOrder()
{
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		delete m_lstItem[i];
	}

	delete[] m_lstItem;
}

bool sict::CustomerOrder::isItemFilled(std::string s) const
{
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (s == m_lstItem[i]->m_itemName) {
			return m_lstItem[i]->m_fillState;
		}
	}

	return true;
}

bool sict::CustomerOrder::isFilled() const
{

	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_fillState == false) {
			return false;
		}

	}

	return true;
}

void sict::CustomerOrder::fillItem(sict::ItemSet & item, std::ostream &os)
{
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (item.getName() == m_lstItem[i]->m_itemName) {
			if (item.getQuantity()) {
				--item;

				m_lstItem[i]->m_serialNumber = item.getSerialNumber();

				m_lstItem[i]->m_fillState = true;

				os << "Filled " << m_name << "[" << m_product << "]" << "[" << m_lstItem[i]->m_itemName << "]" << "[" << m_lstItem[i]->m_serialNumber << "]" << std::endl;
			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;

			}
		}
	}

}

void sict::CustomerOrder::display(std::ostream &os) const
{
	os << std::setw(13)  << getNameProduct() << std::endl;
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		os << std::setw(13) << " " << m_lstItem[i]->m_itemName << std::endl;
		
	}
}

std::string sict::CustomerOrder::getNameProduct() const
{
	return m_name + " [" + m_product + "]";
}

