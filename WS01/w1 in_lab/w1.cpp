/*************************************************************************
// SubjectCode Deliverable: OOP345SFF Workshop 1 in lab
// File: w1.cpp
// Version: 1.0
// Date: 2018-01-17
// Author: Alisa Tam 131580177
// Description: cpp file to hold main
// Revision History: None
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include <iostream>
#include <fstream>
#include "process.h"

int INITIAL = 3;

	int main(int argc, char * argv[]) {

		std::cout << "Command Line : ";
		for (int i = 0; i < argc; ++i) {
			std::cout << argv[i] << ' ';
		}
		if (argc < 1) {
			std::cout << "\n***Insufficient number of arguments***\n";
			return 1;
			 
		}

		std::cout << "\n";

		for (int i = 1; i < argc; ++i)
		{
			sict::process(argv[i]);
		}		
		

		return 0;

	}

