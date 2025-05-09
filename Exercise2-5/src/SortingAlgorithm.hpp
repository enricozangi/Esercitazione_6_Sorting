#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

//bubbleSort

    template <typename T>
    void bubbleSort (std::vector<T>& vec) {

        size_t n = vec.size();
        
        for (size_t i = 0; i < n - 1; i++)
        {
            for (size_t j = 0; j < n - i - 1; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    std::swap(vec[j], vec[j + 1]);
                }
                
            }
            
        }  

    }

//heapify

    template <typename T>
    void heapify(std::vector<T>& vec, int n, int i) {

        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && vec[l]>vec[largest]) largest = l;
        if (r < n && vec[r]>vec[largest]) largest = r;
        if (largest != i)
        {
            std::swap(vec[i], vec[largest]);
            heapify(vec, n, largest);
        }
    
    }


//heapSort

    template <typename T>
    void heapSort(std::vector<T>& vec) {

        size_t n = vec.size();

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(vec, n, i);

        for (int i = n - 1; i > 0; i--) {

            std::swap(vec[0], vec[i]);
            heapify(vec, i, 0);
        }

    }

// selectionSort

    template <typename T>
    void SelectionSort(std::vector<T>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            size_t min_idx = i;
            for (size_t j = i + 1; j < vec.size(); ++j) {
                if (vec[j] < vec[min_idx]) {
                    min_idx = j;
                }
            }
            std::swap(vec[i], vec[min_idx]);
        }
    }

// insertionSort

    template <typename T>
    void InsertionSort(std::vector<T>& vec) {
        for (size_t i = 1; i < vec.size(); ++i) {
            T key = vec[i];
            size_t j = i;
            while (j > 0 && vec[j - 1] > key) {
                vec[j] = vec[j - 1];
                --j;
            }
            vec[j] = key;
        }
    }

}


