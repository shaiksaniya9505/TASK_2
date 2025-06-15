#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


void registerUser();
void loginUser();

int main() {
    int choice;

    while (true) {
        cout << "\n===== LOGIN & REGISTRATION SYSTEM =====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Thank you for using the system!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    }

    return 0;
}


void registerUser() {
    string username, password;
    cout << "\n--- User Registration ---" << endl;
    cout << "Enter username: ";
    cin >> username;

    string filename = username + ".txt";

    
    ifstream checkFile(filename.c_str());
    if (checkFile) {
        cout << "User already exists. Please choose a different username." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(filename.c_str());
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "Registration successful! File created: " << filename << endl;
    } else {
        cout << "Error creating user file!" << endl;
    }
}


void loginUser() {
    string username, password, storedUser, storedPass;
    cout << "\n--- User Login ---" << endl;
    cout << "Enter username: ";
    cin >> username;

    string filename = username + ".txt";

    ifstream file(filename.c_str());
    if (!file) {
        cout << "User not found. Please register first." << endl;
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);
    file.close();

    cout << "Enter password: ";
    cin >> password;

    if (username == storedUser && password == storedPass) {
        cout << "Login successful! Welcome, " << username << "." << endl;
    } else {
        cout << "Incorrect password. Try again!" << endl;
    }
}

