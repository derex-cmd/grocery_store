#pragma once
#include<iostream>
#include<string>
using namespace std;
class User
{
private:
	char Name[100];
	char Password[100];
public:
	User();
	User(string n, string p);
	void setName(string n);
	void setPass(string p);
	string getName();
	string getPass();
	virtual void Register();
};