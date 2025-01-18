#include <iostream>
#include <ctime> // time & date for receipt area
#include <limits> // input validation, avoid infinite looping
using namespace std;

int main() {
    int productType, packageType, vegeProduce, kitType, itemException;
    double totalPrice = 0, grandTotal, cash = 0, totalChange;
    int monthlyQuantity, annualQuantity, items = 0, kitQuantity, totalItem = 0, orderNum = 0, billNum = 1234;
    char continueBuying, hyphen = 45; // ASCII value for '-'
    orderNum++;
    billNum++;

    do {
        // Validation loop for productType
        while (true) {
            cout << "\nPick a product:\n1. Vegetable subscription\n2. Smart kit" << endl
                 << "\nEnter chosen product: ";
            string input;
            cin >> input;

            if (input == "1" || input == "2") {
                productType = stoi(input); // Convert string to integer
                break;
            } else {
                cout << "Invalid product, pick again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (productType == 2) { // Smart Kit
            while (true) {
                cout << "\nPick a package type:\n1. Farm kit\n2. Compost kit\n3. Microgreens kit" << endl
                     << "\nEnter chosen package: ";
                string input;
                cin >> input;

                if (input == "1" || input == "2" || input == "3") {
                    kitType = stoi(input);
                    break;
                } else {
                    cout << "Invalid item, pick again!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            switch (kitType) {
                case 1:
                    cout << "You've picked Farm Kit" << endl << "\nInsert quantity: ";
                    while (!(cin >> kitQuantity)) {
                        cout << "Invalid input. Please enter a numeric quantity: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    totalPrice += kitQuantity * 19;
                    totalItem += kitQuantity;
                    break;
                case 2:
                    cout << "You've picked Compost Kit" << endl << "\nInsert quantity: ";
                    while (!(cin >> kitQuantity)) {
                        cout << "Invalid input. Please enter a numeric quantity: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    totalPrice += kitQuantity * 49;
                    totalItem += kitQuantity;
                    break;
                case 3:
                    cout << "You've picked Microgreens Kit" << endl << "\nInsert quantity: ";
                    while (!(cin >> kitQuantity)) {
                        cout << "Invalid input. Please enter a numeric quantity: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    totalPrice += kitQuantity * 35;
                    totalItem += kitQuantity;
                    break;
                default:
                    cout << "\nInvalid kit, pick again!";
            }
        } else if (productType == 1) { // Vegetable Subscription
            while (true) {
                cout << "\nPick a package type:\n1. Monthly grower\n2. Annual grower\nEnter chosen package: ";
                string input;
                cin >> input;

                if (input == "1" || input == "2") {
                    packageType = stoi(input);
                    break;
                } else {
                    cout << "Invalid product, pick again!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            if (packageType == 1) { // Monthly grower
                while (true) {
                    cout << "\nPick a vegetable produce:\n1. Monthly Grower 1 - Leafy\n2. Monthly Grower 2 - Leafy\n3. Monthly Grower 3 - Leafy\n4. Monthly Grower 1 - Fruity\n5. Monthly Grower 2 - Fruity\nEnter chosen vegetable produce: ";
                    string input;
                    cin >> input;

                    if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5") {
                        vegeProduce = stoi(input);
                        break;
                    } else {
                        cout << "Invalid product, pick again!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                switch (vegeProduce) {
                    case 1:
                        cout << "You've picked Monthly Grower 1 - Leafy" << endl << "\nPick items:\n1. Salad lettuces\n2. Hearty Asian greens\n3. Salad & Asian Mix" << endl << "\nEnter chosen items: ";
                        cin >> items;
                        break;
                    case 4:
                        cout << "You've picked Monthly Grower 1 - Fruity" << endl << "\nInsert quantity: ";
                        while (!(cin >> monthlyQuantity)) {
                            cout << "Invalid input. Please enter a numeric quantity: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        totalPrice += monthlyQuantity * 120;
                        totalItem += monthlyQuantity;
                        break;
                    default:
                        cout << "\nInvalid item, pick again!";
                }
            }
        }

        grandTotal = (totalPrice * 0.06) + totalPrice;
        cout << "\nGrand total (incl. 6%): RM" << grandTotal << "\n";
        cout << "\nDo you want to continue buying? Enter 'y' to continue, 'n' to exit: ";
        cin >> continueBuying;

    } while (continueBuying != 'n' && continueBuying != 'N');

    if (totalItem > 0) {
        cout << "\nEnter cash total: RM";
        cin >> cash;

        while (cash < grandTotal) {
            cout << "Amount entered is not sufficient. Please enter amount: RM";
            cin >> cash;
        }

        cout << "\nPRINTING RECEIPT...\n";
        cout << "\tThank you for shopping with us!";
    }

    return 0;
}
