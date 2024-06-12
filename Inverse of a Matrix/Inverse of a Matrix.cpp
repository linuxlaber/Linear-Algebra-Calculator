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

// Function to calculate the determinant of a 2x2 matrix
double determinant2x2(const vector<vector<double>>& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Function to calculate the determinant of a submatrix
double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];
    if (n == 2) return determinant2x2(matrix);

    double det = 0;
    for (int j = 0; j < n; ++j) {
        vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
        for (int i = 1; i < n; ++i) {
            for (int k = 0, col = 0; k < n; ++k) {
                if (k != j) {
                    submatrix[i - 1][col++] = matrix[i][k];
                }
            }
        }
        det += (j % 2 == 0 ? 1 : -1) * matrix[0][j] * determinant(submatrix);
    }
    return det;
}

// Function to calculate the adjoint of a matrix
vector<vector<double>> adjoint(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> adj(n, vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (r != i && c != j) {
                        submatrix[r < i ? r : r - 1][c < j ? c : c - 1] = matrix[r][c];
                    }
                }
            }
            adj[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * determinant(submatrix);
        }
    }

    return adj;
}

// Function to calculate the inverse of a matrix
vector<vector<double>> inverse(const vector<vector<double>>& matrix) {
    double det = determinant(matrix);
    if (det == 0) {
        cout << "Inverse does not exist as determinant is 0." << endl;
        exit(1);
    }

    int n = matrix.size();
    vector<vector<double>> inv(n, vector<double>(n));

    vector<vector<double>> adj = adjoint(matrix);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inv[i][j] = adj[j][i] / det;
        }
    }

    return inv;
}

int main() {
    int n;

    // Input for matrix
    cout << "Enter the order of the matrix: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Calculate the inverse of the matrix
    vector<vector<double>> invMatrix = inverse(matrix);

    // Display step-by-step solution
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    cout << "Inverse of the Matrix:" << endl;
    printMatrix(invMatrix);

    return 0;
}

