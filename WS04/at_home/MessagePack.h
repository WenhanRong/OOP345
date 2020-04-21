/*************************************************************************
// OOP345SFF Workshop 4 at home
// File: MessagePack.h
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

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include "Message.h"

namespace sict {

	class MessagePack {
	private:
		Message * m_message;
		int m_size;
		int m_used;
	public:
		MessagePack(); //safe empty state
		MessagePack(Message **message, int arraynum);
		~MessagePack();
		MessagePack(MessagePack&&);
		MessagePack& operator=(const MessagePack &);
		MessagePack & operator=(MessagePack &&);
		void display(std::ostream & os) const;
		size_t size() const;
	};

	
}

std::ostream & operator<<(std::ostream & os, sict::MessagePack & msg);

#endif
