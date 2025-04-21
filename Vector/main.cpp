#include <iostream>
#include "vector.h"
#include "vector.cpp"

int main(){
    Vector<int> a(3, 4);

    std::cout << a.capacity() << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }
    a[2] = 123;

    std::cout << std::endl;
    Vector<int> b(6,7);
    for (int i = 0; i < b.size(); i++)
    {
        std::cout << b[i] << std::endl;
    }
    b.push_back(1);

    std::cout << std::endl;
    a.push_back(77);
    a.resize(2, 54);
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }

    std::cout << a.capacity() << std::endl << a.size() << std::endl;

    a.swap(b);
    b.swap(a);

    std::cout << std::endl << "a:\n";
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << std::endl << "b: \n"; 
    for (int i = 0; i < b.size(); i++)
    {
        std::cout << b[i] << std::endl;
    }
}