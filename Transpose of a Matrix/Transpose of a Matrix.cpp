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

// Function to calculate the transpose of a matrix
vector<vector<double>> transposeMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<double>> result(cols, vector<double>(rows));

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

int main() {
    int rows, cols;

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

    // Calculate the transpose of the matrix
    vector<vector<double>> result = transposeMatrix(matrix);

    // Display step-by-step solution
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    cout << "Transpose of the Matrix:" << endl;
    printMatrix(result);

    return 0;
}

