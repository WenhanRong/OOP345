/*************************************************************************
// OOP345SFF Workshop 2 at home
// File: Timekeeper.cpp
// Version: 1
// Date: 2019-02-03
// Author: Alisa Tam
// Description: Implmentation file for Timekeeper
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/



#include "Timekeeper.h"
#include<iomanip>

namespace sict {
	Timekeeper::Timekeeper() {

	}

	void Timekeeper::start() {
		begin = std::chrono::steady_clock::now();
	}
	
	void Timekeeper::stop() {
		end = std::chrono::steady_clock::now();
	}
	
	void Timekeeper::recordEvent(const char* desc) {
		if (numRecords < MAX_RECS) {
			numRecords++;
			this->record[numRecords].message = desc;
			this->record[numRecords].units = " seconds";
			std::chrono::steady_clock::duration temp = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			this->record[numRecords].duration = temp;
		}
		

	}
	
	void Timekeeper::report(std::ostream& os) const {
		os << "\nExecution Times:" << std::endl;
		for (int i = 0; i < numRecords; ++i)
			os << record[i].message << ' ' << std::setw(5) <<
			record[i].duration.count() / 1000000 << record[i].units << std::endl;

	}
}
