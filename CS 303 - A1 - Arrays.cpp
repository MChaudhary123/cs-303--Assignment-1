// CS 303 - A1 - Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Muhammad Chaudhary


 #include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    int* arr = nullptr;  // Array pointer
    int size = 0;        // Size of the array

    // Read data from the input file
    ifstream inputFile("C:\\Users\\muham\\OneDrive\\Desktop\\A1input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;  // Exit if file cannot be opened
    }

    int num;
    while (inputFile >> num) {
        addValue(arr, size, num);  // Add numbers from file to array
    }
    inputFile.close();

    // Testing findIndex function
    int searchNum = 25;
    int index = findIndex(arr, size, searchNum);
    if (index != -1) {
        cout << "Number " << searchNum << " found at index: " << index << endl;
    }
    else {
        cout << "Number " << searchNum << " not found." << endl;
    }

    // Testing modifyValue function with try-catch
    try {
        int modifyIndex = 5;   // Index to modify
        int newValue = 500;    // New value
        modifyValue(arr, size, modifyIndex, newValue);
        cout << "Modified index " << modifyIndex << " to " << newValue << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Testing addValue function with try-catch
    try {
        int newInt = 101;
        addValue(arr, size, newInt);
        cout << "Added " << newInt << " to the array." << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Testing removeValue function with try-catch
    try {
        int removeIndex = 3;  // Index to remove
        removeValue(arr, size, removeIndex);
        cout << "Removed value at index " << removeIndex << "." << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Free allocated memory
    delete[] arr;

    return 0;
}

