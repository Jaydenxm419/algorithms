#include <iostream>
#include <string>
#ifndef SORTING_H


class Sorting {

public:
    int comparisonCounter;
    Sorting(); 
    int doSelectionSort(std::string* items, int size);
    int doInsertionSort(std::string* items, int size);
    std::string* doMergeSort(std::string *items, int size);
    std::string* doMerge(std::string *items, std::string *leftItems, std::string *rightItems, int leftSize, int rightSize);
    int setPartition(std::string* items, int itemFromLeft, int itemFromRight);
    int doQuickSort(std::string *items, int itemFromLeft, int itemFromRight);
    std::string* doKnuthShuffle(std::string* items, int size);
};
#endif