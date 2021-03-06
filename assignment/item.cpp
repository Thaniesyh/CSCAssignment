#include<string>
#include"item.h"

using namespace std;

//constructors
item::item()
{
	//the variables in item.h  
	item_name = "";
	item_price = NULL;
	item_quantity = NULL;
	item_info = "";
	item_weight = NULL;
}

item::item(string name, float price, int qua, float weight, string des)
{
	// variables
	item_name = name;
	item_price = price;
	item_quantity = qua;
	item_weight = weight;
	item_info = des;
}

//getters
int item::getQuantity() 
{
	return item_quantity;
}

float item::getPrice()
{
	return item_price;
}
string item::getName(){
	return item_name;
}
float item::getWeight() {
	return item_weight;
}
string item::getInfo(){
	return item_info;
}

//setters
void item::setInfo(string s) {
	item_info = s;
}
void item::setName(string s) {
	item_name = s;
}
void item::setPrice(float f) {
	item_price = f;
}
void item::setQuantity(int f) {
	item_quantity = f;
}
void item::setWeight(float f) {
	item_weight = f;
}