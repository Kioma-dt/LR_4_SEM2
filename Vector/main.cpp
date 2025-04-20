#include <iostream>
#include "vector.h"
#include "vector.cpp"

int main(){
    Vector<int> a;
    a.push_back(1);
    a.push_back(10);
    a.push_back(5);

    std::cout << a.capacity() << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }

    a.pop_back();
    std::cout << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }

    a.clear();
    std::cout << a.at(1) << std::endl;
}