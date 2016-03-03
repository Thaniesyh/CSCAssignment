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

		cout << "\n\t*******************************************";
		cout << "\n\t1. CUSTOMER";
		cout << "\n\t2. ADMINISTRATOR";
		cout << "\n\t3. EXIT";
		cout << "\n\t*******************************************";

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
			cout << "\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
			cout << "\n\tGood Bye!";
			cout << "\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
			exit(0);

		default:cout << "Invalid Input...\n";
		}

	}
}