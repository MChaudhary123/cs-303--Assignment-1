#include <iostream>
#include <limits>
#include <fstream>
#include "functions.h"

using namespace std;

// Display the menu options to the user
void displayMenu() {
    cout << "\nMenu:\n"
         << "1. Check if an integer exists\n"
         << "2. Modify an integer at index\n"
         << "3. Add new integer to end\n"
         << "4. Remove integer at index\n"
         << "5. Exit\n"
         << "Enter choice: ";
}

int main() {
    // Initialize the dynamic array
    DynamicArray arr;
    initializeArray(arr);

    // Use the fixed input file "A1input.txt"
    string filename = "A1input.txt";

    // Read integers from the file into the array
    if (!readFromFile(arr, filename)) {
        cerr << "Error opening file or file is empty.\n";
        freeArray(arr);
        return 1;
    }

    // Write the initial array to "output.txt"
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "Initial array after reading from file:\n";
        for (size_t i = 0; i < arr.size; ++i) {
            outFile << arr.data[i] << " ";
        }
        outFile << "\n\n";
        outFile.close();
    } else {
        cerr << "Error: Unable to write to output file.\n";
    }

    int choice;
    int indexInput, oldValue, newValue; // Variables for various operations

    do {
        displayMenu();
        cin >> choice;

        // Validate numeric input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: { // Check if an integer exists in the array
                int searchValue;
                cout << "Enter integer to find: ";
                cin >> searchValue;
                int index = findInteger(arr, searchValue);
                if (index != -1)
                    cout << "Integer found at index: " << index << endl;
                else
                    cout << "Integer not found.\n";
                break;
            }
            case 2: { // Modify an integer at a given index
                cout << "Enter index to modify: ";
                cin >> indexInput;
                cout << "Enter new value: ";
                cin >> newValue;
                try {
                    modifyInteger(arr, static_cast<size_t>(indexInput), newValue, oldValue);
                    cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
                    logArrayToFile(arr, "Modified index " + to_string(indexInput) +
                                        " from " + to_string(oldValue) +
                                        " to " + to_string(newValue));
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 3: { // Add a new integer to the end of the array
                cout << "Enter integer to add: ";
                cin >> newValue;
                try {
                    addInteger(arr, newValue);
                    cout << "Integer added successfully." << endl;
                    logArrayToFile(arr, "Added integer " + to_string(newValue) + " to end");
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 4: { // Remove an integer at a specified index
                cout << "Enter index to remove: ";
                cin >> indexInput;
                try {
                    removeInteger(arr, static_cast<size_t>(indexInput));
                    cout << "Integer removed successfully." << endl;
                    logArrayToFile(arr, "Removed integer at index " + to_string(indexInput));
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 5);

    // Free dynamically allocated memory
    freeArray(arr);
    return 0;
}
