#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

const int size = 6;
enum SortingStrategy { BUBBLE, QUICK, SELECTION, INSERTION, MERGE, HEAP };


struct SortingOption {
    SortingStrategy strategy;
    void (*sortfunction)(std::vector<int>&);
};

void stringToVector(const std::string& line, std::vector<int>& vectorSort) {
    std::istringstream iss(line);
    int number;

    while (iss >> number) {
        vectorSort.push_back(number);
    }
} 

bool fileReader(std::string fileName, std::vector<int>& vectorSort) {
    std::ifstream file(fileName);

    if (!file) {
        std::cerr << "Can't open file " << fileName << std::endl;
        return true; 
    } 

    std::string readLine;

    while (std::getline(file, readLine)) {
        stringToVector(readLine, vectorSort);    
    }

    file.close();

    return false;
}

void fileWriter(std::string fileName, const std::vector<int>& sortedVector) {
    std::ofstream file(fileName);
    for (int num : sortedVector) {
        file << num << " ";
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[minIndex], arr[i]);
    }
}

void BubbleSort(std::vector<int>& sortedVector) {
    for (int i = 0; i < sortedVector.size() - 1; ++i) {
        for (int j = 0; j < sortedVector.size() - i - 1; ++j) {
            if (sortedVector[j] > sortedVector[j + 1]) {
                int tmp = sortedVector[j];
                sortedVector[j] = sortedVector[j + 1];
                sortedVector[j + 1] = tmp;
            }
        }
    }
}

void insertionSort(std::vector<int>& sortedVector) {
    for (int i = 1; i < sortedVector.size(); ++i) {
        int key = sortedVector[i];
        int j = i - 1;
        while (j >= 0 && sortedVector[j] > key) {
            sortedVector[j + 1] = sortedVector[j];
            --j;
        }
        sortedVector[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int size_l = mid - left + 1;
    int size_r = right - mid;
    std::vector<int> arr_l;
    std::vector<int> arr_r;
    
    for (int i = 0; i < size_l; ++i) {
        arr_l.push_back(arr[left + i]);
    }

    for (int i = 0; i < size_r; ++i) {
        arr_r.push_back(arr[mid + i + 1]);
    }
    
    int i = 0; 
    int j = 0;
    int k = left;

    while (i < size_l && j < size_r) {
        if (arr_l[i] > arr_r[j]) {
            arr[k++] = arr_r[j++]; 
        } else { 
            arr[k++] = arr_l[i++]; 
        }
    }

    while (i < size_l) {
        arr[k++] = arr_l[i++]; 
    }

    while (j < size_r) {
        arr[k++] = arr_r[j++]; 
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void quickSort(std::vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

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
        std::cout << "Which sorting algorithm do you prefer:\nBubble: 0 \nQuick: 1 \nSelection: 2 \nInsertion: 3 \nMerge: 4 \nHeap: 5 \n";
        std::cin >> strategy;
        if (strategy >=0 && strategy < size) {
            break;
        }
        std::cout << "Incorrect input " << std::endl;
    }
    std::cout << std::endl;

    return strategy;
}

SortingOption arr[] = {
    { BUBBLE, BubbleSort }, 
    { QUICK, quickSort }, 
    { SELECTION, selectionSort }, 
    { INSERTION, insertionSort }, 
    { MERGE, mergeSort }, 
    { HEAP, heapSort }
};

void doneOperation(std::vector<int>& vectorSorted, int strategy) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].strategy == strategy) {
            arr[i].sortfunction(vectorSorted);
        }
    }
}

int main() {
    //std::string fileName = enterFileName();
    std::string fileName = "vector.txt";
    int strategy = enterStrategy();
    
    std::vector<int> vectorSort;

    if (fileReader(fileName, vectorSort)) {
        std::cout << "Failed ";
        return 1;
    }

    doneOperation(vectorSort, strategy);
    fileWriter(fileName, vectorSort);

    std::cout << std::endl;

    return 0;
}

