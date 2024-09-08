#include <iostream>
#include <fstream>
#include "assignment1.h"

using namespace std;

int checkExists(int arr[], int count, int value) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == value)
            return i; // return index
    }
    return -1; // value not found
}

void modifyValue(int arr[], int index, int newValue, int& oldValue) {
    if (index < 0 || index >= sizeof(arr)) {
        cout << "Index out of range\n";
    }
    oldValue = arr[index];
    arr[index] = newValue;
}

void addValue(int* arr[], int& count, int newValue) {
    int* newArr = new int[count + 1];  // Dynamically allocating memory for the new array
    for (int i = 0; i < count; i++) {
        newArr[i] = (*arr)[i];  // Copying the existing values
    }
    newArr[count] = newValue;  // Adding the new value to the array
    delete[] *arr;  // Deleting the old array
    *arr = newArr;  // Pointing to the new array
    count++;
}

void replaceOrRemove(int* arr[], int& count, int index, bool remove) {
    if (index < 0 || index >= count) {
        cout << "Index out of range\n"; 
    }

    if (remove) {
        for (int i = index; i < count - 1; i++) {
            (*arr)[i] = (*arr)[i + 1];
        }
        count--;
    } else {
        (*arr)[index] = 0;
    }
}

int main() {
    // Reading data from file
    ifstream inputFile("input.txt");
    int* arr = new int[100];
    int count = 0;
    int value;

    while (inputFile >> value) {
        arr[count++] = value;
    }

    inputFile.close();

    int choice, number, index, newValue, oldValue;

    while (true) {
        cout << "1. Check if a number exists\n";
        cout << "2. Modify a value\n";
        cout << "3. Add a new value\n";
        cout << "4. Replace or remove a value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter number to check: ";
                    cin >> number;
                    index = checkExists(arr, count, number);
                    if (index != -1) {
                        cout << "Number found at index " << index << endl;
                    } else {
                        cout << "Number not found\n";
                    }
                    break;
                case 2:
                    cout << "Enter index to modify: ";
                    cin >> index;
                    cout << "Enter new value: ";
                    cin >> newValue;
                    modifyValue(arr, index, newValue, oldValue);
                    cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
                    break;
                case 3:
                    cout << "Enter new value to add: ";
                    cin >> newValue;
                    addValue(&arr, count, newValue);
                    cout << "New value added\n";
                    break;
                case 4:
                    cout << "Enter index to replace/remove: ";
                    cin >> index;
                    cout << "Do you want to (1) Replace with 0 or (2) Remove? Enter choice: ";
                    int option;
                    cin >> option;
                    if (option == 1) {
                        replaceOrRemove(&arr, count, index, false);
                        cout << "Value replaced with 0\n";
                    } else if (option == 2) {
                        replaceOrRemove(&arr, count, index, true);
                        cout << "Value removed\n";
                    }
                    break;
                case 5:
                    delete[] arr; 
                    exit(0);
                default:
                    cout << "Invalid choice\n";
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
