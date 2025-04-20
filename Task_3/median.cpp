#include "median.h"

int medianOfThree(int first, int second, int third){
    if ((first <= second && first >= third) || (first >= second && first <= third)){
        return first;
    }

    if ((second <= first && second >= third) || (second >= first && second <= third)){
        return second;
    }

    return third;
};

std::vector <int> medianOfArray(const std::vector<int> &array){
    int size = array.size();
    std::vector<int> medians;

    for (int i = 2; i < size; i+=3){
        medians.push_back(medianOfThree(array[i], array[i - 1], array[i - 2]));
    }

    if (size % 3 == 1){
        medians.push_back(array[size - 1]);
    }
    else if(size % 3 == 2){
        medians.push_back((array[size - 1] + array[size - 2]) / 2);
    }

    return medians;
};