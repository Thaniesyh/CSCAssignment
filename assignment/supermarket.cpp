#include<iostream>
#include<string>
#include"supermarket.h"
#include<fstream>

using namespace std;

void supermarket::save_item() {
	fp.open("Stock.txt", ios::out | ios::app);
	produc.create_item();
	fp.write((char*)&produc, sizeof(item));
	fp.close();
	cout << endl << endl << "The item Has Been Sucessfully Created...";
	getchar();
}
void supermarket::show_all_item()
{
	system("cls");
	cout << endl << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << endl << "\t\tRECORDS.";
	cout << endl << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	fp.open("Stock.txt", ios::in);
	while (fp.read((char*)&produc, sizeof(item)))
	{
		produc.show_item();
		cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
		getchar();
	}
	fp.close();
}
void supermarket::display_record(int num)
{
	bool found = false;
	fp.open("Stock.txt", ios::in);
	while (fp.read((char*)&produc, sizeof(item)))
	{
		if (produc.getitem() == num)
		{
			system("cls");
			produc.show_item();
			found = true;
		}
	}

	fp.close();
	if (found == true)
		cout << "\n\nNo record found";
	getchar();
}
void supermarket::edit_item()
{
	int num;
	bool found = false;
	system("cls");
	cout << endl << endl << "\tPlease Enter The item #: ";
	cin >> num;

	fp.open("Stock.txt", ios::in | ios::out);
	while (fp.read((char*)&produc, sizeof(item)) && found == false)
	{
		if (produc.getitem() == num)
		{
			produc.show_item();
			cout << "\nPlease Enter The New Details of item: " << endl;
			produc.create_item();
			int pos = -1 * sizeof(produc);
			fp.seekp(pos, ios::cur);
			fp.write((char*)&produc, sizeof(item));
			cout << endl << endl << "\t Record Successfully Updated...";
			found = true;
		}
	}
	fp.close();
	if (found == false)
		cout << endl << endl << "Record Not Found...";
	getchar();
}
void supermarket::delete_item()
{
	int num;
	system("cls");
	cout << endl << endl << "Please Enter The item #: ";
	cin >> num;
	fp.open("Stock.txt", ios::in | ios::out);
	fstream fp2;
	fp2.open("Temp.dat", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&produc, sizeof(item)))
	{
		if (produc.getitem() != num)
		{
			fp2.write((char*)&produc, sizeof(item));
		}
	}
	fp2.close();
	fp.close();
	remove("Stock.txt");
	rename("Temp.dat", "Stock.txt");
	cout << endl << endl << "\tRecord Deleted...";
	getchar();
}
void supermarket::item_menu()
{
	system("cls");
	fp.open("Stock.txt", ios::in);

	cout << endl << endl << "\t\titem MENU\n\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "P.NO.\t\tNAME\t\tPRICE\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	while (fp.read((char*)&produc, sizeof(item)))
	{
		cout << produc.getitem() << "\t\t" << produc.getName() << "\t\t" << produc.getPrice() << endl;
	}
	fp.close();
}

void supermarket::place_order()
{
	int order_arr[50], quan[50], c = 0;
	float amt, damt, total = 0;
	char ch = 'Y';
	item_menu();
	cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\n PLACE YOUR ORDER";
	cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	do {
		cout << "\n\nEnter The item #: ";
		cin >> order_arr[c];
		cout << "\nQuantity: ";
		cin >> quan[c];
		c++;
		cout << "\nDo You Want To Order Another item ? (y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << "\n\nThank You...";
	getchar();
	system("cls");
	cout << "\n\n********************************INVOICE************************\n";
	cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
	for (int x = 0; x <= c; x++)
	{
		fp.open("Stock.txt", ios::in);
		fp.read((char*)&produc, sizeof(item));
		while (!fp.eof())
		{
			if (produc.getitem() == order_arr[x])
			{
				amt = produc.getPrice()*quan[x];
				damt = amt - (amt*produc.getDiscount() / 100);
				cout << "\n" << order_arr[x] << "\t" << produc.getName() << "\t" << quan[x] << "\t\t" << produc.getPrice() << "\t" << amt << "\t\t" << damt;
				total += damt;
			}
			fp.read((char*)&produc, sizeof(item));
		}
		fp.close();
	}
	cout << "\n\n\t\t\t\t\tTOTAL = " << total;
	getchar();
}
void supermarket::market_items()
{
	system("cls");

}
void supermarket::admin_menu()
{
	system("cls");
	int option;
	cout << "\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\n\tPress 1 to CREATE item";
	cout << "\n\tPress 2 to DISPLAY ALL itemS";
	cout << "\n\tPress 3 to QUERY ";
	cout << "\n\tPress 4 to MODIFY item";
	cout << "\n\tPress 5 to DELETE item";
	cout << "\n\tPress 6 to GO BACK TO MAIN MENU";
	cout << "\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout << "\n\n\tOption: ";
	cin >> option;
	switch (option)
	{
	case 1: system("cls");
		save_item();
		break;

	case 2: show_all_item();
		break;

	case 3:
		int num;
		system("cls");
		cout << "\n\n\tPlease Enter The item Number: ";
		cin >> num;
		display_record(num);
		break;

	case 4: edit_item();
		break;

	case 5: delete_item();
		break;

	case 6: system("cls");
		break;

	default:admin_menu();
	}
 }
