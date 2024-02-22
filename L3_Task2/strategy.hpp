#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <vector>

class SortingStrategy {
public:
    virtual void sortVector(std::vector<int>& srotedVector) = 0;
};

class BubbleSort : public SortingStrategy {
public:
    void sortVector(std::vector<int>& sortedVector) override 
    {
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
};

class QuickSort : public SortingStrategy {
public:
    void sortVector(std::vector<int>& sortedVector) override 
    {
        quickSort(sortedVector, 0, sortedVector.size() - 1);
    }

private:
    int partition(std::vector<int>& arr, int low, int high) 
    {
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

    void quickSort(std::vector<int>& arr, int low, int high)
    {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
};


class SelectionSort : public SortingStrategy {
public:
    void sortVector(std::vector<int>& sortedVector) override 
    {
        int n = sortedVector.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (sortedVector[j] < sortedVector[minIndex]) {
                    minIndex = j;
                }
            }

            std::swap(sortedVector[minIndex], sortedVector[i]);
        }
    }
};

  

#endif // STRATEGY_HPP
