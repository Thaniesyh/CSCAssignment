#pragma once
#include<iostream>
#include<string>

using namespace std;
class item
{
	string item_name, item_info;
	float item_price, item_quantity, item_weight;

public:

	void create_item();
	void show_item();
	int getQuantity();
	float getPrice();
	string getName();
	float getWeight();
	string getInfo();
	//setter
	void setQuanitity(float);
	void setPrice(float);
	void setName(string);
	void setWeight(float);
	void setInfo(string);
};
