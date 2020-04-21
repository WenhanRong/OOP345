// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Chris Szalwinski
// 2019/01/08

/*************************************************************************
// SubjectCode Deliverable: OOP345SFF Workshop 1 athome
// File: process.cpp
// Version: 1.0
// Date: 2018-01-17
// Author: Alisa Tam 131580177
// Description: provided by prof
// Revision History: None
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include <iostream>
#include "String.h"

namespace sict {
	void process(const char* str) {
		String a = String(str);
		std::cout << a << std::endl;
	}
}
