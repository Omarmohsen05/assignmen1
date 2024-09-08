#ifndef HEADER_H
#define HEADER_H


// Function to check if an integer exists in the array and return the index
int checkExists(int arr[], int size, int value);

// Function to modify the value of an integer in the array and return the old and new values
void modifyValue(int arr[], int index, int newValue, int& oldValue);

// Function to add a new integer to the end of the array
void addValue(int*& arr, int& size, int newValue);

// Function to replace or remove an integer at a specific index in the array
void replaceOrRemove(int*& arr, int& size, int index, bool remove);

#endif
