#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// Helper function to capitalize the first letter of a string
string capitalize(string data) {
    if (!data.empty()) {
        data[0] = toupper(data[0]);
    }
    return data;
}

class Room {
public:
    int roomNo;
    string type;
    float price;
    bool isBooked;
    string balconyView;
    string serviceType;

    Room(int r, string t, float p, string view, string service)
        : roomNo(r), type(t), price(p), isBooked(false), balconyView(view), serviceType(service) {}

    void displayRoom() const {
        // Maintained fixed widths for console alignment
        cout << left << setw(12) << type
             << "Rs." << setw(8) << (int)price
             << setw(20) << balconyView
             << setw(22) << serviceType
             << (isBooked ? "[BOOKED]" : "[Available]") << endl;
    }
};

class Booking {
public:
    string uID, roomType, religion, petType, serviceUsed;
    int days;
    float totalBill;
    bool hasPet;

    void calculateFinalBill(float basePrice, string service) {
        totalBill = basePrice * days;
        serviceUsed = service;

        cout << "\n----------- INVOICE -----------" << endl;
        cout << "Guest ID: " << uID << endl;
        cout << "Room: " << roomType << " (" << days << " days)" << endl;
        cout << "Base Fare: Rs." << basePrice * days << endl;

        if (hasPet) {
            // Logic for specific pet charges
            float petFee = (toLower(petType) == "dog") ? 1500 : 1000;
            totalBill += petFee;
            cout << "Pet Facility Fee: Rs." << petFee << endl;
            cout << "Note: A separate adjacent pet-cabin has been assigned." << endl;
        }

        // Displaying specific service assigned to the room type
        cout << "Service: " << serviceUsed << " (Included in Price)" << endl;

        if (roomType == "Suite" || roomType == "Penthouse" || basePrice >= 7000) {
            cout << "PREMIUM CLASS: Chauffeur service activated." << endl;
        }

        // Updated to display capitalized food preference
        cout << "Food Preference: " << capitalize(religion) << " menu assigned." << endl;

        cout << "-------------------------------" << endl;
        cout << "TOTAL PAYABLE: Rs." << totalBill << endl;
        cout << "-------------------------------\n" << endl;
    }

    void saveHistory() {
        ofstream hFile("history_" + uID + ".txt", ios::app);
        hFile << roomType << endl;
        hFile.close();
    }
};
