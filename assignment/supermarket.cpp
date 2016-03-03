#include<iostream>
#include<string>
#include"supermarket.h"
#include<fstream>

using namespace std;
//TODO: please remove all fp.write
//delete item or edit  item pls save into the variable first
void supermarket::save_item() {
	produc[stock_no].create_item();
	stock_no++;
	cout << endl << endl << "The item Has Been Sucessfully Created...";
	getchar();
}
void supermarket::show_all_item() //OK
{
	system("cls");
	cout << endl << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << endl << "\t\tRECORDS.";
	cout << endl << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	for (int x = 0; x < stock_no; x++)
	produc[x].show_item();
	cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
	getchar();
}
void supermarket::display_record(int num) //OK NO TEST
{
	bool found = false;
	if (num < stock_no){
			system("cls");
			produc[num].show_item();
			found = true;
		}

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
void supermarket::delete_item()
{
	int num;
	system("cls");
	cout << endl << endl << "Please Enter The item #: ";
	cin >> num;
	
	
	while (fp.read((char*)&produc, sizeof(item)))
	{
	//	if (produc[1].getitem() != num)
		{
			
		}
	}
	
	remove("Stock.txt");
	rename("Temp.dat", "Stock.txt");
	cout << endl << endl << "\tRecord Deleted...";
	getchar();
}
void supermarket::item_menu()
{
	system("cls");

	cout << endl << endl << "\t\titem MENU\n\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "NO. NAME\t\tPRICE\n";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
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