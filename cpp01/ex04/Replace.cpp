#include "Replace.hpp"

bool Replace::checkInfile(std::string &infile){
	this->infile.open(infile.c_str());
	if (!this->infile.is_open()){
        std::cerr << "Cannot open file !" << std::endl;
        return false;
    }
	return true;
}

bool Replace::checkOutfile(std::string &outfile){
	std::cout << outfile; 
	this->outfile.open(outfile.c_str());
	if (!this->outfile.is_open()){
        std::cerr << "Cannot open file !" << std::endl;
        return false;
    }
	return true;
}

void Replace::replaceProcess(std::string &s1, std::string &s2){
	std::string read;
    size_t pos = 0;
    while (std::getline(this->infile, read)){
		if(!this->infile.eof())
			read +="\n";
        while ((pos = read.find(s1)) != std::string::npos && !s1.empty()) {
            read.erase(pos, s1.length());
            read.insert(pos, s2);
        }
            this->outfile << read;
    }
}
