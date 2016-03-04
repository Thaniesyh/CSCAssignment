#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include"item.h"
#include"supermarket.h"
using namespace std;



int main()
{
	supermarket store;
	int option;

	for (;;)
	{

		store.border('*', 20);
		cout << "1. CUSTOMER" << endl;
		cout << "2. ADMINISTRATOR" << endl;
		cout << "3. EXIT" << endl;
		store.border('*', 20);

		cout << "\n\tOption: ";
		cin >> option;

		switch (option)
		{
		case 1: system("cls");
			store.place_order();
			getchar();
			break;

		case 2: store.admin_menu();
			break;

		case 3:
			store.border('@', 20);
			cout << "Good Bye!" << endl;
			store.border('@', 20);
			exit(0);

		default:cout << "Invalid Input...\n";
		}

	}
}