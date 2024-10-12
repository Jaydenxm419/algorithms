#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include "../AssignmentOne/stack.h"  // Correct path for Stack

class Search {
    public:
    void doLinearSearch(std::string *items, Stack &stack, int size);
    void doBinarySearch(std::string *items, Stack &stack, int size)
};

#endif