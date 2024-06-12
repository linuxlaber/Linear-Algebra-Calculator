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

// Function to find the basis for the row space
vector<vector<double>> findRowBasis(const vector<vector<double>>& matrix) {
    vector<vector<double>> rowBasis;
    for (const auto& row : matrix) {
        bool allZero = true;
        for (double elem : row) {
            if (fabs(elem) > 1e-10) {
                allZero = false;
                break;
            }
        }
        if (!allZero)
            rowBasis.push_back(row); // Include non-zero rows in the basis for row space
    }
    return rowBasis;
}

// Function to find the basis for the column space
vector<vector<double>> findColumnBasis(const vector<vector<double>>& matrix) {
    vector<vector<double>> copyMatrix = matrix;
    gaussianElimination(copyMatrix);
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    vector<vector<double>> columnBasis;
    for (int j = 0; j < numCols; ++j) {
        bool pivotFound = false;
        for (int i = 0; i < numRows; ++i) {
            if (fabs(copyMatrix[i][j] - 1) < 1e-10) {
                pivotFound = true;
                columnBasis.push_back(matrix[i]); // Include pivot columns in the basis for column space
                break;
            }
        }
        if (!pivotFound)
            columnBasis.push_back(vector<double>(numRows, 0)); // Include non-pivot columns as zero vectors
    }
    return columnBasis;
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

    vector<vector<double>> rowBasis = findRowBasis(matrix);
    cout << "Basis for row space:" << endl;
    displayMatrix(rowBasis);

    vector<vector<double>> columnBasis = findColumnBasis(matrix);
    cout << "Basis for column space:" << endl;
    displayMatrix(columnBasis);

    return 0;
}

