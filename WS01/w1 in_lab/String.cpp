/*************************************************************************
// SubjectCode Deliverable: OOP345SFF Workshop 1 in lab
// File: String.cpp
// Version: 1.0
// Date: 2018-01-17
// Author: Alisa Tam 131580177
// Description: implementation file for String.h file
// Revision History: None
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include "String.h"
#include<iomanip>
#include<cstring>

sict::String::String(const char * s)
{
	string = new char[MAX + 1];

	if (s == nullptr) {
		string[0] = '\0';
	}
	else {
		std::strncpy(string, s, MAX);
		string[MAX] = '\0';
	}

}

sict::String::~String()
{
	delete[] string;
}

void sict::String::display(std::ostream & os)
{
	
	os << string;

}

std::ostream & sict::operator<<(std::ostream & os, String & s)
{
	static int cnt = INITIAL;
	os << cnt << ": ";
	s.display(os);

	cnt++;

	return os;
}
