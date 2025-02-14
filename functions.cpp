#include "functions.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

// Log a message and the current array contents to "output.txt".
void logArrayToFile(const DynamicArray& arr, const std::string& message) {
    std::ofstream outFile("output.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << message << "\nArray contents: ";
        for (size_t i = 0; i < arr.size; ++i) {
            outFile << arr.data[i] << " ";
        }
        outFile << "\n\n";
        outFile.close();
    } else {
        std::cerr << "Unable to open output file for logging.\n";
    }
}

// Initialize the dynamic array.
void initializeArray(DynamicArray& arr) {
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

// Free the memory allocated for the array.
void freeArray(DynamicArray& arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

// Read integers from a file into the dynamic array.
bool readFromFile(DynamicArray& arr, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    int num;
    size_t count = 0;
    // Count integers in the file.
    while (file >> num) {
        count++;
    }
    if (count == 0) {
        return false;
    }

    // Reset file stream to beginning.
    file.clear();
    file.seekg(0);

    arr.data = new int[count];
    arr.capacity = count;
    arr.size = 0;

    // Load integers into the array.
    while (file >> num) {
        arr.data[arr.size++] = num;
    }

    file.close();
    return true;
}

// Return the index of the given value, or -1 if not found.
int findInteger(const DynamicArray& arr, int value) {
    for (size_t i = 0; i < arr.size; ++i) {
        if (arr.data[i] == value) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Modify the integer at a specific index, returning the old value.
void modifyInteger(DynamicArray& arr, size_t index, int newValue, int& oldValue) {
    if (index >= arr.size) {
        throw std::out_of_range("Index out of bounds.");
    }
    oldValue = arr.data[index];
    arr.data[index] = newValue;
}

// Add a new integer to the end of the array, resizing if necessary.
void addInteger(DynamicArray& arr, int value) {
    if (arr.size >= arr.capacity) {
        size_t newCapacity = (arr.capacity == 0) ? 1 : arr.capacity * 2;
        int* newData = new int[newCapacity];
        for (size_t i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
        arr.capacity = newCapacity;
    }
    arr.data[arr.size++] = value;
}

// Remove the integer at a specified index.
void removeInteger(DynamicArray& arr, size_t index) {
    if (index >= arr.size) {
        throw std::out_of_range("Index out of bounds.");
    }
    for (size_t i = index; i < arr.size - 1; ++i) {
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
}
