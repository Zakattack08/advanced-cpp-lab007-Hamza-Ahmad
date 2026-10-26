#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>
#include <iostream>
// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    if (n < 0) {
        throw std::logic_error("factorial is undefined for negative values");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    if (n<0) {
        throw std::logic_error("Invald Input");
    }
    int total = 1;
    for (int i=1; i<=n; i++) {
        total *= i;
    }
    return total;
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if (n<0) {
        throw std::logic_error("Invalid Input");
    }
    else if (n == 0 || n==1) {
        return n;
    }
    return fibonacci(n-2)+fibonacci(n-1);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    if (n<0) {
        throw std::logic_error("Invalid Input");
    }
    int current = 0;
    int prev=1;
    for (int i = 0; i<n; i++) {
        current+=prev;
        prev=current-prev;
    }
    return current;
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.

//helper
int binarySearch(const std::vector<int>& array, int target, int lower, int upper) {
    if (upper < lower) return -1; //target not found
    int cursor = ((upper-lower)/2)+lower;
    if (array[cursor] == target) return cursor; //base case
    //target is in lower half
    else if (array[cursor] > target) return binarySearch(array, target, lower, cursor-1); 
    //target is in upper half
    else if (array[cursor] < target) return binarySearch(array, target, cursor+1, upper);
    return -1; //in case all else somehow fails
}
//Wraper function
int binarySearch(const std::vector<int>& array, int target) {
    if (array.empty()) { //invalid case
        return -1;
    }
    else { //Call Helper
        return binarySearch(array, target, 0, array.size()-1);
    }
    return -1; //in case all else somehow fails
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    if (array.empty()) return -1; //invalid case
    int upper = (array.size()-1);
    int cursor = 0;
    int lower = 0;
    while (upper >= lower) // stop loop when target is found
    {
        cursor = ((upper-lower)/2)+lower;
        if (array[cursor] == target) return cursor; //base case
        else if (array[cursor] > target) upper = cursor-1; //target is in lower half
        else if (array[cursor] < target) lower = cursor+1; //target is in upper half
    }
    return -1; // break if target not found
    
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).

int arraySum(const std::vector<int>& array, int index) { //helper
    if (index == array.size()) return 0; //base case
    else return arraySum(array, index+1) + array[index]; //recursive call
}

int arraySum(const std::vector<int>& array) { //wrapper
    if (array.empty()) return 0;
    return arraySum(array, 0);
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (const int& e : array) sum+=e;
    return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array, int index_to_swap) { //helper
    int other = array.size()-1-index_to_swap;
    if (index_to_swap>=other) return;
    std::swap(array[index_to_swap], array[other]);
    reverseArray(array,index_to_swap+1);
}
void reverseArray(std::vector<int>& array) { //wrapper
    reverseArray(array,0);
    return;
}

// TODO: Implement iterative rechaverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left < right) {
        std::swap(array[left], array[right]);
        ++left;
        --right;
    }
}
