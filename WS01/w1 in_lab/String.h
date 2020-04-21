/*************************************************************************
// SubjectCode Deliverable: OOP345SFF Workshop 1 in lab
// File: String.h
// Version: 1.0
// Date: 2018-01-17
// Author: Alisa Tam 131580177
// Description: header file to hold class string
// Revision History: None
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef W1_IN_LAB_STRING_H
#define W1_IN_LAB_STRING_H

#include <iostream>

extern int INITIAL;

namespace sict {

	class String {
	private:
		
		const int MAX = INITIAL;
		char * string;

	public:
		
		String(const char *);
		~String();
		void display(std::ostream &);

	};

	std::ostream & operator<<(std::ostream &, String &);
}

#endif