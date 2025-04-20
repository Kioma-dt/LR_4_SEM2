#pragma once
#include <iostream>
#include <vector>

void swap(int &a, int &b);
void printArray(std::vector <int> array);

int partition(std::vector <int>& array, int left, int right);
void qsort(std::vector <int>& array, int left, int right);

void merge(std::vector <int>& array, int left, int middle, int right);
void copy(std::vector <int>& array, std::vector <int>& new_array, int from, int size);
void mergeSort(std::vector <int>& array, int left, int right);

void heapify(std::vector <int>& array, int n, int i);
void heapSort(std::vector <int>& array);

void interpolationSort(std::vector <int>& array);
void copyFromBuscket(std::vector<int> &array, std::vector<int> &buscket);

int binSearch(std::vector <int> size, int number);

int binPow(int digit, int powder, int mod);