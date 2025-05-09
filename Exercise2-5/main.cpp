#include <iostream>
#include <cmath>
#include <numeric>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include "SortingAlgorithm.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "argc: " << argc << endl;

    for (size_t a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;

    size_t m = 10;

    if (argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "use value: " << m << endl;
    }
    else cerr << "use default value: " << m << endl;

    srand(7);
    unsigned int num_experiment = 100;

//test vectors
    vector<int> v1(m);
    iota(v1.begin(), v1.end(), -4);

    vector<double> v2(m);

    for(size_t i = 0; i < m; i++)
        v2[i] = rand() / ((double)RAND_MAX);

    vector<int> v3(m, 0);

    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;

    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());
    
// bubbleSort v1

    double time_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);
        auto start = chrono::steady_clock::now();
        SortLibrary::bubbleSort<int>(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v1 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v1 /= num_experiment;
    cout << "Bubble Sort - v1: " << time_bubble_v1 << endl;

// bubbleSort v2

    double time_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);
        auto start = chrono::steady_clock::now();
        SortLibrary::bubbleSort<double>(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v2 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v2 /= num_experiment;
    cout << "Bubble Sort - v2: " << time_bubble_v2 << endl;

// bubbleSort v3

    double time_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);
        auto start = chrono::steady_clock::now();
        SortLibrary::bubbleSort<int>(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v3 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v3 /= num_experiment;
    cout << "Bubble Sort - v3: " << time_bubble_v3 << endl;

// heapSort v1

    double time_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);
        auto start = chrono::steady_clock::now();
        SortLibrary::heapSort<int>(v);
        auto end = chrono::steady_clock::now();
        time_heap_v1 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v1 /= num_experiment;
    cout << "Heap Sort - v1: " << time_heap_v1 << endl;

// heapSort v2

    double time_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);
        auto start = chrono::steady_clock::now();
        SortLibrary::heapSort<double>(v);
        auto end = chrono::steady_clock::now();
        time_heap_v2 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v2 /= num_experiment;
    cout << "Heap Sort - v2: " << time_heap_v2 << endl;

// heapSort v3

    double time_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);
        auto start = chrono::steady_clock::now();
        SortLibrary::heapSort<int>(v);
        auto end = chrono::steady_clock::now();
        time_heap_v3 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v3 /= num_experiment;
    cout << "Heap Sort - v3: " << time_heap_v3 << endl;

    return 0;
}

