#pragma once
#include<iostream>
#include"../ProjectOOP/User.h"
class Manager:public User
{
private:
	char CNIC[100];
	char Gender;
	char Phone[100];
	char Address[200];
public:
	Manager();
	Manager(string Name, string Password, string Phone, string Address, string CNIC, char Gender);
	void DisplayInventory();
	void updateInventory();
	void addInventory();
	void deleteInventory();
	void LoginManager();

};