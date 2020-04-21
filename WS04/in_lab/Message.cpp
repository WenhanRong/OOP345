
// OOP345SFF Workshop 4 in lab
// File: List.h
// Version: 1
// Date: 2019-02-20
// Author: Alisa Tam
// Description: Implementation file for Message
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
/*************************************************************************/


#include "Message.h"

namespace sict {

	Message::Message()
	{

	}

	Message::Message(const std::string & str)
	{
		char msg[MAXMSG + 1];
		msg[0] = '\0';

		strcpy(msg, str.c_str());

		char *cur = msg;
		while (*cur != '\0' && *cur != ' ') {
			m_user += *cur;

			cur++;
		}
		if (*cur == '\0') {
			m_user.clear();
			return;
		}

		cur++;

		if (*cur == '@') {
			cur++;
			while (*cur != '\0' && *cur != ' ') {
				m_reply += *cur;

				cur++;
			}

			if (*cur == '\0') {
				m_user.clear();
				m_reply.clear();
				return;
			}

			cur++;
		}



		while (*cur != '\0') {
			m_message += *cur;

			cur++;
		}

		if (m_message.length() == 0) {
			m_user.clear();
			m_reply.clear();
		}
	}

	bool Message::empty() const
	{
		return m_user.length() == 0;
	}

	void Message::display(std::ostream & os) const
	{
		
		if (m_user.length() != 0) {
			os << ">User  : " << m_user << std::endl;
		}
		
		if (m_reply.length() != 0) {
			os << " Reply : " << m_reply << std::endl;
		}

		if (m_message.length() != 0) {
			os << " Tweet : " << m_message << std::endl;
		}
		

	}

}






