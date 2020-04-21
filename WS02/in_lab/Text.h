/*************************************************************************
// OOP345SFF Workshop 2 at home
// File: Text.h
// Version: 1
// Date: 2019-02-03
// Author: Alisa Tam
// Description: Header file for Text
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include<string>

namespace sict {

	class Text {
	private:
		size_t s;
		std::string * lines;
		void copy(const Text &);
		void move(Text &&);

	public:
		Text();
		Text(const std::string &);
		Text(const Text &);
		Text(Text &&);
		Text & operator=(const Text &);
		~Text();
		Text & operator=(Text &&);
		size_t size() const;
	};


}

#endif

