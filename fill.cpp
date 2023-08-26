#include <iostream>
using namespace std;

// Function to print the given array
void printArray(int arr[][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to implement the boundary-fill algorithm
void boundaryFill(int arr[][5], int row, int col, int fillColor, int borderColor) {
    if (arr[row][col] != borderColor && arr[row][col] != fillColor) {
        arr[row][col] = fillColor;
        if (row > 0) {
            boundaryFill(arr, row - 1, col, fillColor, borderColor); // top
        }
        if (row < 4) {
            boundaryFill(arr, row + 1, col, fillColor, borderColor); // bottom
        }
        if (col > 0) {
            boundaryFill(arr, row, col - 1, fillColor, borderColor); // left
        }
        if (col < 4) {
            boundaryFill(arr, row, col + 1, fillColor, borderColor); // right
        }
    }
}

// Function to implement the flood-fill algorithm
void floodFill(int arr[][5], int row, int col, int fillColor, int oldColor) {
    if (arr[row][col] == oldColor) {
        arr[row][col] = fillColor;
        if (row > 0) {
            floodFill(arr, row - 1, col, fillColor, oldColor); // top
        }
        if (row < 4) {
            floodFill(arr, row + 1, col, fillColor, oldColor); // bottom
        }
        if (col > 0) {
            floodFill(arr, row, col - 1, fillColor, oldColor); // left
        }
        if (col < 4) {
            floodFill(arr, row, col + 1, fillColor, oldColor); // right
        }
    }
}

int main() {
    int arr[5][5] = {{0, 1, 2, 3, 4},
                     {0, 0, 1, 0, 0},
                     {1, 1, 2, 1, 0},
                     {2, 1, 2, 2, 1},
                     {3, 1, 1, 1, 0}};

    // Print the initial array
    cout << "Initial Array:" << endl;
    printArray(arr, 5);

    // Apply the boundary-fill algorithm
    boundaryFill(arr, 1, 2, 3, 1);

    // Print the array after applying boundary-fill
    cout << "After Boundary-Fill:" << endl;
    printArray(arr, 5);

    // Apply the flood-fill algorithm
    floodFill(arr, 2, 2, 3, 2);

    // Print the array after applying flood-fill
    cout << "After Flood-Fill:" << endl;
    printArray(arr, 5);

    return 0;
}
