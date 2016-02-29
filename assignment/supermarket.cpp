#include<iostream>
#include<string>
#include"supermarket.h"
#include<fstream>

using namespace std;

void supermarket::save_item() {
	fp.open("itemstorage.txt", ios::out | ios::app);
	produc.create_item();
	fp.write((char*)&produc, sizeof(item));
	fp.close();
	cout << endl << endl << "The item Has Been Sucessfully Created...";
	getchar();
}
