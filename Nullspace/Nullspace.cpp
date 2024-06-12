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

// Function to find the nullspace of a matrix
vector<vector<double>> findNullspace(const vector<vector<double>>& matrix) {
    vector<vector<double>> copyMatrix = matrix;
    gaussianElimination(copyMatrix);
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int numFreeVars = numCols - numRows; // Number of columns without pivots
    vector<vector<double>> nullspace;
    for (int i = 0; i < numFreeVars; ++i) {
        vector<double> nullVec(numCols, 0.0);
        nullVec[i + numRows] = 1.0; // Set the i-th free variable to 1
        for (int j = 0; j < numRows; ++j) {
            double sum = 0.0;
            for (int k = 0; k < numCols; ++k)
                sum += copyMatrix[j][k] * nullVec[k]; // Multiply the row of the echelon form by the null vector
            if (fabs(sum) > 1e-10)
                nullVec[j] = -sum; // Adjust the coefficients to satisfy the nullspace condition
        }
        nullspace.push_back(nullVec);
    }
    return nullspace;
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

    vector<vector<double>> nullspace = findNullspace(matrix);
    cout << "Basis for nullspace:" << endl;
    displayMatrix(nullspace);

    return 0;
}

