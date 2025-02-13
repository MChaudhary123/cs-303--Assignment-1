#include <iostream>
#include "functions.h"

using namespace std;

// Function to find the index of a given number in the array
int findIndex(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to modify a value at a given index
void modifyValue(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size) {
        throw runtime_error("Invalid index. Cannot modify value.");
    }
    arr[index] = newValue;
}

// Function to add a new integer to the end of the array
void addValue(int*& arr, int& size, int newValue) {
    int* newArr = new int[size + 1];  // Create a new array with extra space
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];  // Copy existing elements
    }
    newArr[size] = newValue;  // Add the new value
    delete[] arr;  // Delete the old array
    arr = newArr;
    size++;  // Increase the size
}

// Function to remove a value at a specified index
void removeValue(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        throw runtime_error("Invalid index. Cannot remove value.");
    }

    int* newArr = new int[size - 1];  // Create a smaller array
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArr[j] = arr[i];  // Copy all elements except the one at 'index'
            j++;
        }
    }
    delete[] arr;  // Delete the old array
    arr = newArr;
    size--;  // Decrease the size
}
