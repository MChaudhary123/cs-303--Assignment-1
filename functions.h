#pragma once
#include <string>
#include <stdexcept>

// Structure representing a dynamic array of integers.
struct DynamicArray {
    int* data;       // Pointer to the array data.
    size_t size;     // Current number of elements.
    size_t capacity; // Maximum number of elements before resizing.
};

// Function declarations for dynamic array operations.
void initializeArray(DynamicArray& arr);                           // Initialize the array.
void freeArray(DynamicArray& arr);                                 // Free allocated memory.
bool readFromFile(DynamicArray& arr, const std::string& filename);   // Read integers from a file.
int findInteger(const DynamicArray& arr, int value);               // Return index of value or -1 if not found.
void modifyInteger(DynamicArray& arr, size_t index, int newValue, int& oldValue); // Modify element at index.
void addInteger(DynamicArray& arr, int value);                     // Add an integer to the array.
void removeInteger(DynamicArray& arr, size_t index);               // Remove the integer at a given index.
void logArrayToFile(const DynamicArray& arr, const std::string& message); // Log array state with a message.

