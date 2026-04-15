#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>

using namespace std;

// Helper function for case-insensitive inputs
string toLower(string data) {
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

// Secure password input
string getHiddenPassword() {
    string password = "";
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 13) break;
        else if (ch == 8) {
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch >= 32 && ch <= 126) {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

class AuthSystem {
public:
    bool adminLogin() {
        string u, p;
        cout << "\nAdmin Username: "; cin >> u;
        cout << "Admin Password: ";
        p = getHiddenPassword();
        if (u == "admin123" && p == "admin321") {
            cout << "Login Successful!\n";
            return true;
        }
        cout << "Invalid Credentials!\n";
        return false;
    }

    bool userLogin(string& loggedInUser) {
        string uid, pass, f_uid, f_pass;
        cout << "\nEnter User ID/Name: ";
        cin >> uid;

        bool userExists = false;
        string matchedPass = "";
        ifstream file("credentials.txt");

        while (file >> f_uid >> f_pass) {
            if (toLower(f_uid) == toLower(uid)) {
                userExists = true;
                matchedPass = f_pass;
                break;
            }
        }
        file.close();

        if (!userExists) {
            cout << "Error: User '" << uid << "' is not registered!\n";
            return false;
        }

        cout << "Enter Password: ";
        pass = getHiddenPassword();

        if (matchedPass == pass) {
            loggedInUser = f_uid;
            return true;
        }

        cout << "Incorrect Password!\n";
        return false;
    }

    bool registerUser(string& loggedInUser) {
        string uid, pass;
        cout << "\nCreate User ID: "; cin >> uid;
        cout << "Create Password: ";
        pass = getHiddenPassword();

        ofstream file("credentials.txt", ios::app);
        file << uid << " " << pass << endl;
        file.close();

        loggedInUser = uid;
        cout << "Registration Successful! Welcome to the system.\n";
        return true;
    }
};

void recommendRoom(string userID) {
    ifstream file("history_" + userID + ".txt");
    if (!file) {
        cout << "\n[System] Welcome! We recommend starting with our 'Deluxe' rooms.\n";
        return;
    }
    string rType, lastType;
    while (file >> rType) { lastType = rType; }
    file.close();
    cout << "\n[System] Welcome back! We suggest the '" << lastType << "' based on your history.\n";
}
