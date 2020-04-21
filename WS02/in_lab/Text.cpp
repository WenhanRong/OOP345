/*************************************************************************
// OOP345SFF Workshop 2 at home
// File: Text.cpp
// Version: 1
// Date: 2019-02-03
// Author: Alisa Tam
// Description: Implmentation file for Text
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/




#include<algorithm>
#include <fstream>
#include "Text.h"

namespace sict {
	void Text::copy(const Text &otherCopy)
	{
		s = 0;
		delete[] lines;
		lines = nullptr;

		if (!otherCopy.s) {
			return;
		}

		s = otherCopy.s;
		lines = new std::string[s];
		for (size_t i = 0; i < s; ++i) {
			lines[i] = otherCopy.lines[i];
		}
	}
	void Text::move(Text && other)
	{
		std::swap(s, other.s);
		std::swap(lines, other.lines);
	}
	sict::Text::Text()
	{

		s = 0;
		lines = nullptr;

	}

	sict::Text::Text(const std::string &fname) : Text()
	{
		std::string a;


		std::ifstream f;
		f.open(fname);
		if (!f.is_open()) {
			return;
		}

		while (!f.eof()) {
			getline(f, a);
			s++;
		}

		lines = new std::string[s];

		f.close();

		f.open(fname);
		for (size_t i = 0; i < s; ++i) {

			getline(f, lines[i]);

		}

		f.close();

	}

	sict::Text::Text(Text && other) : Text()
	{

		move(std::move(other));
	}

	Text::Text(const Text &otherCopy) : Text()
	{
		copy(otherCopy);
	}

	sict::Text::~Text()
	{
		delete[] lines;
	}

	Text & sict::Text::operator=(const Text &rhs)
	{
		copy(rhs);
		// TODO: insert return statement here
		return *this;
	}

	Text & sict::Text::operator=(Text &&rhs)
	{
		move(std::move(rhs));
		// TODO: insert return statement here
		return *this;
	}

	size_t sict::Text::size() const
	{
		return s;
	}

}
