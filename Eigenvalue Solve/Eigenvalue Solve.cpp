#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

// Function to multiply a matrix by a vector
Vector multiply(const Matrix& A, const Vector& x) {
    int n = A.size();
    Vector result(n, 0.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i] += A[i][j] * x[j];
        }
    }
    return result;
}

// Function to calculate the norm of a vector
double norm(const Vector& v) {
    double sum = 0.0;
    for (double val : v) {
        sum += val * val;
    }
    return sqrt(sum);
}

// Function to normalize a vector
void normalize(Vector& v) {
    double v_norm = norm(v);
    for (double& val : v) {
        val /= v_norm;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

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

    Vector b(n);

    // Initialize the vector b with random values
    for (int i = 0; i < n; ++i) {
        b[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    const int max_iterations = 1000;
    const double tolerance = 1e-10;
    double eigenvalue = 0.0;
    Vector eigenvector;

    for (int iter = 0; iter < max_iterations; ++iter) {
        eigenvector = multiply(A, b);
        eigenvalue = norm(eigenvector);
        normalize(eigenvector);
        if (norm(b) < tolerance) {
            break;
        }
        b = eigenvector;
    }

    // Output the largest eigenvalue
    cout << "Largest Eigenvalue: " << eigenvalue << endl;
    
    // Output the corresponding eigenvector
    cout << "Eigenvector: [";
    for (size_t i = 0; i < eigenvector.size(); ++i) {
        cout << eigenvector[i];
        if (i < eigenvector.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

