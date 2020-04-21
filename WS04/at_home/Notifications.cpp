/*************************************************************************
// OOP345SFF Workshop 4 at home
// File: Notifications.cpp
// Version: 1
// Date: 2019-02-27
// Author: Alisa Tam
// Description: Implementation file for Notifications
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/



#include "Notifications.h"

sict::Notifications::Notifications()
{
	m_message = nullptr;
	m_size = 0;
	m_used = 0;
}

sict::Notifications::Notifications(int maxsize) : Notifications()
{
	if (maxsize <= 0) {
		return;
	}

	m_message = new const Message*[maxsize];

	for (int i = 0; i < maxsize; i++) {
		m_message[i] = nullptr;
	}

	m_size = maxsize;
}

sict::Notifications::~Notifications()
{
	delete[] m_message;
}

sict::Notifications::Notifications(Notifications && nots) : Notifications()
{
	std::swap(nots.m_message, m_message);
	std::swap(nots.m_size, m_size);
	std::swap(nots.m_used, m_used);

}

sict::Notifications & sict::Notifications::operator=(const Notifications & nots)
{
	delete[] m_message;
	m_message = nullptr;
	m_size = 0;
	m_used = 0;

	if (nots.m_message != nullptr) {
		m_message = new const Message*[nots.m_size];

		for (int i = 0; i < nots.m_size; i++) {
			m_message[i] = nots.m_message[i];
		}

		m_used = nots.m_used;
		m_size = nots.m_size;

	}

	return *this;
}

sict::Notifications & sict::Notifications::operator=(Notifications && nf)
{
	std::swap(nf.m_message, m_message);
	std::swap(nf.m_size, m_size);
	std::swap(nf.m_used, m_used);
	return *this;
}

sict::Notifications & sict::Notifications::operator+=(const Message & msg)
{
	if (m_message == nullptr || m_size == m_used || msg.empty()) {
		return *this;
	}

	for (int i = 0; i < m_size; i++) {
		if (m_message[i] == nullptr) {
			m_message[i] = &msg;
			m_used++;
			break;
		}

	}

	return *this;

}

sict::Notifications & sict::Notifications::operator-=(const Message & msg)
{
	if (m_message == nullptr || m_used == 0) {
		return *this;
	}

	for (int i = 0; i < m_size; i++) {
		if (m_message[i] == &msg) {
			m_message[i] = nullptr;
			m_used--;
			break;
		}

	}

	return *this;

}

void sict::Notifications::display(std::ostream & os) const
{
	for (int i = 0; i < m_size; i++) {
		if (m_message[i] != nullptr) {
			m_message[i]->display(os);
		}

		
	}
}

size_t sict::Notifications::size() const
{
	return m_used;
}

std::ostream & operator<<(std::ostream & os, sict::Notifications & nots)
{
	nots.display(os);

	return os;
}
