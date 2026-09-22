#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void pageHeader() ;
void displayMenu();
double getPrice(int choice);
string getProduct(int choice);
double calculateTotal(double price, int quantity);
double makePayment(double totalPayment);

int main()
{
    int choice, quantity;
    double price;
    double totalPrice;
    double totalPayment = 0;
    double balance;
    string product;

	pageHeader() ;
	cout << endl ;

    do
    {
        displayMenu();

        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            product = getProduct(choice);
            price = getPrice(choice);

            cout << "Enter quantity: ";
            cin >> quantity;

            totalPrice = calculateTotal(price, quantity);
            totalPayment = totalPayment + totalPrice;

            cout << fixed << setprecision(2);
            cout << "Total price for " << quantity << " " ;
            cout << product << " is RM" << totalPrice << endl;
            cout << endl;
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    cout << fixed << setprecision(2);
    cout << "Total payment is RM" << totalPayment << endl;

    balance = makePayment(totalPayment);

    cout << "Thank you, your balance is RM" << balance << endl;

    return 0;
}

//Function to display one-time page header
void pageHeader(){
	cout << "*******************" << endl;
    cout << "Welcome to Mike Shop" << endl;
    cout << "*******************" << endl;
}

// Function to display menu
void displayMenu()
{
    cout << "List of product and price per unit" << endl;
    cout << "1. Soap RM3.50" << endl;
    cout << "2. Shampoo RM6.80" << endl;
    cout << "3. Detergent RM11.20" << endl;
    cout << "4. Payment" << endl;
}


// Function to get product price
double getPrice(int choice)
{
    if (choice == 1)
        return 3.50;
    else if (choice == 2)
        return 6.80;
    else
        return 11.20;
}


// Function to get product name
string getProduct(int choice)
{
    if (choice == 1)
        return "Soap";
    else if (choice == 2)
        return "Shampoo";
    else
        return "Detergent";
}


// Function to calculate total price
double calculateTotal(double price, int quantity)
{
    return price * quantity;
}


// Function to process payment
double makePayment(double totalPayment)
{
    double payment;

    do
    {
        cout << "Your payment: RM";
        cin >> payment;

        if (payment < totalPayment)
        {
            cout << "Not enough make new payment" << endl;
        }

    } while (payment < totalPayment);

    return payment - totalPayment;
}
