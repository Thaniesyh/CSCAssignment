#include<iostream>
#include<string>
#ifndef _ITEM_
#define _ITEM_

using namespace std;
class item
{
	string item_name, item_info;
	float item_price, item_quantity, item_weight;

public:
	//setters
	void setQuanitity(float);
	void setPrice(float);
	void setName(string);
	void setWeight(float);
	void setInfo(string);

	//getters
	string getName();
	int getQuantity();
	float getPrice();
	float getWeight();
	string getInfo();
	
};


#endif // !_ITEM_