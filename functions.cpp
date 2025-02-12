#include <iostream>
#include "functions.h"

using namespace std;

int findIndex(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

void modifyValue(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size) {
        throw runtime_error("Index out of bounds");
    }
    arr[index] = newValue;
}

void addValue(int*& arr, int& size, int newValue) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = newValue;
    delete[] arr;
    arr = newArr;
    size++;
}

void removeValue(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        throw runtime_error("Index out of bounds");
    }
    int* newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArr[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = newArr;
    size--;
}
