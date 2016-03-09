#include<iostream>
#include<string>
#include<fstream>
#include"supermarket.h"
#include<iomanip>
using namespace std;

//constructor - this will load the stock txt into your var
supermarket::supermarket() {
	ifstream fp;
	fp.open("Stock.txt");
	if (fp.is_open()) {
		string tmp;
		getline(fp, tmp, ':');
		market_name = tmp;
		getline(fp, tmp, ':');
		market_stock = stoi(tmp);
		getline(fp, tmp, ':');
		money = stof(tmp);

		int x = 0; //array need x 
		try
		{
			
			while (!fp.eof()) { //Stock array - read until EOF
				getline(fp, tmp, '\n'); //eat newline
				getline(fp, tmp, ':'); //itemname
				product[x].setName(tmp);
				getline(fp, tmp, ':'); //number
				product[x].setQuantity(stod(tmp));
				getline(fp, tmp, ':'); //unit price
				product[x].setPrice(stof(tmp));
				getline(fp, tmp, ':');//unit weight
				product[x].setWeight(stof(tmp));
				getline(fp, tmp, ':');//unit descp
				product[x].setInfo(tmp);
				x++;
				stock_no = x;
			}
		}
		catch (exception ex)
		{
			//throw ex
		}

	}
	else {
		//Stock.txt not open
		//code error handling here.
	}

}


void supermarket::place_order() // place order in the menu 
{
	int order_arr[50], quan[50], c = 0;
	float amt, total = 0;
	char ch = 'Y';
	item_menu();
	border('@', 50);
	cout << "\n PLACE YOUR ORDER";
	space();
	border('@', 50);
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
	border('*', 50);
	cout << "\t\tInvoice" << endl;
	border('*', 50);
	cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount\n";
	for (int x = 0; x < c; x++)
	{
		amt = product[order_arr[x]-1].getPrice()*quan[x];
		product[order_arr[x] - 1].setPrice(product[order_arr[x]-1].getQuantity()-quan[x]);
		cout << "\n" << order_arr[x] << "\t" << product[order_arr[x]-1].getName() << "\t" << quan[x] << "\t\t" << product[order_arr[x]-1].getPrice() << "\t" << amt;
		total += amt;
	}
	cout << "\n\n\t\t\t\t\tTOTAL = " << total;
	getchar();
}

void supermarket::item_menu() // display all the item menu
{	
	system("cls");
	cout << endl << endl << "\t\tItem MENU\n\n";
	border('@', 50);
	cout << "NO. NAME\t\tPRICE\t\tQuantity\n";	
	border('@', 50);

	for (int x = 0; x < stock_no; x++) {
		cout << x + 1 << ". "
			<< product[x].getName() << "\t\t"
			<< product[x].getPrice() << "\t\t"
			<< product[x].getQuantity() << endl;
	}

}


void supermarket::edit_item() //edit all the item in the menu
{
	int num, n;
	int newQua;
	double newPri;

	system("cls");
	item_menu();
	cout << endl << endl << "\tPlease Enter The item #: ";
	cin >> num;
	if (num > 0 && num < stock_no + 1) {

		cout << "1. Quantity" << endl;
		cout << "2. Price" << endl;
		cout << "Please select option" << endl;
		cin >> n;

		switch (n)
		{
		case 1:
			cout << "New quantity :" << endl;
			cin >> newQua;
			product[num - 1].setQuantity(newQua);
			break;

		case 2:
			cout << "New price :" << endl;
			cin >> newPri;
			product[num - 1].setPrice(newPri);
			break;

		default:
			cout << "Error" << endl;
		}

	}

	else
		cout << "Record not found!" << endl;
	

}




void supermarket::border(char c, int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << c;
	}
	space();
}


void supermarket::space()
{
	cout << endl;
}


int supermarket::checkValidation(int cho, int a, int b)
{	
	
	while (cho < a || cho > b)
	{
		cout << "Please try again!" << endl;
		cin >> cho;		
	}

	return cho;
}

supermarket::~supermarket() {
	ofstream fo; //transfer to Stock.txt
	fo.open("Stock.txt");
	

	if (fo.is_open()) {
		fo << fixed << showpoint << setprecision(2);
		//Save to txt
		string line;
		//First Line
		fo << market_name << ":" << market_stock << ":" << money << ":" << endl;
		int x = 0;
		while (x < stock_no) {
			fo << product[x].getName() << ":" << product[x].getQuantity() << ":" << product[x].getPrice() << ":" << product[x].getWeight() << ":" << product[x].getInfo();
			if (x < stock_no - 1)
				fo << ":" << endl;
			x++;
		}
	}
	else {
		cout << "\n \\Enter Error Message Here \n";
	}

}
