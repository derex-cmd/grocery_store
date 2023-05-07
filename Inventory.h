#pragma once
#include<string>
#include<iostream>
#include"../ProjectOOP/Catalog.h"
using namespace std;
class Inventory:public Catalog
{
private:
	
public:
	Inventory();
	Inventory(string name, double price);
	void deleteitemInventory(string itemn);
	void updateItemInventory(string itemn, string itemp);
	void displayItemInventory();


	template <class P>
	void addItemInventory(const string file, const P& u);
	
};