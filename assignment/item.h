#pragma once
#include<iostream>
#include<string>

using namespace std;
class item
{
	int item_number;
	string item_name, item_info;
	float item_price, item_quantity, item_weight, item_discount;

public:

	void create_item();
	void show_item();
	int getitem();
	int getQuantity();
	float getPrice();
	string getName();
	float getDiscount();
	float getWeight();
	string getInfo();
	//setter
	void setitem(int);
	void setQuanitity(float);
	void setPrice(float);
	void setName(string);
	void setWeight(float);
	void setInfo(string);
};
