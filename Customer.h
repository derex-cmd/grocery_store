#pragma once
#include"../ProjectOOP/User.h"
#include"../ProjectOOP/Shopping.h"
using namespace std;

class Customer:public User
{
private:
	char CNIC[100];
	char Gender;
	char Phone[100];
	char Address[200];
	Shopping* S;
public:
	Customer();
	Customer(string Name, string Password, string Phone, string Address, string CNIC, char Gender);
	void setThisItemCart(string Name, double Cost);
	void DisplayItems();
	void FeedbackWrite();
	void DisplayFeedback();
	void LoginCustomer();
};