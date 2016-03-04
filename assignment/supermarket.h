#include<iostream>
#include<string>
#include"item.h"

class supermarket{
	string market_name;
	int market_stock,stock_no;
	float money;
	fstream fp;
	item product[100];
public:
	// constructor
	supermarket();

	void item_menu();
	void edit_item();
	void place_order();
	void admin_menu();	
	void show_item();

	// alignment
	void border(char, int);
	void space();
	
};