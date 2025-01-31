#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
 #include <fstream>

class Replace {
	private:
		std::ifstream infile;
		std::ofstream outfile;
	public:
		bool checkInfile(std::string &infile);
		bool checkOutfile(std::string &outfile);
		void replaceProcess(std::string &s1, std::string &s2);
};
#endif

