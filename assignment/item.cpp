#include<iostream>
#include<string>
#include"item.h"

using namespace std;

//getter

//setter

void item::create_item() {
	cout << endl << "Please Enter The Name of The item: ";
	cin.ignore();
	getline(cin,item_name);
	cout << endl << "Please Enter Quantity of The item: ";
	cin >> item_quantity;
	cout << endl << "Please Enter The Price of The item: ";
	cin >> item_price;
	cout << endl << "Please Enter The Weight of The item: ";
	cin >> item_weight;
	cout << endl << "Please Enter Description of The item: ";
	cin.ignore();
	getline(cin,item_info);
}

void item::show_item(){
	cout << endl << "Name" << "Quantity" << "Price" << "Weight" << "Info";
	cout << endl << item_name << ":" << item_quantity << ":" << item_price << ":" << item_weight << ":" << item_info;
}

int item::getQuantity() {
	return item_quantity;
}

float item::getPrice(){
	return item_price;
}
string item::getName()
{
	return item_name;
}
float item::getWeight() 
{
	return item_weight;
}
string item::getInfo()
{
	return item_info;
}

void item::setInfo(string s) {
	item_info = s;
}
void item::setName(string s) {
	item_name = s;
}
void item::setPrice(float f) {
	item_price = f;
}
void item::setQuanitity(float f) {
	item_quantity = f;
}
void item::setWeight(float f) {
	item_weight = f;
}