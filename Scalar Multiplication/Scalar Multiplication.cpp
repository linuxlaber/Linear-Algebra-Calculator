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

// Function to perform scalar multiplication on a matrix
vector<vector<double>> scalarMultiplication(const vector<vector<double>>& matrix, double scalar) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

int main() {
    int rows, cols;
    double scalar;

    // Input for matrix
    cout << "Enter the number of rows for the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns for the matrix: ";
    cin >> cols;

    vector<vector<double>> matrix(rows, vector<double>(cols));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Input for scalar
    cout << "Enter the scalar value: ";
    cin >> scalar;

    // Perform scalar multiplication
    vector<vector<double>> result = scalarMultiplication(matrix, scalar);

    // Display step-by-step solution
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    cout << "Scalar Multiplication with " << scalar << ":" << endl;
    printMatrix(result);

    return 0;
}

