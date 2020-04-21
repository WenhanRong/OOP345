/*************************************************************************
// OOP345SFF Workshop 4 at home
// File: Notifications.h
// Version: 1
// Date: 2019-02-27
// Author: Alisa Tam
// Description: Header file for Notifications
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include "Message.h"

namespace sict {

	class Notifications {
	private:
		const Message ** m_message;
		int m_size;
		int m_used;
	public:
		Notifications(); 
		Notifications(int maxsize);
		~Notifications();
		Notifications(Notifications &&);
		Notifications & operator=(const Notifications &);
		Notifications & operator=(Notifications&&);
		Notifications & operator+=(const Message & msg);
		Notifications & operator-=(const Message & msg);
		void display(std::ostream & os) const;
		size_t size() const;
	};
}

std::ostream & operator<<(std::ostream & os, sict::Notifications & nots);

#endif

