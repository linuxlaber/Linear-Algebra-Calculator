#include <iostream>
#include <string>
#include <cstdlib> // For system() function
using namespace std;

int main()
{
    while (true) {
        system("cls");
        cout << "1.) Gaussian Elimination \n";
        cout << "2.) Gauss Jordan Elimination \n";
        cout << "3.) Operations with Matrices \n";
        cout << "4.) Exit \n";

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("start \"\" \"C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Gaussian Elimination\\Gaussian Elimination.exe\"");
                break;
            case 2:
                system("start \"\" \"C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Gauss Jordan Elimination\\Gauss Jordan Elimination.exe\"");
                break;
            case 3:
                system("start \"\" \"C:\\Users\\ElectronicsMan\\OneDrive\\Documents\\Operations with Matrices\\Operations with Matrices.exe\"");
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}

