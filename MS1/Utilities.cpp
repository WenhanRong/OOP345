/*************************************************************************
// OOP345SFF Milestone 1
// File: Utilities.cpp
// Version: 1.0
// Date: 2019-04-03
// Author: Alisa Tam
// Description: Implementation file for Utilities
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include "Utilities.h"

char sict::Utilities::m_delimiter = ',';
bool more;

sict::Utilities::Utilities()
{

	m_widthField = 1; 

}

const std::string sict::Utilities::extractToken(const std::string & str, size_t & next_pos)
{
	std::string s;
	

	while (next_pos < str.length() && str[next_pos] != m_delimiter) {
		s += str[next_pos];
		next_pos++;
	}

	next_pos++;

	

	if (next_pos >= str.length()) {
		more = false;
	}
	else {
		if (str[next_pos] == m_delimiter) {
			throw std::string("Missing Token");
		}

		more = true;
	}

	if (s.length() > m_widthField) {

		m_widthField = s.length();
	}

	return s;
}

const char sict::Utilities::getDelimiter() const
{
	return m_delimiter;
}

size_t sict::Utilities::getFieldWidth()
{
	return this->m_widthField;
}

void sict::Utilities::setDelimiter(const char d)
{

	m_delimiter = d;

}

void sict::Utilities::setFieldWidth(size_t fw)
{

	this->m_widthField = fw;

}
