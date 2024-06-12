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

// Function to find the rank of a matrix
int findRank(const vector<vector<double>>& matrix) {
    vector<vector<double>> copyMatrix = matrix;
    gaussianElimination(copyMatrix);
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int rank = 0;
    for (int i = 0; i < numRows; ++i) {
        bool allZero = true;
        for (int j = 0; j < numCols; ++j) {
            if (fabs(copyMatrix[i][j]) > 1e-10) {
                allZero = false;
                break;
            }
        }
        if (!allZero)
            ++rank; // Increment rank for each non-zero row
    }
    return rank;
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

    int rank = findRank(matrix);
    cout << "Rank of the matrix: " << rank << endl;

    return 0;
}

