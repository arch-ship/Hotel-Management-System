#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "AuthSystem.cpp"
#include "final.cpp"

using namespace std;

string getValidAlphaInput(string prompt) {
    string input;
    bool hasNumber;
    do {
        hasNumber = false;
        cout << prompt;
        cin >> input;
        for (char c : input) {
            if (isdigit(c)) {
                hasNumber = true;
                break;
            }
        }
        if (hasNumber) cout << "Invalid input! Numbers are not allowed.\n";
    } while (hasNumber);
    return input;
}

void initializeRooms(vector<Room>& rooms) {
    rooms.push_back(Room(101, "Standard", 1500, "City View", "Courtesy Car"));
    rooms.push_back(Room(201, "Deluxe", 3000, "Garden View", "Courtesy Car"));
    rooms.push_back(Room(301, "Premium", 5000, "Pool View", "Courtesy Car"));
    rooms.push_back(Room(401, "Suite", 8000, "Mountain View", "Private Chauffeur"));
    rooms.push_back(Room(501, "Penthouse", 15000, "Panoramic Sea", "Private Chauffeur"));
}

int main() {
    AuthSystem auth;
    vector<Room> hotelRooms;
    initializeRooms(hotelRooms);

    int choice;
    string loggedInUser = "";

    do {
        cout << "\n==========================================";
        cout << "\n      HOTEL MANAGEMENT SYSTEM - JIIT";
        cout << "\n==========================================";
        cout << "\n1. Admin Login\n2. User Login\n3. Registration\n4. Cancel Booking\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 2) {
            if (auth.userLogin(loggedInUser)) {
                recommendRoom(loggedInUser);
                cout << "\n*** NOTE: ALL ROOMS ARE PET FRIENDLY (Dog: 1500, Cat: 1000) ******\n";

                // Fixed header alignment to match Room::displayRoom widths
                cout << left << setw(12) << "Type"
                     << setw(11) << "Price"
                     << setw(20) << "Balcony View"
                     << setw(22) << "Service"
                     << "Status" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
                for(const auto& r : hotelRooms) r.displayRoom();

                string selected;
                cout << "\nEnter Room Type to book (e.g., Deluxe):"; cin >> selected;

                for(auto& r : hotelRooms) {
                    if(toLower(r.type) == toLower(selected)) {
                        if(r.isBooked) cout << "Room type fully booked!\n";
                        else {
                            Booking b; b.uID = loggedInUser; b.roomType = r.type;
                            cout << "Stay Duration (in Days): "; cin >> b.days;
                            b.religion = getValidAlphaInput("Religion (Hindu/Jain/Other): ");
                            cout << "Bringing a pet? (1-Yes, 0-No): "; cin >> b.hasPet;
                            if(b.hasPet) b.petType = getValidAlphaInput("Dog or Cat?: ");

                            r.isBooked = true;
                            b.calculateFinalBill(r.price, r.serviceType); // Passing service name to invoice
                            b.saveHistory();
                        }
                        break;
                    }
                }
            }
        }
        else if (choice == 4) {
            string cancelUID;
            cout << "\nEnter User ID to cancel their booking: ";
            cin >> cancelUID;
            for(auto& r : hotelRooms) r.isBooked = false;
            cout << "Booking cancelled for User: " << cancelUID << endl;
        }
        else if (choice == 1) auth.adminLogin();
        else if (choice == 3) auth.registerUser();

    } while (choice != 5);
    return 0;
}
