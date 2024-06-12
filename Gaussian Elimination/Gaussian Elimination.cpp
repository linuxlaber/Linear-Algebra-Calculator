#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath> // for fabs
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

// Perform Gaussian Elimination with partial pivoting
void gaussianElimination(vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        // Partial pivoting: find the row with the largest absolute value for the pivot element
        int pivotRow = i;
        for (int j = i + 1; j < rows; ++j) {
            if (fabs(matrix[j][i]) > fabs(matrix[pivotRow][i])) {
                pivotRow = j;
            }
        }
        if (pivotRow != i) {
            swap(matrix[i], matrix[pivotRow]);
            cout << "Swap row " << i + 1 << " with row " << pivotRow + 1 << ":" << endl;
            printMatrix(matrix);
        }

        // Make the diagonal elements 1
        double pivot = matrix[i][i];
        if (pivot != 0) {
            for (int j = i; j < cols; ++j) {
                matrix[i][j] /= pivot;
            }
            cout << "Divide row " << i + 1 << " by " << pivot << ":" << endl;
            printMatrix(matrix);
        }

        // Make the elements below the pivot zero
        for (int j = i + 1; j < rows; ++j) {
            double factor = matrix[j][i];
            for (int k = i; k < cols; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
            cout << "Subtract " << factor << " times row " << i + 1 << " from row " << j + 1 << ":" << endl;
            printMatrix(matrix);
        }
    }
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<double>> matrix(rows, vector<double>(cols));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Initial Matrix:" << endl;
    printMatrix(matrix);

    cout << "Applying Gaussian Elimination:" << endl;
    gaussianElimination(matrix);

    cout << "Matrix after Gaussian Elimination:" << endl;
    printMatrix(matrix);

    return 0;
}

