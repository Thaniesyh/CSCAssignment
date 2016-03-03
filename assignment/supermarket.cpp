#include<iostream>
#include<string>
#include"supermarket.h"
#include<fstream>

using namespace std;

void supermarket::edit_item()
{
	int num;
	bool found = false;
	system("cls");
	cout << endl << endl << "\tPlease Enter The item #: ";
	cin >> num;

	
	while (fp.read((char*)&produc, sizeof(item)) && found == false)
	{
	//	if (produc[1].getitem() == num)
		{
			produc[1].show_item();
			cout << "\nPlease Enter The New Details of item: " << endl;
			produc[1].create_item();
			int pos = -1 * sizeof(produc);
			
			cout << endl << endl << "\t Record Successfully Updated...";
			found = true;
		}
	}
	
	if (found == false)
		cout << endl << endl << "Record Not Found...";
	getchar();
}

void supermarket::item_menu()
{
	system("cls");

	cout << endl << endl << "\t\titem MENU\n\n";
	border('@', 20);
	cout << "NO. NAME\t\tPRICE\n";
	space();
	border('@', 20);

	for (int x = 0; x < stock_no; x++) {
		cout << x <<". " << produc[x].getName() << "\t\t" << produc[x].getPrice() << endl;
	}
	
}

void supermarket::place_order() //OK
{
	int order_arr[50], quan[50], c = 0;
	float amt, damt, total = 0;
	char ch = 'Y';
	item_menu();
	border('@', 20);
	cout << "\n PLACE YOUR ORDER";
	space();
	border('@', 20);
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
	border('*', 20);
	cout << "Invoice" << endl;
	border('*', 20);
	cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount\n";
	for (int x = 0; x <= c; x++)
	{
		amt = produc[order_arr[x]].getPrice()*quan[x];
		cout << "\n" << order_arr[x] << "\t" << produc[x].getName() << "\t" << quan[x] << "\t\t" << produc[x].getPrice() << "\t" << amt;
		total += amt;
	}
	cout << "\n\n\t\t\t\t\tTOTAL = " << total;
	getchar();
}


void supermarket::admin_menu()
{
	system("cls");
	int option;
	border('@', 30);
	
	cout << "\n\tPress 1 to DISPLAY ALL itemS";
	cout << "\n\tPress 2 to MODIFY item";
	cout << "\n\tPress 3 to GO BACK TO MAIN MENU";
	border('@', 30);

	cout << "\n\n\tOption: ";
	cin >> option;
	switch (option)
	{
	

	case 1: item_menu();
		break;

	case 2: edit_item();
		break;

	case 3: system("cls");
		break;

	default:admin_menu();
	}
 }

//constructor - this will load the stock txt into your var
supermarket::supermarket() {
	
		string tmp;
		getline(fp, tmp, ':');
		market_name = tmp;
		getline(fp, tmp, ':');
		market_stock = stoi(tmp);
		getline(fp, tmp, ':');
		money = stod(tmp);

		int x = 0; //array need x 
		try
		{
			//no plagrism citation: Ji Young,2016
			while (!fp.eof()) { //Stock array - read until EOF
				getline(fp, tmp, '\n'); //eat newline
				getline(fp, tmp, ':'); //itemname
				produc[x].setName(tmp);
				getline(fp, tmp, ':'); //number
				produc[x].setQuanitity(stod(tmp));
				getline(fp, tmp, ':'); //unit price
				produc[x].setPrice(stod(tmp));
				getline(fp, tmp, ':');//unit weight
				produc[x].setWeight(stod(tmp));
				getline(fp, tmp, ':');//unit descp
				produc[x].setInfo(tmp);
				x++;
				stock_no = x;
			}
		}
		catch (exception ex)
		{
			//throw ex
		}
}

// #chenggarnett #yolo
void border(char c, int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << c;
	}
	space();
}

// #chenggarnett #yolo
void space()
{
	cout << endl;
}
