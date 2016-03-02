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
	void save_item();
	void show_all_item();
	void display_record(int num);
	void edit_item();
	void delete_item();
	void item_menu();
	void place_order();
	void market_items();
	void admin_menu();
	supermarket();
};