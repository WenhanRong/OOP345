/*************************************************************************
// OOP345SFF Workshop 4 in lab
// File: List.h
// Version: 1
// Date: 2019-02-20
// Author: Alisa Tam
// Description: Header file for Message
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <string>
#include<cstring>
#include <ostream>
#include <cstddef>

namespace sict {

	constexpr size_t MAXMSG = 255;

	class Message {
	private:
		std::string m_user;
		std::string m_reply;
		std::string m_message;

	public:
		Message();
		Message(const std::string & str);
		bool empty() const;
		void display(std::ostream & os) const;
	};

}

#endif