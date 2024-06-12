#include <iostream>
#include <vector>
using namespace std;

// Function to check if two matrices are equal
bool areMatricesEqual(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // If dimensions of matrices are different, they can't be equal
    if (rows1 != rows2 || cols1 != cols2) {
        return false;
    }

    // Check each element for equality
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }

    // If all elements are equal, matrices are equal
    return true;
}

int main() {
    int rows, cols;

    // Input for matrix 1
    cout << "Enter the number of rows for matrix 1: ";
    cin >> rows;
    cout << "Enter the number of columns for matrix 1: ";
    cin >> cols;

    vector<vector<double>> matrix1(rows, vector<double>(cols));

    cout << "Enter the elements of matrix 1 row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix1[i][j];
        }
    }

    // Input for matrix 2
    cout << "Enter the number of rows for matrix 2: ";
    cin >> rows;
    cout << "Enter the number of columns for matrix 2: ";
    cin >> cols;

    vector<vector<double>> matrix2(rows, vector<double>(cols));

    cout << "Enter the elements of matrix 2 row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix2[i][j];
        }
    }

    // Check if matrices are equal
    if (areMatricesEqual(matrix1, matrix2)) {
        cout << "Matrices are equal." << endl;
    } else {
        cout << "Matrices are not equal." << endl;
    }

    return 0;
}

