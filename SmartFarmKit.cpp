#include <iostream>
#include <ctime> // time&date for receipt area
#include <limits> // the limit header for input validation, avoid infinity looping

using namespace std;

int main() {
    int productType, packageType, vegeProduce, kitType, itemException;
    double totalPrice = 0, grandTotal, cash = 0, totalChange; // Initialize totalPrice to 0
    int monthlyQuantity, annualQuantity, items = 0, kitQuantity, totalItem = 0, orderNum = 0, billNum = 1234; // Initialize totalItem to 0
    char continueBuying, hyphen = 45; // ASCII value for '-'

    orderNum++;
    billNum++;

    do {
        // Validation loop for productType, avoid infinite loop
        while (true) {
            cout << "\nPick a product:\n1. vegetable subscription\n2. smart kit" << endl << "\nEnter chosen product: ";
            string input;
            cin >> input;

            if (input == "1" || input == "2") {
                productType = stoi(input); // Convert the string to an integer
                break;
            } else {
                cout << "Invalid product, pick again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (productType == 2) {
            while (true) {
                cout << "\nPick a package type:\n1. farm kit\n2. compost kit\n3. microgreens kit" << endl << "\nEnter chosen package: ";
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

            if (kitType >= 1 && kitType <= 3) {
                switch (kitType) {
                    case 1:
                        cout << "You've picked Farm Kit" << endl << "\nInsert quantity: ";
                        while (!(cin >> kitQuantity)) {
                            cout << "Invalid input. \nPlease enter a numeric quantity: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        totalPrice += kitQuantity * 19; // Add to total price
                        totalItem += kitQuantity; // Add to total items
                        cout << "\nTotal price: RM" << totalPrice << endl;
                        break;
                    case 2:
                        cout << "You've picked Compost Kit" << endl << "\nInsert quantity: ";
                        while (!(cin >> kitQuantity)) {
                            cout << "Invalid input. \nPlease enter a numeric quantity: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        totalPrice += kitQuantity * 49;
                        totalItem += kitQuantity;
                        cout << "\nTotal price: RM" << totalPrice << endl;
                        break;
                    case 3:
                        cout << "You've picked Microgreens Kit" << endl << "\nInsert quantity: ";
                        while (!(cin >> kitQuantity)) {
                            cout << "Invalid input. \nPlease enter a numeric quantity: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        totalPrice += kitQuantity * 35;
                        totalItem += kitQuantity;
                        cout << "\nTotal price: RM" << totalPrice << endl;
                        break;
                }
            } else {
                cout << "\nInvalid kit, pick again!";
            }
        } else if (productType == 1) {
            while (true) {
                cout << "\nPick a package type:\n1. monthly grower\n2. annual grower\nEnter chosen package: ";
                string input;
                cin >> input;

                if (input == "1" || input == "2") {
                    packageType = stoi(input); // Convert the string to an integer
                    break;
                } else {
                    cout << "Invalid product, pick again!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            if (packageType == 1) {
                while (true) {
                    cout << "\nPick a vegetable produce:\n1. Monthly Grower 1 - Leafy\n2. Monthly Grower 2 - Leafy\n3. Monthly Grower 3 - Leafy\n4. Monthly Grower 1 - Fruity\n5. Monthly Grower 2 - Fruity\n";
                    cout << "\nEnter a chosen vegetable produce: ";
                    string input;
                    cin >> input;

                    if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5") {
                        vegeProduce = stoi(input); // Convert the string to an integer
                        break;
                    } else {
                        cout << "Invalid product, pick again!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                if (vegeProduce >= 1 && vegeProduce <= 5) {
                    switch (vegeProduce) {
                        case 1:
                            cout << "\nYou've picked Monthly Grower 1 - Leafy \nPick items: \n1. Salad lettuces\n2. Hearty Asian greens\n3. Salad & Asian Mix" << endl;
                            cout << "\nEnter chosen items: ";
                            cin >> items;
                            break;
                        case 2:
                            cout << "\nYou've picked Monthly Grower 2 - Leafy \nPick items: \n1. Salad lettuces\n2. Hearty Asian greens\n3. Salad & Asian Mix" << endl;
                            cout << "\nEnter chosen items: ";
                            cin >> items;
                            break;
                        case 3:
                            cout << "\nYou've picked Monthly Grower 3 - Leafy \nPick items: \n1. Salad lettuces\n2. Hearty Asian greens\n3. Salad & Asian Mix" << endl;
                            cout << "\nEnter chosen items: ";
                            cin >> items;
                            break;
                        case 4:
                            cout << "\nYou've picked Monthly Grower 1 - Fruity\nThis package includes: \n-red/yellow capsicums\n-tomatoes/cherry\n-green/red chilis\n-english/cocktail cucumbers" << endl << "\nInsert quantity: ";
                            while (!(cin >> monthlyQuantity)) {
                                cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            totalPrice += monthlyQuantity * 120;
                            totalItem += monthlyQuantity;
                            cout << "\nTotal price: RM" << totalPrice << endl;
                            itemException = 1;
                            break;
                        case 5:
                            cout << "\nYou've picked Monthly Grower 2 - Fruity\nThis package includes: \n-red/yellow capsicums\n-tomatoes/cherry\n-green/red chilis\n-english/cocktail cucumbers" << endl << "\nInsert quantity: ";
                            while (!(cin >> monthlyQuantity)) {
                                cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            totalPrice += monthlyQuantity * 240;
                            totalItem += monthlyQuantity;
                            cout << "\nTotal price: " << totalPrice << endl;
                            itemException = 1;
                            break;
                    }

                    if ((items >= 1 && items <= 3) || (itemException == 1)) {
                        switch (items) {
                            case 1:
                                cout << "\nInsert quantity: ";
                                while (!(cin >> monthlyQuantity)) {
                                    cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                                totalPrice += monthlyQuantity * 105;
                                totalItem += monthlyQuantity;
                                cout << "\nTotal price: RM" << totalPrice << endl;
                                items = 0;
                                break;
                            case 2:
                                cout << "\nInsert quantity: ";
                                while (!(cin >> monthlyQuantity)) {
                                    cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                                totalPrice += monthlyQuantity * 189;
                                totalItem += monthlyQuantity;
                                cout << "\nTotal price: RM" << totalPrice << endl;
                                items = 0;
                                break;
                            case 3:
                                cout << "\nInsert quantity: ";
                                while (!(cin >> monthlyQuantity)) {
                                    cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                                totalPrice += monthlyQuantity * 270;
                                totalItem += monthlyQuantity;
                                cout << "\nTotal price: RM" << totalPrice << endl;
                                items = 0;
                                break;
                        }
                    } else {
                        cout << "\nInvalid item, pick again!";
                    }
                } else {
                    cout << "\nInvalid item, pick again!";
                }
            } else if (packageType == 2) {
                while (true) {
                    cout << "You've picked Monthly Grower 1 - Leafy" << endl;
                    cout << "Pick items:" << endl;
                    cout << "1. Salad lettuces" << endl;
                    cout << "2. Hearty Asian greens" << endl;
                    cout << "3. Salad & Asian Mix" << endl;
                    cout << "Enter chosen items: ";

                    if (cin >> items) {
                        if (items >= 1 && items <= 3) {
                            break; // Valid input, exit the loop
                        }
                    } else {
                        cout << "Invalid item, pick again!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                if (items >= 1 && items <= 3) {
                    switch (items) {
                        case 1:
                            cout << "\nInsert quantity: ";
                            while (!(cin >> annualQuantity)) {
                                cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            totalPrice += annualQuantity * 1200;
                            totalItem += annualQuantity;
                            cout << "\nTotal price: RM" << totalPrice << endl;
                            items = 0;
                            break;
                        case 2:
                            cout << "\nInsert quantity: ";
                            while (!(cin >> annualQuantity)) {
                                cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            totalPrice += annualQuantity * 1200;
                            totalItem += annualQuantity;
                            cout << "\nTotal price: RM" << totalPrice << endl;
                            items = 0;
                            break;
                        case 3:
                            cout << "\nInsert quantity: ";
                            while (!(cin >> annualQuantity)) {
                                cout << "Invalid input. \nPlease enter a numeric quantity: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            totalPrice += annualQuantity * 1200;
                            totalItem += annualQuantity;
                            cout << "\nTotal price: RM" << totalPrice << endl;
                            items = 0;
                            break;
                    }
                } else {
                    cout << "\nInvalid item, pick again!";
                }
            } else {
                cout << "\nInvalid product, pick again!";
            }
        } else {
            cout << "\nInvalid product, pick again!";
        }

        grandTotal = (totalPrice * 0.06) + totalPrice;
        cout << "\nGrand total (incl. 6%): RM" << grandTotal << "\n";
        cout << "\nDo you want to continue buying?\nEnter 'y' to continue, 'n' to exit: ";
        cin >> continueBuying;

    } while (continueBuying != 'n' && continueBuying != 'N'); // Continue buying as long as 'n' or 'N' is not entered

    if (totalItem > 0) {
        cout << "\nEnter cash total: RM";
        cin >> cash;
        while (cash < grandTotal) {
            cout << "Amount entered is not sufficient\nPlease enter amount: RM";
            cin >> cash;
        }
        cout << "\nPRINTING RECEIPT..." << endl;

        // Receipt area
        cout << "\n\n\t\t\tSalad Finger CO." << endl;
        time_t now = time(0);
        char* date_time = ctime(&now);
        cout << "\tdate and time: " << date_time << endl;
        cout << "\tlocation: AREA 51" << endl;
        cout << "\torder number: " << orderNum << endl;
        cout << "\n\t\t\tINVOICE\n" << endl;

        int hyphenCount = 65; // Print 65 '-'
        for (int i = 0; i < hyphenCount; i++) {
            cout << '-';
        }
        cout << endl;

        cout << "\tbill number: " << billNum << "\tstatus: COMPLETED" << endl;

        // Print 65 '-'
        for (int i = 0; i < hyphenCount; i++) {
            cout << '-';
        }
        cout << endl;

        cout << "\t\t\t\tquantity\tprice(RM)" << endl;

        // Print 65 '-'
        for (int i = 0; i < hyphenCount; i++) {
            cout << '-';
        }
        cout << endl;

        cout << "\ttotal:\t\t" << "\t" << totalItem << "\t\t" << totalPrice << endl;

        // Print 65 '-'
        for (int i = 0; i < hyphenCount; i++) {
            cout << '-';
        }
        cout << endl;

        cout << "\t\t\t\tGRAND TOTAL\t" << grandTotal << "\n\t\t\t\t(incl. 6%)" << endl;
        cout << "\t\t\t\tcash\t\t" << cash << endl;
        totalChange = cash - grandTotal;
        cout << "\t\t\t\tchange\t\t" << totalChange << endl;
        cout << "\n\tThank you, please continue to use our service!" << endl;

    } else {
        cout << "\nThank you for shopping with us! come again!";
    }

    return 0;
}
