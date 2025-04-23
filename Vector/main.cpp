#include <iostream>
#include <vector>
#include "vector.h"
#include "vector.cpp"
#include "pair.h"
#include "pair.cpp"

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

    std::cout << std::endl;
    std::vector<int> shit({10, 24, 32, 10, 28, 76, 64});
    Vector<int> cool(shit.begin(), shit.end());
    cool.insert(cool.begin() + 3, 16, 2);
    for (auto i : cool)
    {
        std::cout << i << std::endl;
    }
    std::cout << cool.capacity() << std::endl;

    std::cout << std::endl;
    cool.erase(cool.begin(), cool.end() - 1);
    for (auto i : cool)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;
    Pair<Pair<int, double>, Pair<double, Vector<int>>> x;
    Pair<int, double> fir = make_pair(10, 21.10);
    Vector<int> vec(3, 4);
    Pair<double, Vector<int>> sec = make_pair(6.66, vec);
    x = make_pair(fir, sec);
    std::cout << x.first.first << '\t' << x.first.second << '\t' << x.second.first << std::endl;
    for (auto i : x.second.second){
        std::cout << i << std::endl;
    }

    std::cout << std::endl;
    Vector<Pair<double, int>> par;
    par.push_back(make_pair(10.4, 3l));
    par.push_back(make_pair(4, 5.5));
    par.push_back(make_pair(5.1, 61));

    for(auto i: par){
        std::cout << i.first << '\t' << i.second << std::endl;
    }

    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vector_(1);
    vector_.front().first.push_back(5);
    std::cout << vector_.front().first.front() << std::endl;
}