 #include <iostream>
 // #include <>
 #include <fstream>

int main(int ac, char *av[])
{
    (void)ac;
    if (ac != 4){
        std::cerr << "Wrong parameters !" << std::endl;
        exit(1);
    }
    std::ifstream file(av[1]);
    if (!file.is_open()){
        std::cerr << "Cannot open file !" << std::endl;
        exit(1);
    }
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string read;
    std::string rep = ".replace";
    std::string name = av[1] + rep;
    std::ofstream output(name);
    if (!output.is_open()){
        std::cerr << "Cannot open file !" << std::endl;
        exit(1);
    }
    size_t pos = 0;
    while (std::getline(file, read)){
        while ((pos = read.find(s1)) != std::string::npos) {
            read.erase(pos, s1.length());
            read.insert(pos, s2);
        }
            output << read << std::endl;
    } 
    return 0;
}







