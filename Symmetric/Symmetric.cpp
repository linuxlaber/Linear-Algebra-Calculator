// File: check_symmetric.cpp

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrix;

// Function to check if a matrix is symmetric
bool isSymmetric(const Matrix& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != A[j][i]) {
                return false;
            }
        }
    }
    return true;
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

    if (isSymmetric(A)) {
        cout << "The matrix is symmetric." << endl;
    } else {
        cout << "The matrix is not symmetric." << endl;
    }

    return 0;
}

