// #include <iostream>
// #include <fstream>

// int main(int ac, char *av[])
// {
//     if (ac != 4){
//         std::cerr << "Wrong parameters !" << std::endl;
//         exit(1);
//     }
//     std::ifstream file(av[1]);
//     if (!file.is_open()){
//         std::cerr << "Cannot open file !" << std::endl;
//         exit(1);
//     }
//     std::string s1 = av[2];
//     std::string s2 = av[3];
//     std::string read;
//     std::ofstream output("output");
//     while (std::getline(file, read)){
//         for (read.find(s1))
//             output << read.replace(read.find(s1), s2.length(), s2);
//         else
//             output << read;
//     }
//     output << std::endl;
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char *av[]) {
    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " <input_file> <s1> <s2>" << std::endl;
        return 1;
    }

    std::ifstream file(av[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file '" << av[1] << "'!" << std::endl;
        return 1;
    }

    std::string s1 = av[2];
    std::string s2 = av[3];

    // Open the output file
    std::ofstream output("output.txt");
    if (!output.is_open()) {
        std::cerr << "Error: Cannot create output file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        // Replace all occurrences of s1 with s2 in the line
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.replace(pos, s1.length(), s2);
            pos += s2.length(); // Move past the replaced substring
        }
        output << line << "\n"; // Write the modified line to the output file
    }

    std::cout << "File processed successfully. Output saved to 'output.txt'." << std::endl;

    return 0;
}
