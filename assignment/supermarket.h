
#include<string>
#include"item.h"

#ifndef _SUPERMARKET_
#define _SUPERMARKET_

class supermarket{
	string market_name;
	int market_stock,stock_no;
	float money;
	item product[100];
public:
	// constructor
	supermarket();

	void item_menu();
	void edit_item();
	void place_order();			

	// alignment
	void border(char, int);
	void space();
	
};
#endif // !_SUPERMARKET_