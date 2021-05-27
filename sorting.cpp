#include <iostream>
#include <vector>

#include "sorting.h"

int main(){
    std::vector<int> vec;
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(2);
    QuickSort<int>(vec, 0, 3);
    std::cout << vec[0] << vec[1] << vec[2] << vec[3] << std::endl;

    int arr[] = {5, 6, 4, 3};
    QuickSort<int>(arr, 0, 3);
    std::cout << arr[0] << arr[1] << arr[2] << arr[3] << std::endl;
    
}