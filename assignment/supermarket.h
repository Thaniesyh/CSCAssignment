#include<iostream>
#include<string>
#include"item.h"
#include<fstream>

class supermarket{
	string market_name;
	int market_stock,stock_no;
	float money;
	fstream fp;
	item produc[100];
public:

	void show_all_item();
	void item_menu();
	void edit_item();
	void place_order();
	void admin_menu();
	void border(char, int);
	supermarket();
};