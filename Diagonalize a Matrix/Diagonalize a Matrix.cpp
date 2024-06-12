// File: diagonalize_matrix.cpp

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

// Function to print a matrix
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to print a vector
void printVector(const Vector& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to multiply two matrices
Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, Vector(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to perform QR decomposition using Gram-Schmidt process
void qrDecomposition(const Matrix& A, Matrix& Q, Matrix& R) {
    int n = A.size();
    Q = Matrix(n, Vector(n, 0.0));
    R = Matrix(n, Vector(n, 0.0));

    for (int k = 0; k < n; ++k) {
        Vector u = A[k];
        for (int j = 0; j < k; ++j) {
            double dotProduct = 0.0;
            for (int i = 0; i < n; ++i) {
                dotProduct += A[i][k] * Q[i][j];
            }
            for (int i = 0; i < n; ++i) {
                u[i] -= dotProduct * Q[i][j];
            }
        }
        double normU = 0.0;
        for (double val : u) {
            normU += val * val;
        }
        normU = sqrt(normU);
        for (int i = 0; i < n; ++i) {
            Q[i][k] = u[i] / normU;
        }
        for (int j = k; j < n; ++j) {
            double dotProduct = 0.0;
            for (int i = 0; i < n; ++i) {
                dotProduct += A[i][j] * Q[i][k];
            }
            R[k][j] = dotProduct;
        }
    }
}

// Function to diagonalize a matrix using QR algorithm
void diagonalize(Matrix& A, Matrix& D, Matrix& P) {
    int n = A.size();
    P = Matrix(n, Vector(n, 0.0));
    for (int i = 0; i < n; ++i) {
        P[i][i] = 1.0;
    }

    const int max_iterations = 100;
    for (int iter = 0; iter < max_iterations; ++iter) {
        Matrix Q, R;
        qrDecomposition(A, Q, R);
        A = multiply(R, Q);
        P = multiply(P, Q);
    }

    D = A;
}

int main() {
    int n;
    cout << "Enter the number of rows and columns of the matrix (n x n): ";
    cin >> n;

    Matrix A(n, Vector(n));
    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    Matrix D, P;
    diagonalize(A, D, P);

    cout << "Diagonal Matrix D:" << endl;
    printMatrix(D);

    cout << "Eigenvector Matrix P:" << endl;
    printMatrix(P);

    return 0;
}

