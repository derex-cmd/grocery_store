#pragma once
#include"../ProjectOOP/User.h"
#include"../ProjectOOP/Manager.h"
#include"../ProjectOOP/Catalog.h"
class Admin:public User
{
private:
	Manager* M;
	Catalog* Cata;
public:
	void deleteitem(string itemn, string itemp);
	void updateItem(string itemn, string itemp);
	void DisplayCatalog();
	void updateCatalog();
	void writeCatalog();
	void deleteCatalog();
	void makeManager();
	void LoginAdmin();
};