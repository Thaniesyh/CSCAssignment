
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
