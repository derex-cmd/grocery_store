#pragma once
#include<iostream>
#include<string>
using namespace std;

class Shopping
{
private:
	int totalItems;
	double Cost;
public:
	Shopping();
	Shopping(double totalItems, double Cost);
	void settotalItems(int totalitems);
	void setCost(double Cost);
};