#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class FileHandler {
public:
    void fileReader(std::string fileName, std::vector<int>& vectorSort) 
    {
        std::ifstream file(fileName);

        int value;
        while (file >> value) {
            vectorSort.push_back(value);
        }
        file.close();
    }

    void fileWriter(std::string fileName, const std::vector<int>& sortedVector) 
    {
        std::ofstream file(fileName);
        for (int value : sortedVector) {
            file << value << ' ';
        }

        file.close();
    }
};

#endif //FILEHANDLER_HPP
