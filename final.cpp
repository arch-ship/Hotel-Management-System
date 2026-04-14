#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

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
        // Use fixed widths to ensure columns stay aligned in the console
        cout << left << setw(12) << type
             << "Rs." << setw(8) << (int)price
             << setw(20) << balconyView
             << setw(22) << serviceType // Adjusted width for better alignment
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
            float petFee = (toLower(petType) == "dog") ? 1500 : 1000;
            totalBill += petFee;
            cout << "Pet Facility Fee: Rs." << petFee << endl;
            cout << "Note: A separate adjacent pet-cabin has been assigned." << endl;
        }

        // Added specific service line to invoice
        cout << "Service: " << serviceUsed << " (Incl. in Price)" << endl;

        if (roomType == "Suite" || roomType == "Penthouse" || basePrice >= 7000) {
            cout << "PREMIUM CLASS: Chauffeur service activated." << endl;
        }

        cout << "Food Preference: " << religion << " menu assigned." << endl;
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
