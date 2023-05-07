#pragma once
#include<iostream>
#include<string>
#include"../ProjectOOP\Online.h"
using namespace std;

class Bank
{
private:
	char accountNumber[100];
public:
	Bank();
	Bank(string p);
	void setaccountNumber(string p);
	string getaccountNumber();




};