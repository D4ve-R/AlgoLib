#include <iostream>
#include <vector>
#include <array>

#include "Sorting.h"

using namespace AlgoLib::Sorting;

int main()
{
    std::vector<int> vec = {8, 6, 2, 3};
    QuickSort<int>(vec, 0, 3);
    std::cout << vec[0] << vec[1] << vec[2] << vec[3] << std::endl;

    int c_Array[] = {5, 9, 4, 1};
    QuickSort<int>(c_Array, 0, 3);
    std::cout << c_Array[0] << c_Array[1] << c_Array[2] << c_Array[3] << std::endl;
    
    std::array<int, 4> std_Array = {7, 2, 4, 1};
    QuickSort<int>(std_Array, 0, 3);
    std::cout << std_Array[0] << std_Array[1] << std_Array[2] << std_Array[3] << std::endl;

    return 0;
}