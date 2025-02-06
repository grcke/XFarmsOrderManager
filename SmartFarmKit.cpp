#include <iostream>
#include <ctime>  // For time & date in receipt
#include <limits> // For input validation

using namespace std;

int main() {
    int productType, packageType, vegeProduce, kitType, itemException;
    double totalPrice = 0, grandTotal, cash = 0, totalChange;
    int monthlyQuantity, annualQuantity, items = 0, kitQuantity, totalItem = 0, orderNum = 0, billNum = 1234;
    char continueBuying;
    orderNum++;
    billNum++;

    do {
        while (true) {
            cout << "\nPick a product:\n1. Vegetable Subscription\n2. Smart Kit" << endl;
            cout << "\nEnter chosen product: ";
            string input;
            cin >> input;

            if (input == "1" || input == "2") {
                productType = stoi(input);
                break;
            } else {
                cout << "Invalid product, pick again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (productType == 2) {
            while (true) {
                cout << "\nPick a package type:\n1. Farm Kit\n2. Compost Kit\n3. Microgreens Kit" << endl;
                cout << "\nEnter chosen package: ";
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
                    cout << "You've picked Farm Kit\n\nInsert quantity: ";
                    break;
                case 2:
                    cout << "You've picked Compost Kit\n\nInsert quantity: ";
                    break;
                case 3:
                    cout << "You've picked Microgreens Kit\n\nInsert quantity: ";
                    break;
            }

            while (!(cin >> kitQuantity)) {
                cout << "Invalid input. \nPlease enter a numeric quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            totalPrice += kitQuantity * (kitType == 1 ? 19 : kitType == 2 ? 49 : 35);
            totalItem += kitQuantity;
            cout << "\nTotal price: RM" << totalPrice << endl;
        }
        
        else if (productType == 1) {
            while (true) {
                cout << "\nPick a package type:\n1. Monthly Grower\n2. Annual Grower" << endl;
                cout << "Enter chosen package: ";
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

            if (packageType == 1) {
                while (true) {
                    cout << "\nPick a vegetable produce:\n1. Leafy Grower 1\n2. Leafy Grower 2\n3. Leafy Grower 3\n4. Fruity Grower 1\n5. Fruity Grower 2" << endl;
                    cout << "\nEnter a chosen vegetable produce: ";
                    string input;
                    cin >> input;

                    if (input >= "1" && input <= "5") {
                        vegeProduce = stoi(input);
                        break;
                    } else {
                        cout << "Invalid product, pick again!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                switch (vegeProduce) {
                    case 4:
                        cout << "\nInsert quantity: ";
                        while (!(cin >> monthlyQuantity)) {
                            cout << "Invalid input. \nPlease enter a numeric quantity: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        totalPrice += monthlyQuantity * 120;
                        totalItem += monthlyQuantity;
                        break;
                    case 5:
                        cout << "\nInsert quantity: ";
                        while (!(cin >> monthlyQuantity)) {
                            cout << "Invalid input. \nPlease enter a numeric quantity: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        totalPrice += monthlyQuantity * 240;
                        totalItem += monthlyQuantity;
                        break;
                }
                cout << "\nTotal price: RM" << totalPrice << endl;
            }
        }

        grandTotal = totalPrice * 1.06;
        cout << "\nGrand total (incl. 6%): RM" << grandTotal << "\n";
        cout << "\nDo you want to continue buying? (y/n): ";
        cin >> continueBuying;

    } while (continueBuying != 'n' && continueBuying != 'N');

    if (totalItem > 0) {
        cout << "\nEnter cash total: RM";
        cin >> cash;
        while (cash < grandTotal) {
            cout << "Amount entered is not sufficient\nPlease enter amount: RM";
            cin >> cash;
        }
        cout << "\nPRINTING RECEIPT...\nThank you for shopping with us!" << endl;
    } else {
        cout << "\nThank you for shopping with us! Come again!" << endl;
    }
    return 0;
}
