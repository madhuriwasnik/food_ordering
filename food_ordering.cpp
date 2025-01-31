#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Structure to represent a menu item
struct MenuItem {
    int id;
    string name;
    double price;
};

// Structure to represent an order
struct Order {
    int itemId;
    int quantity;
};

// Class to handle the ordering system
class FoodOrderingSystem {
private:
    map<int, MenuItem> menu;
    vector<Order> orders;
    double totalPrice = 0.0;

public:
    // Constructor to initialize menu with prices in INR
    FoodOrderingSystem() {
        menu[1] = {1, "Pizza", 199.00};
        menu[2] = {2, "Burger", 129.00};
        menu[3] = {3, "Pasta", 179.00};
        menu[4] = {4, "Soda", 49.00};
    }

    // Function to display menu
    void displayMenu() {
        cout << "\n------ Menu ------\n";
        for (const auto& item : menu) {
            cout << item.second.id << ". " << item.second.name << "- Rs."<< item.second.price << "\n";
        }
        cout << "-------------------\n";
    }

    // Function to take orders
    void takeOrder() {
        int itemId, quantity;
        char choice;

        do {
            cout << "Enter item ID to order: ";
            cin >> itemId;
            if (menu.find(itemId) == menu.end()) {
                cout << "Invalid item ID! Please try again.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> quantity;

            orders.push_back({itemId, quantity});
            totalPrice += menu[itemId].price * quantity;

            cout << "Add another item? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

    // Function to display the order summary
    void displayOrderSummary() {
        cout << "\n------ Order Summary ------\n";
        for (const auto& order : orders) {
            cout << menu[order.itemId].name << " x " << order.quantity << " - Rs." 
                 << menu[order.itemId].price * order.quantity << "\n";
        }
        cout << "Total Price: Rs." << totalPrice << "\n";
    }

    // Function to process payment
    void processPayment() {
        double amount;
        cout << "\nTotal Amount Due: Rs." << totalPrice << "\n";
        cout << "Enter amount to pay: ";
        cin >> amount;

        if (amount >= totalPrice) {
            cout << "Payment successful! Change: Rs." << amount - totalPrice << "\n";
            cout << "Order confirmed! Thank you for ordering.\n";
        } else {
            cout << "Insufficient amount! Please retry.\n";
        }
    }
};

// Main function
int main() {
    FoodOrderingSystem system;
    cout << "Welcome to the Online Food Ordering System!\n";

    system.displayMenu();
    system.takeOrder();
    system.displayOrderSummary();
    system.processPayment();

    return 0;
}
