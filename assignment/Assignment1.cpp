#include<fstream>
#include<string>
#include<iostream>
#include"item.h"
#include"supermarket.h"

using namespace std;

int admin_menu(supermarket&);

int main()
{
	supermarket store;
	int option;
	
	do 
	{		
		store.space();
		store.border('*', 20);
		cout << "1. CUSTOMER" << endl;
		cout << "2. ADMINISTRATOR" << endl;
		cout << "3. EXIT" << endl;
		store.border('*', 20);

		cout << "\nOption: ";
		cin >> option;
		option = store.checkValidation(option, 1, 3);

		switch (option)
		{
		case 1: 
			system("cls");
			store.place_order();			
			break;

		case 2:
			system("cls");
			option = admin_menu(store);
			break;

		case 3:
			system("cls");
			store.border('@', 20);
			cout << "Good Bye!" << endl;
			store.border('@', 20);
			store.space();
			break;

		default:cout << "Invalid Input...\n";
		}

	} while (option != 3);
	
	cout << "Thanks for using this program" << endl;
	system("pause");
	return 0;
}

int admin_menu(supermarket& store)
{
	system("cls");
	int option;

	store.border('@', 30);	
	cout << "\nPress 1 to DISPLAY ALL itemS";
	cout << "\nPress 2 to MODIFY item";
	cout << "\nPress 3 to GO BACK TO MAIN MENU" << endl;
	store.border('@', 30);

	cout << "\nOption: ";
	cin >> option;
	option = store.checkValidation(option, 1, 3);

	switch (option)
	{
	case 1: store.item_menu();
		break;
	case 2: store.edit_item();
		break;
	case 3: return 0;
		break;

	default:
		cout << "Admin menu error!";
	}

	return option;
}