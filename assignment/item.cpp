#include<iostream>
#include<string>
#include"item.h"

using namespace std;

//getter

//setter

void item::create_item() {
	cout << endl << "Please Enter The item Number: ";
	cin >> item_number;
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
	cout << endl << "Please Enter The Discount (%): ";
	cin >> item_discount;
}

void item::show_item(){
	cout << endl << "No" << "Name" << "Quantity" << "Price" << "Weight" << "Info";
	cout << endl << item_number << ":" << item_name << ":" << item_quantity << ":" << item_price << ":" << item_weight << ":" << item_info << ":" << item_discount;
}

void item::create_market() {
	cout << "Enter market's name" << endl;
	cin >> market_name;
	cout << "Enter market's money" << endl;
	cin >> money;
}

void item::show_marketinfo(){
	cout << endl << "Market Name" << "Amount of item" << "Money own";
	cout << endl << market_name << ":" << item_stock << ":" << money << ":";
}

int item::getitem() {
	return item_number;
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
float item::getDiscount()
{
	return item_discount;
}
float item::getWeight() 
{
	return item_weight;
}
string item::getInfo()
{
	return item_info;
}
