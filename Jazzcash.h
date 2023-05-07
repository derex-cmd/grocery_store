#pragma once
#include<iostream>
#include<string>
#include"../ProjectOOP\Online.h"
using namespace std;

class Jazzcash:public Online
{
private:
	char Number[100];
public:
	Jazzcash();
	Jazzcash(string p);
	void setNumber(string p);
	string getNumber();




};