#include <iostream>
#include <string>
#include <cstdlib> // For system() function
#include <conio.h>
using namespace std;

int main()
{
    int choice;

    do {
        cout << "\n        Linear Algebra \n\n";
        cout << "1.) Part 1 (Matrix Calculations) \n";
        cout << "2.) Part 2 (Linear Combinations, Span, Linear Independence and Dependence, etc.) \n";
        cout << "3.) Part 3 (Eigenvalues and Eigenvectors and Linear Transformations) \n";
        cout << "4.) Exit \n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("start \"\" \"C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Matrix Calculations\\Matrix Calculations.exe\"");
                break;
            case 2:
                system("start \"\" \"C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Linear Combinations etc\\Linear Combinations.exe\"");
                break;
            case 3:
                system("start \"\" \"C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Eigenvalues and Eigenvectors\\Eigenvalues and Eigenvectors.exe\"");
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }

        if (choice != 4) {
            cout << "Press any key to return to the menu...";
            _getch();  // Wait for a key press
            system("cls"); // Clear the screen (Windows specific)
        }

    } while (choice != 4);

    return 0;
}

