// File: check_orthogonal.cpp

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<double>> Matrix;

// Function to compute the transpose of a matrix
Matrix transpose(const Matrix& A) {
    int n = A.size();
    Matrix T(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            T[j][i] = A[i][j];
        }
    }
    return T;
}

// Function to multiply two matrices
Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to check if a matrix is an identity matrix
bool isIdentity(const Matrix& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j && abs(A[i][j] - 1.0) > 1e-9) {
                return false;
            }
            if (i != j && abs(A[i][j]) > 1e-9) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a matrix is orthogonal
bool isOrthogonal(const Matrix& A) {
    Matrix At = transpose(A);
    Matrix product = multiply(A, At);
    return isIdentity(product);
}

int main() {
    int n;
    cout << "Enter the number of rows and columns of the matrix (n x n): ";
    cin >> n;

    Matrix A(n, vector<double>(n));
    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    if (isOrthogonal(A)) {
        cout << "The matrix is orthogonal." << endl;
    } else {
        cout << "The matrix is not orthogonal." << endl;
    }

    return 0;
}

