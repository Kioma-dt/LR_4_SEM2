#include <iostream>
// #include "sorts.h"
#include "sorts.cpp"
#include <ctime>

int main()
{
    int n;
    std::cout << "Input n: ";
    std::cin >> n;

    std::vector <int> a(n);
    std::cout << "Input array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cout << std::endl;

    std::vector <int>sorted(n);
    clock_t begin, end;
    double duration;

    copy(a, sorted, 0, n);

    std::cout << "Qick Sort: ";

    begin = clock();
    qsort(sorted, 0, n - 1);
    end = clock();

    printArray(sorted);

    duration = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time: " << duration << " milliseconds\n\n";


    copy(a, sorted, 0, n);

    std::cout << "Merge Sort: ";

    begin = clock();
    mergeSort(sorted, 0, n - 1);
    end = clock();

    printArray(sorted);

    duration = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time: " << duration << " milliseconds\n\n";


    copy(a, sorted, 0, n);

    std::cout << "Heap Sort: ";

    begin = clock();
    heapSort(sorted);
    end = clock();

    printArray(sorted);

    duration = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time: " << duration << " milliseconds\n\n";

    copy(a, sorted, 0, n);

    std::cout << "Intrepolation Sort: ";

    begin = clock();
    interpolationSort(sorted);
    end = clock();

    printArray(sorted);

    duration = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time: " << duration << " milliseconds\n\n";


    int number, mod;
    std::cout << "Input number for search: ";
    std::cin >> number;
    std::cout << "Input mod: ";
    std::cin >> mod;
    int pos = binSearch(sorted, number);
    std::cout << "Position: " << pos << std::endl;
    std::cout << "POWDER: " << binPow(pos, sorted.size(), mod) << std::endl;
}
