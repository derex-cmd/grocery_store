#pragma once
#include<iostream>
#include<string>
using namespace std;

class Feedback
{
private:
	char Comment[1000];
public:
	Feedback();
	Feedback(string c);
	string getFeedback();
};