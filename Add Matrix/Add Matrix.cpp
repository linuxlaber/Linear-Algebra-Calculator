#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to print the matrix
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double elem : row) {
            cout << setw(10) << fixed << setprecision(4) << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to add two matrices
vector<vector<double>> addMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
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

    // Check if matrices can be added
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        cout << "Matrices cannot be added. Dimensions are not equal." << endl;
        return 0;
    }

    // Add matrices
    vector<vector<double>> result = addMatrices(matrix1, matrix2);

    // Display step-by-step solution
    cout << "Matrix 1:" << endl;
    printMatrix(matrix1);

    cout << "Matrix 2:" << endl;
    printMatrix(matrix2);

    cout << "Result of adding Matrix 1 and Matrix 2:" << endl;
    printMatrix(result);

    return 0;
}

