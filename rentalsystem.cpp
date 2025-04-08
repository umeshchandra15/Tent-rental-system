#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tent {
public:
    string id;
    string size;
    double pricePerDay;
    bool isRented;

    Tent(string tid, string tsize, double price) {
        id = tid;
        size = tsize;
        pricePerDay = price;
        isRented = false;
    }

    void display() {
        cout << "Tent ID: " << id
             << ", Size: " << size
             << ", Price/Day: $" << pricePerDay
             << ", Status: " << (isRented ? "Rented" : "Available") << endl;
    }
};

class TentRentalSystem {
private:
    vector<Tent> tents;

public:
    void addTent(string id, string size, double price) {
        tents.push_back(Tent(id, size, price));
    }

    void showAvailableTents() {
        cout << "\nAvailable Tents:\n";
        for (auto& tent : tents) {
            if (!tent.isRented) {
                tent.display();
            }
        }
    }

    void rentTent(string id, string customerName, int days) {
        for (auto& tent : tents) {
            if (tent.id == id && !tent.isRented) {
                tent.isRented = true;
                double total = tent.pricePerDay * days;
                cout << "\nTent " << id << " rented to " << customerName
                     << " for " << days << " days. Total: $" << total << endl;
                return;
            }
        }
        cout << "Tent not available or invalid ID.\n";
    }

    void returnTent(string id) {
        for (auto& tent : tents) {
            if (tent.id == id && tent.isRented) {
                tent.isRented = false;
                cout << "Tent " << id << " returned successfully.\n";
                return;
            }
        }
        cout << "Invalid Tent ID or not rented.\n";
    }

    void showAllTents() {
        cout << "\nAll Tents:\n";
        for (auto& tent : tents) {
            tent.display();
        }
    }
};

int main() {
    TentRentalSystem system;

    // Adding some sample tents
    system.addTent("T001", "Small", 20.0);
    system.addTent("T002", "Medium", 30.0);
    system.addTent("T003", "Large", 50.0);

    int choice;
    do {
        cout << "\n--- Tent Rental Menu ---\n";
        cout << "1. Show Available Tents\n";
        cout << "2. Rent a Tent\n";
        cout << "3. Return a Tent\n";
        cout << "4. Show All Tents\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            system.showAvailableTents();
        } else if (choice == 2) {
            string id, name;
            int days;
            cout << "Enter Tent ID: ";
            cin >> id;
            cout << "Enter Customer Name: ";
            cin >> name;
            cout << "Enter Number of Days: ";
            cin >> days;
            system.rentTent(id, name, days);
        } else if (choice == 3) {
            string id;
            cout << "Enter Tent ID to return: ";
            cin >> id;
            system.returnTent(id);
        } else if (choice == 4) {
            system.showAllTents();
        } else if (choice == 5) {
            cout << "Thank you for using the system!\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
