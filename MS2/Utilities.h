/*************************************************************************
// OOP345SFF Milestone 2
// File: Utilities.h
// Version: 1.0
// Date: 2019-04-10
// Author: Alisa Tam
// Description: header file for Utilities
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <string>

namespace sict {

	class Utilities {
	private:

		size_t m_widthField;
		static char m_delimiter;

	public:
		Utilities();
		const std::string extractToken(const std::string &str, size_t &next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth();
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
		
	};

}

#endif