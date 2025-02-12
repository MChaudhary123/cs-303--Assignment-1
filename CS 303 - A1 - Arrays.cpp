// CS 303 - A1 - Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    int* arr = nullptr;
    int size = 0;

    // Read data from the input file into the array
    ifstream inputFile("C:\\Users\\muham\\OneDrive\\Desktop\\A1input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int num;
    while (inputFile >> num) {
        addValue(arr, size, num);
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

    // Testing modifyValue with try-catch block
    try {
        int modifyIndex = 5;
        int newValue = 500;
        modifyValue(arr, size, modifyIndex, newValue);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Testing addValue function
    try {
        int newInt = 101;
        addValue(arr, size, newInt);
        cout << "Added " << newInt << " to the array." << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Testing removeValue with try-catch block
    try {
        int removeIndex = 3;
        removeValue(arr, size, removeIndex);
        cout << "Removed value at index " << removeIndex << "." << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Clean up
    delete[] arr;

    return 0;
}

