#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// Updated Helper: Turns "hiNDU" into "Hindu"
string capitalize(string data) {
    if (data.empty()) return data;
    for (int i = 0; i < data.length(); i++) {
        data[i] = tolower(data[i]);
    }
    data[0] = toupper(data[0]);
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

    void calculateFinalBill(float basePrice, string service, bool isFirstBooking) {
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

        cout << "Service: " << serviceUsed << " (Included in Price)" << endl;

        if (roomType == "Suite" || roomType == "Penthouse" || basePrice >= 7000) {
            cout << "PREMIUM CLASS: Chauffeur service activated." << endl;
        }

        if (isFirstBooking) {
            float discount = totalBill * 0.20;
            totalBill -= discount;
            cout << "First Booking Discount (20%): -Rs." << discount << endl;
        }

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
