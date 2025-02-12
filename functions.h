
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <fstream>

// Function to check if a certain integer exists in the array
int findIndex(int arr[], int size, int num);

// Function to modify the value of an integer at a specified index
void modifyValue(int arr[], int size, int index, int newValue);

// Function to add a new integer to the end of the array
void addValue(int*& arr, int& size, int newValue);

// Function to remove an integer from the array at a given index
void removeValue(int*& arr, int& size, int index);

#endif // ARRAY_FUNCTIONS_H
