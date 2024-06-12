#include <iostream>
#include <vector>
#include <cmath> // For fabs
using namespace std;

// Function to swap two rows of a matrix
void swapRows(vector<vector<double>>& matrix, int row1, int row2) {
    vector<double> temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

// Function to perform Gaussian elimination
void gaussianElimination(vector<vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    int lead = 0;
    for (int r = 0; r < numRows; ++r) {
        if (lead >= numCols)
            return;
        int i = r;
        while (fabs(matrix[i][lead]) < 1e-10) {
            ++i;
            if (i == numRows) {
                i = r;
                ++lead;
                if (lead == numCols)
                    return;
            }
        }
        swapRows(matrix, i, r);

        double lv = matrix[r][lead];
        for (int j = 0; j < numCols; ++j)
            matrix[r][j] /= lv;

        for (int i = 0; i < numRows; ++i) {
            if (i != r) {
                lv = matrix[i][lead];
                for (int j = 0; j < numCols; ++j)
                    matrix[i][j] -= lv * matrix[r][j];
            }
        }
        ++lead;
    }
}

// Function to check if a matrix is linearly dependent
bool isLinearlyDependent(const vector<vector<double>>& matrix) {
    vector<vector<double>> copyMatrix = matrix;
    gaussianElimination(copyMatrix);
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    for (int i = 0; i < numRows; ++i) {
        bool allZero = true;
        for (int j = 0; j < numCols; ++j) {
            if (fabs(copyMatrix[i][j]) > 1e-10) {
                allZero = false;
                break;
            }
        }
        if (allZero)
            return true; // If any row becomes all zeros, the matrix is linearly dependent
    }
    return false; // If no row becomes all zeros, the matrix is linearly independent
}

// Function to display a matrix
void displayMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows, numCols;

    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    vector<vector<double>> matrix(numRows, vector<double>(numCols));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix:" << endl;
    displayMatrix(matrix);

    bool linearlyDependent = isLinearlyDependent(matrix);
    if (linearlyDependent) {
        cout << "The vectors represented by the rows of the matrix are linearly dependent." << endl;
    } else {
        cout << "The vectors represented by the rows of the matrix are linearly independent." << endl;
    }

    return 0;
}

