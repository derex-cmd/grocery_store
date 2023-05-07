#pragma once
#include<iostream>
#include<string>
using namespace std;

class Payment
{
	double bill;
public:
	Payment();
	Payment(double p);
	void setBill(double p);
	double getBill();
	virtual void checkPayment();

};