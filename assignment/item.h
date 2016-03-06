#include<string>
#ifndef _ITEM_
#define _ITEM_

using namespace std;

class item
{
	string item_name, item_info;
	float item_price, item_weight;
	int item_quantity;

public:
	// constructors
	item();
	item(string, float, int, float, string);

	//setters
	void setName(string);
	void setPrice(float);
	void setQuantity(int);		
	void setWeight(float);
	void setInfo(string);

	//getters
	string getName();
	float getPrice();
	int getQuantity();	
	float getWeight();
	string getInfo();
	
};


#endif // !_ITEM_