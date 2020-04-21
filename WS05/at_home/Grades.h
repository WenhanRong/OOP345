/*************************************************************************
// OOP345SFF Workshop 5 at home
// File: Grades.h
// Version: 1
// Date: 2019-02-28
// Author: Alisa Tam
// Description: Grades module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_GRADES_H
#define SICT_GRADES_H

namespace sict {
	class Grades {
	private:
	public:
		inline const char * operator()(float f) {

			if (f <= 100 && f >= 90) {
				return "A+";
			}
			else if (f < 90 && f >= 80) {
				return "A ";
			}
			else if (f < 80 && f >= 75) {
				return "B+";
			}
			else if (f < 75 && f >= 70) {
				return "B ";
			}
			else if (f < 70 && f >= 65) {
				return "C+";
			}
			else if (f < 65 && f >= 60) {
				return "C ";
			}
			else if (f < 60 && f >= 55) {
				return "D+";
			}
			else if (f < 55 && f >= 50) {
				return "D ";
			}
			else {
				return "F ";
			}
			
		}
	};
}
#endif