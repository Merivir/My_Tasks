#ifndef SORTINGAPP_HPP
#define SORTINGAPP_HPP

#include "strategy.hpp"
#include "filehandler.hpp"

#include <iostream>

class SortingApp {
public:
    SortingApp() : strategy(nullptr) {}

    void setUserInput() {
        std::string filename = enterFileName();
        int choice = enterStrategy();
        FileHandler file;

        std::vector<int> vectorSort;

        file.fileReader(filename, vectorSort);
            
        switch (choice) {
            case 0:
                strategy = new BubbleSort();
                break;
            case 1:
                strategy = new QuickSort();
                break;
            case 2:
                strategy = new SelectionSort();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                return;
        }

        for (auto num : vectorSort) {
            std::cout << num << " ";
        }

        std::cout << std::endl;

        strategy->sortVector(vectorSort);

        file.fileWriter(filename, vectorSort);

        for (auto num : vectorSort) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }


private:
    std::string enterFileName() {
        std::string fileName;
        std::cout << "Please enter the file name " << std::endl;
        std::cin >> fileName;
        std::cout << std::endl;
    
        return fileName;
    }    

    int enterStrategy() {
        int strategy = 0;
        while (true) {
            std::cout << "Which sorting algorithm do you prefer:\nBubble: 0 \nQuick: 1 \nSelection: 2\n";
            std::cin >> strategy;
            if (strategy >=0 && strategy < 3) {
                break;
            }
            std::cout << "Incorrect input " << std::endl;
        }
        std::cout << std::endl;

        return strategy;
    }

private:
    SortingStrategy* strategy;

};

#endif //SORTINGAPP_HPP
