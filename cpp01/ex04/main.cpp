 #include <iostream>
 #include "Replace.hpp"

int main(int ac, const char *av[])
{
	if (ac != 4){
		std::cerr << "Wrong parameters !" << std::endl;
        return false;
    }
	Replace replace;
	std::string infile = av[1];
	std::string outfile = av[1] + std::string(".replace");
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (replace.checkInfile(infile) == false)
		return (false);
	if (replace.checkOutfile(outfile) == false)
		return (false);
    replace.replaceProcess(s1, s2);
    return 0;
}







