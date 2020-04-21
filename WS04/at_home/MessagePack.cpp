/*************************************************************************
// OOP345SFF Workshop 4 at home
// File: MessagePack.cpp
// Version: 1
// Date: 2019-02-27
// Author: Alisa Tam
// Description: Header file for MessagePack
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/



#include "MessagePack.h"

sict::MessagePack::MessagePack()
{
	m_message = nullptr;
	m_size = 0;
	m_used = 0;
}

sict::MessagePack::MessagePack(Message ** message, int arraynum) : MessagePack()
{
	if (message == nullptr || arraynum <= 0) {
		return;
	}

	m_message = new Message[arraynum];

	m_size = arraynum;

	for (int i = 0; i < m_size; i++) {
		if (message[i] != nullptr && !message[i]->empty()) {
			m_message[m_used++] = *message[i];
		}
	}
}

sict::MessagePack::~MessagePack()
{
	delete[] m_message;
}

sict::MessagePack::MessagePack(MessagePack && mp) : MessagePack()
{
	std::swap(mp.m_message, m_message);
	std::swap(mp.m_size, m_size);
	std::swap(mp.m_used, m_used);

}

sict::MessagePack & sict::MessagePack::operator=(const MessagePack & msg)
{
	delete[] m_message;
	m_message = nullptr;
	m_size = 0;
	m_used = 0;

	if (msg.m_message != nullptr) {
		m_message = new Message[msg.m_size];

		for (int i = 0; i < msg.m_used; i++) {
			m_message[i] = msg.m_message[i];
		}

		m_used = msg.m_used;
		m_size = msg.m_size;

	}

	return *this;
}

sict::MessagePack & sict::MessagePack::operator=(MessagePack && mp)
{
	std::swap(mp.m_message, m_message);
	std::swap(mp.m_size, m_size);
	std::swap(mp.m_used, m_used);
	return *this;
}

void sict::MessagePack::display(std::ostream & os) const
{
	for (int i = 0; i < m_used; i++) {
		m_message[i].display(os);
	}
	
}

size_t sict::MessagePack::size() const
{
	return m_used;
}

std::ostream & operator<<(std::ostream & os, sict::MessagePack & msg)
{
	msg.display(os);

	return os;
}
