#include <iostream>
#include<fstream>
#include<time.h>
using std::cout;
using std::endl;
void displayMenu() {
	cout << "\t\t\t===========" << endl;
	cout << "\t\t\tOption Menu" << endl;
	cout << "\t\t\t===========" << endl;
	cout << endl;
	cout << "1.Check balance " << endl;
	cout << "2.Deposit" << endl;
	cout << "3.Withdraw" << endl;
	cout << "4.Print balance report" << endl;
	cout << "5.Exit " << endl;
	cout << "------------------" << endl;


}
int main()
{
	
	int menuOption{};
	double accountBalance{};
	std::fstream report;
	

	

	
	do {
		displayMenu();
		cout << "Choose from the available options: "; std::cin >> menuOption;
		while (menuOption < 1 || menuOption>5) {
			cout << " Invalid menu option"<<endl;
			cout << "Choose from the available options: "; std::cin >> menuOption;
		}
		system("cls");
		switch (menuOption)
		{
		case 1:
			cout << " Your Account Balance is " << accountBalance<<endl;
			break;
		case 2:
			cout << "Input the deposit amount : ";
			double depositAmount;
			std::cin >> depositAmount;
			while (depositAmount <= 0) {
				cout << "\nPlease enter a valid amount : ";
				std::cin >> depositAmount;
			}
			accountBalance += depositAmount;

			cout << "Amount successfully deposited"<<endl;
			break;
		case 3:
			cout << "Input the withdraw amount: ";
			double withdrawAmount;
			std::cin >> withdrawAmount;
			while (withdrawAmount <= 0) {
				cout << "\nPlease enter a valid amount : ";
				std::cin >> withdrawAmount;
			}
			if (withdrawAmount > accountBalance) {
				cout << "Insufficient funds" << endl;
			}
			else {
				accountBalance -= withdrawAmount;
			}
			break;
		case 4:
			report.open("Report.txt", std::ios::out);
			if (report.is_open()) {
				report << "***Bank: Name_of_the_Bank***" << endl;
				report << "***Address:Address_of_the_Bank***" << endl;
				report << "***Vat Number: VAT_number***" << endl;
				report << "------------------------------" << endl;
				report << " Account holder name: Name"<<endl;
				report << "Account balance : " << accountBalance<<endl;
				report << "Time of report generation : " << __DATE__ << " " << __TIME__ << endl;
				report.close();
			}
			cout << "Report Printed Succefully";

		default:
			break;
		}
	} while(menuOption != 5);
	
	return 0;

}
