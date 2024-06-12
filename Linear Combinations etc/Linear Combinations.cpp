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

// Function to perform linear combination of vectors
vector<double> linearCombination(const vector<vector<double>>& vectors, const vector<double>& coefficients) {
    // Check if the number of vectors and coefficients match
    if (vectors.size() != coefficients.size()) {
        cout << "Error: Number of vectors and coefficients must be the same." << endl;
        return {};
    }
    
    // Check if the vectors are of the same dimension
    int dimension = vectors[0].size();
    for (int i = 1; i < vectors.size(); ++i) {
        if (vectors[i].size() != dimension) {
            cout << "Error: Vectors must be of the same dimension." << endl;
            return {};
        }
    }
    
    // Perform linear combination
    vector<double> result(dimension, 0);
    for (int i = 0; i < vectors.size(); ++i) {
        for (int j = 0; j < dimension; ++j) {
            result[j] += vectors[i][j] * coefficients[i];
        }
    }
    
    return result;
}

// Function to input vectors
vector<vector<double>> inputVectors(int numVectors, int dimension) {
    vector<vector<double>> vectors(numVectors, vector<double>(dimension));
    cout << "Enter the vectors row by row:" << endl;
    for (int i = 0; i < numVectors; ++i) {
        cout << "Vector " << i + 1 << ": ";
        for (int j = 0; j < dimension; ++j) {
            cin >> vectors[i][j];
        }
    }
    return vectors;
}

// Function to input coefficients
vector<double> inputCoefficients(int numCoefficients) {
    vector<double> coefficients(numCoefficients);
    cout << "Enter the coefficients:" << endl;
    for (int i = 0; i < numCoefficients; ++i) {
        cout << "Coefficient " << i + 1 << ": ";
        cin >> coefficients[i];
    }
    return coefficients;
}

// Function to check if a matrix is linearly independent
bool isLinearlyIndependent(const vector<vector<double>>& matrix) {
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
            return false; // If any row becomes all zeros, the matrix is linearly dependent
    }
    return true; // If no row becomes all zeros, the matrix is linearly independent
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

// Function to check if a matrix spans
bool doesSpan(const vector<vector<double>>& matrix) {
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
            return false; // If any row becomes all zeros, the matrix does not span
    }
    return true; // If no row becomes all zeros, the matrix spans
}

// Function to find the dimension of a matrix
int findDimension(const vector<vector<double>>& matrix) {
    vector<vector<double>> copyMatrix = matrix;
    gaussianElimination(copyMatrix);
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int dimension = 0;
    for (int i = 0; i < numRows; ++i) {
        bool allZero = true;
        for (int j = 0; j < numCols; ++j) {
            if (fabs(copyMatrix[i][j]) > 1e-10) {
                allZero = false;
                break;
            }
        }
        if (!allZero)
            ++dimension; // Increment dimension for each non-zero row
    }
    return dimension;
}

// Function to find the basis for the row space
vector<vector<double>> findRowBasis(const vector<vector<double>>& matrix) {
    vector<vector<double>> copyMatrix = matrix;
    gaussianElimination(copyMatrix);
    int numRows = matrix.size();
    int numCols     = matrix[0].size();
    vector<vector<double>> basis;
    for (int i = 0; i < numRows; ++i) {
        bool allZero = true;
        for (int j = 0; j < numCols; ++j) {
            if (fabs(copyMatrix[i][j]) > 1e-10) {
                allZero = false;
                break;
            }
        }
        if (!allZero)
            basis.push_back(matrix[i]); // Add non-zero rows to the basis
    }
    return basis;
}

// Function to print a matrix
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// Main function to display the menu and perform operations based on user choice
int main() {
    int choice;
    vector<vector<double>> matrix;
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Input a matrix" << endl;
        cout << "2. Check if matrix is linearly independent" << endl;
        cout << "3. Check if matrix is linearly dependent" << endl;
        cout << "4. Check if matrix spans" << endl;
        cout << "5. Find dimension of the subspace spanned by the matrix" << endl;
        cout << "6. Find basis for the row space of the matrix" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int numRows, numCols;
                cout << "Enter the number of rows and columns of the matrix: ";
                cin >> numRows >> numCols;
                matrix.resize(numRows, vector<double>(numCols));
                cout << "Enter the matrix elements row by row:" << endl;
                for (int i = 0; i < numRows; ++i) {
                    cout << "Row " << i + 1 << ": ";
                    for (int j = 0; j < numCols; ++j) {
                        cin >> matrix[i][j];
                    }
                }
                break;
            }
            case 2:
                cout << "Matrix is " << (isLinearlyIndependent(matrix) ? "linearly independent." : "linearly dependent.") << endl;
                break;
            case 3:
                cout << "Matrix is " << (isLinearlyDependent(matrix) ? "linearly dependent." : "linearly independent.") << endl;
                break;
            case 4:
                cout << "Matrix " << (doesSpan(matrix) ? "spans." : "does not span.") << endl;
                break;
            case 5:
                cout << "Dimension of the subspace spanned by the matrix is: " << findDimension(matrix) << endl;
                break;
            case 6: {
                vector<vector<double>> rowBasis = findRowBasis(matrix);
                cout << "Basis for the row space:" << endl;
                printMatrix(rowBasis);
                break;
            }
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }
    }
    return 0;
}


