#include <iostream>
#include <vector>
#include "median.cpp"

int main(){
    int size;

    std::cout << "Input array size: ";
    std::cin >> size;

    std::vector<int> array(size);
    std::cout << "Input array: ";
    for (int i = 0; i < size; i++){
        std::cin>>array[i];
    }

    std::vector<int> median = medianOfArray(array);

    std::cout << "Medians: ";
    for (auto i : median)
    {
        std::cout << i << ' ';
    }
    std::cout<<std::endl;
}