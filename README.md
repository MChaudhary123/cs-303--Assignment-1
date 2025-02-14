# CS 303 - Assignment 1 

# Overview
This project implements a **dynamic array** in C++ that reads integers from a file (`A1input.txt`) and allows users to search, modify, add, and remove integers interactively. It also logs changes to an output file (`output.txt`).

# Features
- Reads integers from `A1input.txt` and stores them in a dynamic array.
- Allows searching for an integer by value.
- Supports modifying an integer at a given index.
- Enables adding new integers dynamically.
- Allows removing integers by index.
- Logs all modifications to `output.txt`.

## Files
- **`main.cpp`** – Handles user interaction and menu logic.
- **`functions.cpp`** – Implements all operations on the dynamic array.
- **`functions.h`** – Header file with function declarations and the DynamicArray structure.
- **`A1input.txt`** – Input file containing integers (should be created by the user).
- **`output.txt`** – Logs changes made to the array.
