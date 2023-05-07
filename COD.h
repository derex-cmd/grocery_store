#pragma once
#include<iostream>
#include"../ProjectOOP/Payment.h"
using namespace std;

class COD:public Payment
{
private:
	char address[200];

public:
	COD();
	COD(string p);
	void setCOD(string p);
	string getCOD();
};