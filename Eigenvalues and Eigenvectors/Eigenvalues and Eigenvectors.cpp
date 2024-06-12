#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    int choice;
    cout << "1. Eigenvalues and Eigenvectors \n";
    cout << "2. Diagonalize a Matrix \n";
    cout << "3. Check if a Matrix is Symmetric \n";
    cout << "4. Check if a Matrix is Orthogonal \n";

    cin >> choice; // Capture user input

    switch(choice) {
        case 1:
            ShellExecute(NULL, "open", "C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Eigenvalue Solve\\Eigenvalue Solve.exe", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 2:
            ShellExecute(NULL, "open", "C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Diagonalize a Matrix\\Diagonalize a Matrix.exe", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 3:
            ShellExecute(NULL, "open", "C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Symmetric\\Symmetric.exe", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 4:
            ShellExecute(NULL, "open", "C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Orthogonal\\Orthogonal.exe", NULL, NULL, SW_SHOWNORMAL);
            break;
        default:
            cout << "Invalid option selected.";
            break;
    }

    return 0;
}

