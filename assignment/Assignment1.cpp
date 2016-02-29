#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>


using namespace std;

class item
{
	int item_number, item_stock;
	char item_name[50], item_info[50], market_name[50];
	float item_price, item_quantity, item_weight, item_discount, money;

public:

	void create_item()
	{
		cout << endl << "Please Enter The item Number: ";
		cin >> item_number;
		cout << endl << "Please Enter The Name of The item: ";
		cin.ignore();
		cin.getline(item_name, 50);
		cout << endl << "Please Enter Quantity of The item: ";
		cin >> item_quantity;
		cout << endl << "Please Enter The Price of The item: ";
		cin >> item_price;
		cout << endl << "Please Enter The Weight of The item: ";
		cin >> item_weight;
		cout << endl << "Please Enter Description of The item: ";
		cin.ignore();
		cin.getline(item_info, 50);
		cout << endl << "Please Enter The Discount (%): ";
		cin >> item_discount;
	}

	void show_item()
	{
		cout << endl << "No" << "Name" << "Quantity" << "Price" << "Weight" << "Info";
		cout << endl << item_number << ":" << item_name << ":" << item_quantity << ":" << item_price << ":" << item_weight << ":" << item_info << ":" << item_discount;
	}
	void create_market()
	{
		cout << "Enter market's name" << endl;
		cin >> market_name;
		cout << "Enter market's money" << endl;
		cin >> money;
	}

	void show_marketinfo()
	{
		cout << endl << "Market Name" << "Amount of item" << "Money own";
		cout << endl << market_name << ":" << item_stock << ":" << money << ":";
	}

	int getitem()
	{
		return item_number;
	}

	int getQuantity() {
		return item_quantity;
	}

	float getPrice()
	{
		return item_price;
	}

	char* getName()
	{
		return item_name;
	}

	float getDiscount()
	{
		return item_discount;
	}

	float getWeight() {
		return item_weight;
	}

	char* getInfo() {
		return item_info;
	}
};



fstream fp;
item produc;


void save_item()
{
	fp.open("itemstorage.txt", ios::out | ios::app);
	produc.create_item();
	fp.write((char*)&produc, sizeof(item));
	fp.close();
	cout << endl << endl << "The item Has Been Sucessfully Created...";
	getchar();
}


void show_all_item()
{
	system("cls");
	cout << endl << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << endl << "\t\tRECORDS.";
	cout << endl << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	fp.open("itemstorage.txt", ios::in);
	while (fp.read((char*)&produc, sizeof(item)))
	{
		produc.show_item();
		cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
		getchar();
	}
	fp.close();
}


void display_record(int num)
{
	bool found = false;
	fp.open("itemstorage.txt", ios::in);
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



void edit_item()
{
	int num;
	bool found = false;
	system("cls");
	cout << endl << endl << "\tPlease Enter The item #: ";
	cin >> num;

	fp.open("itemstorage.txt", ios::in | ios::out);
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


void delete_item()
{
	int num;
	system("cls");
	cout << endl << endl << "Please Enter The item #: ";
	cin >> num;
	fp.open("itemstorage.txt", ios::in | ios::out);
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
	remove("itemstorage.txt");
	rename("Temp.dat", "itemstorage.txt");
	cout << endl << endl << "\tRecord Deleted...";
	getchar();
}


void item_menu()
{
	system("cls");
	fp.open("itemstorage.txt", ios::in);

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



void place_order()
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
		fp.open("itemstorage.txt", ios::in);
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

void market_items()
{
	system("cls");

}



void admin_menu()
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


int main(int argc, char *argv[])
{
	system("cls");
	system("color 05");
	cout << "\t\t\t\t*\t*";
	cout << "\t\t\t\t**\t**";
	cout << "\t\t\t\t***\t***";
	cout << "\t\t\t\t****\t****";
	cout << "\t\t\t\t*****\t*****";
	cout << "\t\t\t\t******\t******";
	cout << "\t\t\t\t*******\t*******";
	cout << "\t\t\t\t*******\t*******";
	cout << "\t\t\t\t******\t******";
	cout << "\t\t\t\t*****\t*****";
	cout << "\t\t\t\t****\t****";
	cout << "\t\t\t\t***\t***";
	cout << "\t\t\t\t**\t**";
	cout << "\t\t\t\t*\t*";
	int option;

	for (;;)
	{

		cout << "\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t1. CUSTOMER";
		cout << "\n\t2. ADMINISTRATOR";
		cout << "\n\t3. EXIT";
		cout << "\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

		cout << "\n\tOption: ";
		cin >> option;

		switch (option)
		{
		case 1: system("cls");
			place_order();
			getchar();
			break;

		case 2: admin_menu();
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