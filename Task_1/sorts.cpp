#include "sorts.h"

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
};

void printArray(std::vector <int> array){
    for (auto i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
};

int partition(std::vector <int>& array, int left, int right)
{
    int base = array[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (array[i] < base)
        {
            i++;
        }

        while (array[j] > base)
        {
            j--;
        }

        if (i >= j)
        {
            break;
        }

        swap(array[i++], array[j--]);
    }
    return j;
};

void qsort(std::vector <int>& array, int left, int right)
{
    if (left < right)
    {
        int middle = partition(array, left, right);
        qsort(array, left, middle);
        qsort(array, middle + 1, right);
    }
};

void merge(std::vector <int>& array, int left, int middle, int right)
{
    int size_1 = middle - left + 1;
    int size_2 = right - middle;

    std::vector <int> arr_1 (size_1);
    std::vector <int> arr_2(size_2);

    copy(array, arr_1, left, size_1);
    copy(array, arr_2, middle + 1, size_2);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < size_1 && j < size_2)
    {
        if (arr_1[i] < arr_2[j])
        {
            array[k++] = arr_1[i++];
        }
        else
        {
            array[k++] = arr_2[j++];
        }
    }

    while (i < size_1)
    {
        array[k++] = arr_1[i++];
    }

    while (j < size_2)
    {
        array[k++] = arr_2[j++];
    }
}

void copy(std::vector <int>& array, std::vector <int>& new_array, int from, int size)
{
    for (int i = 0; i < size; i++)
    {
        new_array[i] = array[from + i];
    }
};

void mergeSort(std::vector <int>& array, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
};

void heapify(std::vector <int>& array, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[largest] < array[left]){
        largest = left;
    }
    
    if (right < n && array[largest] < array[right]){
        largest = right;
    }

    if (largest != i){
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
};

void heapSort(std::vector <int>& array){
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }

    for (int i = n - 1; i > 0; i--){
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
};

void copyFromBuscket(std::vector<int>& array, std::vector<int>& buscket){
    for (int i = 0; i < buscket.size();i++){
        array.push_back(buscket[i]);
    }
}

void interpolationSort(std::vector <int>& array){
    int size = array.size();
    std::vector<std::vector<int>> busckets(size);
    int min = 0;
    int max = 0;

    for (int i = 1; i < size; i++){
        if (array[min] > array[i]){
            min = i;
        }
        if (array[max] < array[i]){
            max = i;
        }
    }

    if (min == max){
        return;
    }

    for (int i = 0; i < size;i++){
        int inter = (array[i] - array[min]) / (array[max] - array[min]) * (size - 1);
        busckets[inter].push_back(array[i]);
    }



    std::vector<int> new_array;
    for (int i = 0; i < size; i++){
        if (busckets[i].size() > 1){
            interpolationSort(busckets[i]);
        }

        if (busckets[i].size() > 0){
            copyFromBuscket(new_array, busckets[i]);
        }
    }

    array = new_array;
};

int binSearch(std::vector <int> array, int number){
    int size = array.size();
    int left = 0;
    int right = size - 1;
    int middle = (left + right) / 2;

    while(left <= right){
        if (array[middle] == number){
            return middle;
        }

        if (number < array[middle]){
            right = middle - 1;
            middle = (left + right) / 2;
        }
        
        else {
            left = middle + 1;
            middle = (left + right) / 2;
        }
    }
    return -1;
};

int binPow(int digit, int powder, int mod){
    if (powder == 0){
        return 1;
    }

    if (powder == 1){
        return digit % mod;
    }

    if (powder % 2 == 1){
        return (binPow(digit, powder - 1, mod) * (digit % mod)) % mod;
    }
    else {
        int temp = binPow(digit, powder / 2, mod);
        return (temp * temp) % mod;
    }
};