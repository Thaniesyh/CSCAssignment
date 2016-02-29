#pragma once
#include<iostream>
#include<string>

using namespace std;
class item
{
	int item_number, item_stock;
	string item_name, item_info, market_name;
	float item_price, item_quantity, item_weight, item_discount, money;

public:

	void create_item();
	void show_item();
	void create_market();
	void show_marketinfo();
	int getitem();
	int getQuantity();
	float getPrice();
	string getName()
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

	string getInfo() {
		return item_info;
	}
};
