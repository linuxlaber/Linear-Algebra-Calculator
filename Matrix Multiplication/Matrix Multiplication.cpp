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

// Function to perform matrix multiplication
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    vector<vector<double>> result(rows1, vector<double>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input for matrix 1
    cout << "Enter the number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for matrix 1: ";
    cin >> cols1;

    vector<vector<double>> matrix1(rows1, vector<double>(cols1));

    cout << "Enter the elements of matrix 1 row by row:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> matrix1[i][j];
        }
    }

    // Input for matrix 2
    cout << "Enter the number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for matrix 2: ";
    cin >> cols2;

    vector<vector<double>> matrix2(rows2, vector<double>(cols2));

    cout << "Enter the elements of matrix 2 row by row:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> matrix2[i][j];
        }
    }

    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        cout << "Matrices cannot be multiplied. Number of columns in matrix 1 must be equal to number of rows in matrix 2." << endl;
        return 0;
    }

    // Perform matrix multiplication
    vector<vector<double>> result = matrixMultiplication(matrix1, matrix2);

    // Display step-by-step solution
    cout << "Matrix 1:" << endl;
    printMatrix(matrix1);

    cout << "Matrix 2:" << endl;
    printMatrix(matrix2);

    cout << "Result of Matrix 1 multiplied by Matrix 2:" << endl;
    printMatrix(result);

    return 0;
}

