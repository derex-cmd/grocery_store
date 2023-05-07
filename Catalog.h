#pragma once
#include<string>
#include<iostream>
using namespace std;
class Catalog
{
private:
	char item[100];
	char itemPrice[100];
public:
	Catalog();
	Catalog(string item, string itemPrice);
	void setItem(string item);
	void setPriceItem(string itemPrice);
	string getItem();
	string getPriceItem();
	void deleteitem(string itemn);
	void updateItem(string itemn, string itemp);
	void displayItem();

	template <class P>
	void addItem(const string file, const P& u);
	
};