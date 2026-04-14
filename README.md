# 🏨 Hotel Management System - JIIT Edition

A robust, console-based C++ application designed to manage hotel bookings, user authentication, and personalized guest experiences.

## ✨ Key Features

* **Secure Authentication**: Integrated login system with **hidden password input** (using `_getch()`) and case-insensitive username verification.
* **Smart Recommendations**: A history-based engine that suggests room types based on a user's past stays.
* **Dynamic Billing**: Comprehensive invoice generation including:
    * **Pet-Friendly Logic**: Specific surcharges for Dogs (Rs. 1500) and Cats (Rs. 1000).
    * **Premium Services**: Automatic activation of **Private Chauffeur** or **Courtesy Car** services based on room category.
    * **Validated Inputs**: Secure data entry for fields like Religion (no numbers allowed!) to ensure data integrity.
* **Diverse Room Tiers**: Support for 5 room types ranging from Standard to the luxurious **Penthouse** with panoramic sea views.

## 🛠️ Installation & Setup

1.  **Download**: Place `AuthSystem.cpp`, `main.cpp`, and `final.cpp` into a single project folder.
2.  **Compile**: Open your terminal or IDE (like VS Code) and compile `main.cpp`.
3.  **Run**: Execute the compiled file to launch the system.

## 📂 File Structure

Upon the first run, the system automatically generates:
* `credentials.txt`: Securely stores user IDs and passwords.
* `history_[username].txt`: Tracks the booking patterns of individual guests to power the recommendation engine.

## 🚀 Quick Start
* **Admin Login**: Use `admin123` / `admin321` to access administrative controls.
* **New Users**: Register via the main menu to create your unique guest profile.

---
