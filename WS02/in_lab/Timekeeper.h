/*************************************************************************
// OOP345SFF Workshop 2 at home
// File: Timekeeper.h
// Version: 1
// Date: 2019-02-03
// Author: Alisa Tam
// Description: Header file for Timekeeper
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/



#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <chrono>
#include <ostream>

namespace sict {

	const int MAX_RECS = 10;

	class Timekeeper {
	private:
		int numRecords = 0;
		std::chrono::steady_clock::time_point begin;
		std::chrono::steady_clock::time_point end;
		struct {

			const char * message;
			const char * units;
			std::chrono::steady_clock::duration duration;

		}record[MAX_RECS]; //name of struct

	public:

		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char * description);
		void report(std::ostream & os) const;

	};
}

#endif



