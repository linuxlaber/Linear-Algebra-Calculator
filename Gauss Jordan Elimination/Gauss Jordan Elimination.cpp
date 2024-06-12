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

// Function to convert a matrix to RREF
void toRREF(vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int lead = 0;
    
    for (int r = 0; r < rows; ++r) {
        if (lead >= cols) return;
        int i = r;
        while (matrix[i][lead] == 0) {
            ++i;
            if (i == rows) {
                i = r;
                ++lead;
                if (lead == cols) return;
            }
        }
        
        swap(matrix[i], matrix[r]);
        cout << "Swap row " << i + 1 << " with row " << r + 1 << ":" << endl;
        printMatrix(matrix);
        
        double lv = matrix[r][lead];
        for (int j = 0; j < cols; ++j) {
            matrix[r][j] /= lv;
        }
        cout << "Divide row " << r + 1 << " by " << lv << ":" << endl;
        printMatrix(matrix);
        
        for (int i = 0; i < rows; ++i) {
            if (i != r) {
                lv = matrix[i][lead];
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] -= lv * matrix[r][j];
                }
                cout << "Subtract " << lv << " times row " << r + 1 << " from row " << i + 1 << ":" << endl;
                printMatrix(matrix);
            }
        }
        ++lead;
    }
}

int main() {
    while (true) {
        int rows, cols;
        char continueChoice;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        vector<vector<double>> matrix(rows, vector<double>(cols));

        cout << "Enter the elements of the matrix row by row:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> matrix[i][j];
            }
        }

        cout << "Initial Matrix:" << endl;
        printMatrix(matrix);

        toRREF(matrix);

        cout << "Matrix in RREF:" << endl;
        printMatrix(matrix);

        cout << "Would you like to enter another matrix? (y/n): ";
        cin >> continueChoice;
        if (continueChoice == 'n' || continueChoice == 'N') {
            break;
        }
        system("cls"); // Clear the screen (Windows specific)
    }

    return 0;
}

