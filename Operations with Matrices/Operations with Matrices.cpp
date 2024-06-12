#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Function to check if two matrices are equal
bool areMatricesEqual(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // If dimensions of matrices are different, they can't be equal
    if (rows1 != rows2 || cols1 != cols2) {
        return false;
    }

    // Check each element for equality
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }

    // If all elements are equal, matrices are equal
    return true;
}

// Function to add two matrices
vector<vector<double>> addMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<double>> subtractMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

// Function to perform scalar multiplication on a matrix
vector<vector<double>> scalarMultiplication(const vector<vector<double>>& matrix, double scalar) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<double>> result(rows, vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

// Function to perform matrix multiplication
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    vector<vector<double>> result(rows1, vector<double>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
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

int main()
{
    cout << "1.) Check if both matrices are equal \n";
cout << "2.) Add matrices \n";
cout << "3.) Subtract matrices \n";
cout << "4.) Scalar Multiplication \n";
cout << "5.) Matrix Multiplication \n";
cout << "6.) Transpose of a Matrix \n";
cout << "7.) Inverse of a Matrix \n";

while (true) {
    int choice;
    cout << "Enter your choice (1-7): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int rows1, cols1, rows2, cols2;

            // Input for matrix 1
            cout << "Enter the number of rows for matrix 1: ";
            cin >> rows1;
            cout << "Enter the number of columns for matrix 1: ";
            cin >> cols1;

            vector<vector<double>> matrix1(rows1, vector<double>(cols1));

            cout << "Enter the elements of matrix 1 row by row:" << endl;
            for (int i = 0; i < rows1; ++i) {
                for (int j = 0; j < cols1; ++j) {
                    cin >> matrix1[i][j];
                }
            }

            // Input for matrix 2
            cout << "Enter the number of rows for matrix 2: ";
            cin >> rows2;
            cout << "Enter the number of columns for matrix 2: ";
            cin >> cols2;

            vector<vector<double>> matrix2(rows2, vector<double>(cols2));

            cout << "Enter the elements of matrix 2 row by row:" << endl;
            for (int i = 0; i < rows2; ++i) {
                for (int j = 0; j < cols2; ++j) {
                    cin >> matrix2[i][j];
                }
            }

            // Check if matrices are equal
            if (areMatricesEqual(matrix1, matrix2)) {
                cout << "Matrices are equal." << endl;
            } else {
                cout << "Matrices are not equal." << endl;
            }
            break;
        }
        case 2: {
            int rows, cols;

            // Input for matrix 1
            cout << "Enter the number of rows for matrix 1: ";
            cin >> rows;
            cout << "Enter the number of columns for matrix 1: ";
            cin >> cols;

            vector<vector<double>> matrix1(rows, vector<double>(cols));

            cout << "Enter the elements of matrix 1 row by row:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> matrix1[i][j];
                }
            }

            // Input for matrix 2
            cout << "Enter the number of rows for matrix 2: ";
            cin >> rows;
            cout << "Enter the number of columns for matrix 2: ";
            cin >> cols;

            vector<vector<double>> matrix2(rows, vector<double>(cols));

            cout << "Enter the elements of matrix 2 row by row:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> matrix2[i][j];
                }
            }

            // Check if matrices can be added
            if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
                cout << "Matrices cannot be added. Dimensions are not equal." << endl;
                return 0;
            }

            // Add matrices
            vector<vector<double>> result = addMatrices(matrix1, matrix2);

            // Display step-by-step solution
            cout << "Matrix 1:" << endl;
            for (const auto& row : matrix1) {
                for (double elem : row) {
                    cout << setw(10) << fixed << setprecision(4) << elem << " ";
                }
                cout << endl;
            }

            cout << "Matrix 2:" << endl;
            for (const auto& row : matrix2) {
                for (double elem : row) {
                    cout << setw(10) << fixed << setprecision(4) << elem << " ";
                }
                cout << endl;
            }

            cout << "Result of adding Matrix 1 and Matrix 2:" << endl;
            for (const auto& row : result) {
                for (double elem : row) {
                    cout << setw(10) << fixed << setprecision(4) << elem << " ";
                }
                cout << endl;
            }

            break;
        }
        case 3: {
            int rows, cols;

            // Input for matrix 1
            cout << "Enter the number of rows for matrix 1: ";
            cin >> rows;
            cout << "Enter the number of columns for matrix 1: ";
            cin >> cols;

            vector<vector<double>> matrix1(rows, vector<double>(cols));

            cout << "Enter the elements of matrix 1 row by row:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> matrix1[i][j];
                }
            }

            // Input for matrix 2
            cout << "Enter the number of rows for matrix 2: ";
            cin >> rows;
            cout << "Enter the number of columns for matrix 2: ";
            cin >> cols;

            vector<vector<double>> matrix2(rows, vector<double>(cols));

            cout << "Enter the elements of matrix 2 row by row:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> matrix2[i][j];
                }
            }

            // Check if matrices can be subtracted
            if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
                cout << "Matrices cannot be subtracted. Dimensions are not equal." << endl;
                return 0;
            }

            // Subtract matrices
            vector<vector<double>> result = subtractMatrices(matrix1, matrix2);

            // Display step-by-step solution
            cout << "Matrix 1:" << endl;
            for (const auto& row : matrix1) {
                for (double elem : row) {
                    cout << setw(10) << fixed << setprecision(4) << elem << " ";
                }
                cout << endl;
            }

            cout << "Matrix 2:" << endl;
            for (const auto& row : matrix2) {
                for (double elem : row) {
                    cout << setw(10) << fixed << setprecision(4) << elem << " ";
                }
                cout << endl;
            }

            cout << "Result of subtracting Matrix 2 from Matrix 1:" << endl;
            for (const auto& row : result) {
                for (double elem : row) {
                    cout <<  setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                break;
            }
            case 4: {
                int rows, cols;
                double scalar;

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

                // Input for scalar
                cout << "Enter the scalar value: ";
                cin >> scalar;

                // Perform scalar multiplication
                vector<vector<double>> result = scalarMultiplication(matrix, scalar);

                // Display step-by-step solution
                cout << "Original Matrix:" << endl;
                for (const auto& row : matrix) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                cout << "Scalar Multiplication with " << scalar << ":" << endl;
                for (const auto& row : result) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                break;
            }
            case 5: {
                int rows1, cols1, rows2, cols2;

                // Input for matrix 1
                cout << "Enter the number of rows for matrix 1: ";
                cin >> rows1;
                cout << "Enter the number of columns for matrix 1: ";
                cin >> cols1;

                vector<vector<double>> matrix1(rows1, vector<double>(cols1));

                cout << "Enter the elements of matrix 1 row by row:" << endl;
                for (int i = 0; i < rows1; ++i) {
                    for (int j = 0; j < cols1; ++j) {
                        cin >> matrix1[i][j];
                    }
                }

                // Input for matrix 2
                cout << "Enter the number of rows for matrix 2: ";
                cin >> rows2;
                cout << "Enter the number of columns for matrix 2: ";
                cin >> cols2;

                vector<vector<double>> matrix2(rows2, vector<double>(cols2));

                cout << "Enter the elements of matrix 2 row by row:" << endl;
                for (int i = 0; i < rows2; ++i) {
                    for (int j = 0; j < cols2; ++j) {
                        cin >> matrix2[i][j];
                    }
                }

                // Check if matrices can be multiplied
                if (cols1 != rows2) {
                    cout << "Matrices cannot be multiplied. Number of columns in matrix 1 must be equal to number of rows in matrix 2." << endl;
                    return 0;
                }

                // Perform matrix multiplication
                vector<vector<double>> result = matrixMultiplication(matrix1, matrix2);

                // Display step-by-step solution
                cout << "Matrix 1:" << endl;
                for (const auto& row : matrix1) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                cout << "Matrix 2:" << endl;
                for (const auto& row : matrix2) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                cout << "Result of Matrix 1 multiplied by Matrix 2:" << endl;
                for (const auto& row : result) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                break;
            }
            case 6: {
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
                for (const auto& row : matrix) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                cout << "Transpose of the Matrix:" << endl;
                for (const auto& row : result) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                break;
            }
            case 7: {
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
                for (const auto& row : matrix) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                cout << "Inverse of the Matrix:" << endl;
                for (const auto& row : invMatrix) {
                    for (double elem : row) {
                        cout << setw(10) << fixed << setprecision(4) << elem << " ";
                    }
                    cout << endl;
                }

                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                break;
        }
    }

    return 0;
}



