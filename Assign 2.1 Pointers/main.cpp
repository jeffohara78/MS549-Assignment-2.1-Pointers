/*
MS539 Data Structures and Testing
11-10-24
Jeff O'Hara
This is a very basic program that tests conditions of pointers by declaring a variable and storing it in memory
and accessing it via pointers to perform some basic math after collecting data from the user to compute.

*/

// Libraries
#include <iostream>

// Use the standard namespace
using namespace std;

int main() {
    int numElements;  // Number of elements in the array

    cout << "Enter the number of elements: ";
    cin >> numElements;

    // Input validation
    if (cin.fail() || numElements <= 0) 
    {
        cerr << "Invalid input! Please enter a positive integer." << endl;
        return 1;
    }

    // Dynamically allocate memory for the array using a pointer
    int* numbers = new int[numElements];

    // Check if memory allocation was successful
    if (numbers == nullptr) 
    {
        cerr << "Memory allocation failed!" << endl;
        return 1;
    }

    // Prompt the user to enter the elements
    cout << "Enter " << numElements << " integers:" << endl;
    for (int i = 0; i < numElements; ++i) 
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> *(numbers + i);  // Using pointer arithmetic to access array elements
    }

    // Calculate the sum of the elements
    int sum = 0;
    for (int i = 0; i < numElements; ++i) 
    {
        sum += *(numbers + i);  // Accessing elements using pointers
    }

    // Calculate the average
    double average = static_cast<double>(sum) / numElements;

    // Display the results
    cout << "\nSum of the elements: " << sum << endl;
    cout << "Average of the elements: " << average << endl;

    // Deallocate the memory to prevent memory leaks
    delete[] numbers;
    numbers = nullptr;  // Set the pointer to nullptr for safety

    return 0;
}
