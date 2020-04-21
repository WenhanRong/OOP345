// Assembly Line Project
// AssemblyLine.cpp
// Elliott Coleshill, Chris Szalwinski
// 2019/02/17

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Utilities.h"
#include "AssemblyLine.h"
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
	os << std::setw(13) << getNameProduct() << std::endl;
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		os << std::setw(13) << " " << m_lstItem[i]->m_itemName << std::endl;

	}
}

std::string sict::CustomerOrder::getNameProduct() const
{
	return m_name + " [" + m_product + "]";
}



namespace sict {
	const int T{ 0 }; // index for manual validation

	// constructor stores file addresses
	//
	AssemblyLine::AssemblyLine(char* filename[], int nFiles) :
		fInventory(nFiles > 0 ? filename[0] : nullptr),
		fOrders(nFiles > 1 ? filename[1] : nullptr) {
		if (nFiles < 1) throw std::string("*** Insufficient command line arguments ***\n");
	}

	// loads inventory and validates it
	//
	void AssemblyLine::loadInventory(std::ostream& os)
	{
		std::ifstream file(fInventory);
		if (!file) throw std::string("*** Unable to open Inventory file ") + std::string(fInventory);
		std::string record;
		while (!file.eof()) {
			std::getline(file, record);
			inventory.push_back(std::move(ItemSet(record)));
		}
		file.close();
		os << "Items in Stock\n";
		os << "--------------\n";
		for (size_t i = 0; i < inventory.size(); i++)
			inventory[i].display(os, true);

		// Verify that all the functionality of inventory item T is working
		os << "\nFor Manual Validation: Item " << T+1 << std::endl;
		os << " getName(): " << inventory[T].getName() << std::endl;
		os << " getSerialNumber(): " << inventory[T].getSerialNumber() << std::endl;
		os << " getQuantity(): " << inventory[T].getQuantity() << std::endl;
		--inventory[T];
		os << " getSerialNumber(): " << inventory[T].getSerialNumber() << std::endl;
		os << " getQuantity(): " << inventory[T].getQuantity() << std::endl;
	}

	// loads customer orders and validates them
	//
	void AssemblyLine::loadOrders(std::ostream& os)
	{
		if (inventory.empty()) loadInventory(os);
		std::ifstream file(fOrders);
		if (!file) throw std::string("*** Unable to open Customer Orders file ") + std::string(fOrders);
		std::string record;
		while (!file.eof()) {
			std::getline(file, record);
			orders.push_back(std::move(CustomerOrder(record)));
		}
		file.close();
		os << "\nCustomer Orders\n";
		os << "---------------\n";
		for (size_t i = 0; i < orders.size(); i++)
			orders[i].display(os);

		os << "\nFor Manual Validation" << std::endl;
		orders[orders.size() - 1].display(os);
		CustomerOrder tmp(std::move(orders[orders.size() - 1]));
		orders.pop_back();
		tmp.display(os);
		os << std::endl;

		std::string strRecord = "Chloe|Flight PC|CPU|GPU|Power Supply";
		CustomerOrder tmp2(strRecord);
		tmp2.display(os);
		tmp2 = std::move(orders[orders.size() - 1]);
		orders.pop_back();
		tmp2.display(os);

		os << "\nFor Manual Validation Filling" << std::endl;
		tmp2.display(os);
		os << " isFilled(): " << (tmp2.isFilled() ? "true" : "false") << std::endl;
		tmp2.fillItem(inventory[T], os);
		os << " isFilled(): " << (tmp2.isFilled() ? "true" : "false") << std::endl;

		for (size_t i = 0; i < inventory.size(); i++)
			tmp2.fillItem(inventory[i], os);
		os << " isFilled(): " << (tmp2.isFilled() ? "true" : "false") << std::endl;
	}
}