#include <iostream>
#include <cstddef>
#include <vector>
#include <array>

#include "Sorting.h"

template <typename Cont>
void printCont(const Cont& cont, std::size_t n)
{
    for (size_t t = 0; t < n; ++t)
    {
        std::cout << cont[t];
    }
    std::cout << std::endl;
}

int main()
{
    using namespace AlgoLib::Sorting;

    std::vector<int> vec = {8, 6, 2, 3};
    QuickSort(vec, 0, 3);
    printCont(vec, vec.size());

    int c_Array[] = {5, 9, 4, 1};
    QuickSort(c_Array, 0, 3);
    printCont(c_Array, sizeof(c_Array)/sizeof(c_Array[0]));
    
    std::array<int, 4> std_Array = {{7, 2, 4, 1}};
    QuickSort(std_Array, 0, 3);
    printCont(std_Array, std_Array.size());

    std::vector<int> vec1 = {8, 6, 2, 3};
    HeapSort(vec1, vec1.size());
    printCont(vec1, vec1.size());

    int c_Array1[] = {5, 9, 4, 1};
    HeapSort(c_Array1, 4);
    printCont(c_Array1, sizeof(c_Array1)/sizeof(c_Array1[0]));
    
    std::array<int, 4> std_Array1 = {{7, 2, 4, 1}};
    HeapSort(std_Array1, std_Array1.size());
    printCont(std_Array1, std_Array1.size());

    return 0;
}
