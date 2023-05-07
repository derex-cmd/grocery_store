#include<iostream>
#include<string>
#include<string.h>
#include<cstdlib>
#include<fstream>
//#include"../ProjectOOP/User.h"
//#include"../ProjectOOP/Customer.h"
using namespace std;


/*Functions to check Validation of CNIC*/
bool digitsCheck(string s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]))
		{
			return true;
		}
		return false;
	}
}


bool cniclenCheck(string s)
{
	if (s.length() == 13)
	{
		return true;
	}
	return false;

}








template<class P>
bool cnicCheck(string file, string CNIC)
{
	P check;
	ifstream inp(file, ios::binary);

	while (inp.read((char*)&check, sizeof(check)))
	{
		if (check.getCNIC() == CNIC)
		{
			return false;
		}
	}
	return true;
}






/*Fuctions to check validation of Password*/
bool numCheck(string s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]))
		{
			return true;
		}
		return false;
	}
}
bool capCheck(string s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (isupper(s[i]))
		{
			return true;
		}
		return false;
	}
}
bool lenCheck(string s)
{
	if (s.length() >= 9)
	{
		return true;
	}
		return false;

}


/*To read and write data from a specific class using Templates*/


/*This function is used to verifying admin' credentials*/
template<class P>
bool read(string file, string Name, string Password, P& u) // Read function .
{
	ifstream inp(file, ios::binary);

	while (inp.read((char*)&u, sizeof(u)))
	{
		if (u.getName() == Name && u.getPass() == Password)
		{
			return true;
		}
	}
	return false;
}

/*This will be used by both customer and manager's verification*/
template<class P>
bool readLogin(string file, string cnic, string Password, P& u) // Read function .
{
	ifstream inp(file, ios::binary);

	while (inp.read((char*)&u, sizeof(u)))
	{
		if (u.getCNIC() == cnic && u.getPass() == Password)
		{
			return true;
		}
	}
	return false;
}



template <class P>
void write(const string file, const P& u) // Write function to register a new user.
{
	ofstream o(file, ios::binary | ios::app);
	o.write((char*)&u, sizeof(u));
	cout << "Successfull!" << endl;
	o.close();
}


/*Helping function, just to check admins username and password*/
template<class P>
void readDisplay(string file, P& u) // Read function .
{
	ifstream inp(file, ios::binary);

	while (inp.read((char*)&u, sizeof(u)))
	{
		cout << "Username =: " << u.getName() << "    " << "Password" << u.getPass() << endl;
	}
}











/*This function will delete an item from the inventory, replciate the file and name it as the older file*/
//void deleteitem(string itemn, string itemp)
//{
//	string fileName = "Catalog.bin";
//	Catalog t;
//	fstream f("Catalog.bin", ios::binary | ios::in | ios::out);
//	fstream f2("temp.bin", ios::binary | ios::in | ios::out | ios::app);
//	while (f.read((char*)&t, sizeof(t)))
//	{
//		if (t.getItem() == itemn && t.getPriceItem() == itemp)
//		{
//
//		}
//		else
//		{
//			f2.write((char*)&t, sizeof(t));
//		}
//	}
//	f.close();
//	f2.close();
//	remove(fileName.c_str());
//	rename("temp.bin", fileName.c_str());
//}
//
//
///*This function will update the price of an item in the list, hence appending that item ONLY*/
//void updateItem(string itemn, string itemp)
//{
//	Catalog p;
//	fstream update("Catalog.bin", ios::in | ios::out | ios::binary);
//	while (update.read((char*)&p, sizeof(p)))
//	{
//		if (p.getItem() == itemn)
//		{
//			p.setPriceItem(itemp);
//			int b = 0;
//			b = update.tellg();
//			int c = sizeof(p);
//			update.seekp(b - c, ios::beg);
//			update.write((char*)&p, sizeof(p));
//			break;
//		}
//	}
//	update.close();
//}
//
//
///*This function will be used to display All the current items in the Catalog*/
//void displayItem()
//{
//	Catalog t;
//	int i = 1;
//	fstream f("Catalog.bin", ios::in | ios::out | ios::binary);
//	while (f.read((char*)&t, sizeof(t)))
//	{
//		cout << "Item name = " << t.getItem() << "    " << "Price = " << t.getPriceItem() << endl;
//	}
//	f.close();
//}




class Payment
{
	double bill;
public:
	Payment()
	{

	}
	Payment(double p)
	{
		bill = p;
	}
	void setBill(double p)
	{
		bill = p;
	}
	double getBill()
	{
		return bill;
	}
	void checkPayment();

};





class COD :public Payment
{
private:
	char address[200];

public:
	COD()
	{

	}
	COD(string p)
	{
		strcpy_s(this->address, p.c_str());
	}
	void setCOD(string p)
	{
		strcpy_s(this->address, p.c_str());
	}
	string getCOD()
	{
		return address;
	}
	void checkPayment()
	{
		string add;
		cout << "*********************************************************************************" << endl;
		cout << "You have chosen Cash on Delivery Option, kindly enter your Shipping Details" << endl;
		cout << endl;
		cout << "Enter Your Address: ";
		cin >> add;
		setCOD(add);
		cout << "Successfull!" << endl;
		cout << "Your final bill after 3 dollar delivery charges is: " << (getBill() + 3) << endl;
		cout << "*********************************************************************************" << endl;
	}

};




class Online :public Payment
{
public:
};




class Bank:public Online
{
private:
	char accountNumber[100];
public:
	Bank()
	{

	}
	Bank(string p)
	{
		strcpy_s(this->accountNumber, p.c_str());
	}
	void setaccountNumber(string p)
	{
		strcpy_s(this->accountNumber, p.c_str());
	}
	string getaccountNumber()
	{
		return accountNumber;
	}

	void BankType()
	{
		string code;
		cout << "*********************************************************************************" << endl;
		cout << "Please Enter your account code below for the transaction:  ";
		cin >> code;
		setaccountNumber(code);
		cout << "Successfull" << endl << endl;
		cout << "Thank you so much for Shopping with us!" << endl;
		cout << "*********************************************************************************" << endl;
	}

};




class Jazzcash :public Online
{
private:
	char Number[100];
public:
	Jazzcash()
	{

	}
	Jazzcash(string p)
	{
		strcpy_s(this->Number, p.c_str());
	}
	void setNumber(string p)
	{
		strcpy_s(this->Number, p.c_str());
	}
	string getNumber()
	{
		return Number;
	}
	void JazzcashType()
	{
		string code;
		cout << "*********************************************************************************" << endl;
		cout << "Please Enter your mobile number below for the transaction:  ";
		cin >> code;
		setNumber(code);
		cout << "Successfull" << endl << endl;
		cout << "Thank you so much for Shopping with us!" << endl;
		cout << "*********************************************************************************" << endl;
	}
};













class Feedback
{
private:
	char Comment[1000];
public:
	Feedback()
	{

	}
	Feedback(string c)
	{
		strcpy_s(this->Comment, c.c_str());
	}
	void setFeedback(string c)
	{
		strcpy_s(this->Comment, c.c_str());
	}
	string getFeedback()
	{
		return Comment;
	}






	/*This function will add a new item inside the item lists*/
	template <class P>
	void addFeedback(const string file, const P& u) // Write function to add new Item.
	{
		ofstream o(file, ios::binary | ios::app);
		o.write((char*)&u, sizeof(u));
		cout << "Feedback Successfully Added!" << endl;
		o.close();
	}



	/*This function will be used to display All the current items in the Catalog*/
	void displayFeedback()
	{
		Feedback t;
		int i = 1;
		fstream f("Feedback.bin", ios::in | ios::out | ios::binary);
		while (f.read((char*)&t, sizeof(t)))
		{
			cout << t.getFeedback() << endl;
		}
		f.close();
	}








};














class Shopping
{
private:
	string totalItems;
	double Cost;
public:
	Shopping()
	{
		
	}
	Shopping(string totalItemss, double Cost)
	{
		for (int i = 0; i < 7; i++)
		{
			this->totalItems = totalItems;
			this->Cost = Cost;
		}
	}
	void settotalItems(string name)
	{
		totalItems = name;
	}
	void setCost(double price)
	{
		Cost = price;
	}
	string gettotalItems()
	{
		return totalItems;
	}
	double getCost()
	{
		return Cost;
	}






};




/*Catalog attributes Initialization*/
class Catalog
{
private:
	char item[100];
	char itemPrice[100];
public:
	Catalog()
	{

	}
	Catalog(string item, string itemPrice)
	{
		strcpy_s(this->item, item.c_str());
		strcpy_s(this->itemPrice, itemPrice.c_str());
	}
	void setItem(string item)
	{
		strcpy_s(this->item, item.c_str());
	}
	void setPriceItem(string itemPrice)
	{
		strcpy_s(this->itemPrice, itemPrice.c_str());
	}
	string getItem()
	{
		return item;
	}
	string getPriceItem()
	{
		return itemPrice;
	}



	/*This function will delete an item from the inventory, replicate the file and name it as the older file*/
	void deleteitem(string itemn)
	{
		string fileName = "Catalog.bin";
		Catalog t;
		fstream f("Catalog.bin", ios::binary | ios::in | ios::out);
		fstream f2("temp.bin", ios::binary | ios::in | ios::out | ios::app);
		while (f.read((char*)&t, sizeof(t)))
		{
			if (t.getItem() == itemn)
			{

			}
			else
			{
				f2.write((char*)&t, sizeof(t));

			}
		}
		cout << "Item Successfuly Deleted!" << endl;
		f.close();
		f2.close();
		remove(fileName.c_str());
		rename("temp.bin", fileName.c_str());
	}


	/*This function will update the price of an item in the list, hence appending that item ONLY*/
	void updateItem(string itemn, string itemp)
	{
		Catalog p;
		fstream update("Catalog.bin", ios::in | ios::out | ios::binary);
		while (update.read((char*)&p, sizeof(p)))
		{
			if (p.getItem() == itemn)
			{
				p.setPriceItem(itemp);
				int b = update.tellg();
				int c = sizeof(p);
				update.seekp(b - c, ios::beg);
				update.write((char*)&p, sizeof(p));
				cout << "Item successfully Updated!" << endl;
				break;
			}
			else
			{
				cout << "No such item found in the Catalog    :(  " << endl;
				break;
			}
		}
		update.close();
	}


	/*This function will be used to display All the current items in the Catalog*/
	void displayItem()
	{
		Catalog t;
		int i = 1;
		fstream f("Catalog.bin", ios::in | ios::out | ios::binary);
		while (f.read((char*)&t, sizeof(t)))
		{
			cout << "Item name = " << t.getItem() << "    " << "Price = " << t.getPriceItem() << endl;
		}
		f.close();
	}


	/*This function will add a new item inside the item lists*/
	template <class P>
	void addItem(const string file, const P& u) // Write function to add new Item.
	{
		ofstream o(file, ios::binary | ios::app);
		o.write((char*)&u, sizeof(u));
		cout << "Item successfully added to the Catalog!" << endl;
		o.close();
	}





};







/*Inventory Class*/
class Inventory :public Catalog
{
private:

public:
	Inventory()
	{

	}
	Inventory(string item, string itemPrice)
	{
		setItem(item);
		setPriceItem(itemPrice);
	}



	/*This function will delete an item from the inventory, replicate the file and name it as the older file*/
	void deleteitemInventory(string itemn)
	{
		string fileName = "Inventory.bin";
		Inventory t;
		fstream f("Inventory.bin", ios::binary | ios::in | ios::out);
		fstream f2("temp.bin", ios::binary | ios::in | ios::out | ios::app);
		while (f.read((char*)&t, sizeof(t)))
		{
			if (t.getItem() == itemn)
			{

			}
			else
			{
				f2.write((char*)&t, sizeof(t));

			}
		}
		cout << "Item Successfuly Deleted!" << endl;
		f.close();
		f2.close();
		remove(fileName.c_str());
		rename("temp.bin", fileName.c_str());
	}


	bool searchInventory(string itemn)
	{
		Inventory p;
		fstream update("Inventory.bin", ios::in | ios::out | ios::binary);
		while (update.read((char*)&p, sizeof(p)))
		{
			if (p.getItem() == itemn)
			{
				return true;
			}
			else
			{
				cout << "No such item found in the Inventory    :(  " << endl;
				return false;
				break;
			}
		}
	}

	

	/*This function will update the price of an item in the list, hence appending that item ONLY*/
	void updateItemInventory(string itemn, string itemp)
	{
		Inventory p;
		fstream update("Inventory.bin", ios::in | ios::out | ios::binary);
		while (update.read((char*)&p, sizeof(p)))
		{
			if (p.getItem() == itemn)
			{
				p.setPriceItem(itemp);
				int b = 0;
				b = update.tellg();
				int c = sizeof(p);
				update.seekp(b - c, ios::beg);
				update.write((char*)&p, sizeof(p));
				cout << "Item successfully Updated!" << endl;
				break;
			}
			else
			{
				cout << "No such item found in the Inventory    :(  " << endl;
				break;
			}
		}
		update.close();
	}


	/*This function will be used to display All the current items in the Catalog*/
	void displayItemInventory()
	{
		Inventory t;
		int i = 1;
		fstream f("Inventory.bin", ios::in | ios::out | ios::binary);
		while (f.read((char*)&t, sizeof(t)))
		{
			cout << "Item name = " << t.getItem() << "    " << "Price = " << t.getPriceItem() << endl;
		}
		f.close();
	}


	/*This function will add a new item inside the item lists*/
	template <class P>
	void addItemInventory(const string file, const P& u) // Write function to add new Item.
	{
		ofstream o(file, ios::binary | ios::app);
		o.write((char*)&u, sizeof(u));
		cout << "Item successfully added to the Inventory!" << endl;
		o.close();
	}



};








/*Initializing the attributes of User Class*/
/*Constructor + Setters + Getters*/

class User
{
private:
	char Name[100];
	char Password[100];

	char CNIC[100];
	char Gender;
	char Phone[100];
	char Address[200];
public:
	User()
	{

	}
	User(string Name, string Password)
	{
		strcpy_s(this->Name, Name.c_str());
		strcpy_s(this->Password, Password.c_str());
	}
	void setName(string s)
	{
		strcpy_s(this->Name, s.c_str());
	}
	void setPass(string p)
	{
		strcpy_s(this->Password, p.c_str());
	}
	string getName()
	{
		return Name;
	}
	string getPass()
	{
		return Password;
	}

	void setCNIC(string CNIC)
	{
		strcpy_s(this->CNIC, CNIC.c_str());
	}
	void setGender(char g)
	{
		Gender = g;
	}
	void setAddress(string Address)
	{
		strcpy_s(this->Address, Address.c_str());
	}
	void setPhone(string Phone)
	{
		strcpy_s(this->Phone, Phone.c_str());
	}

	string getCNIC()
	{
		return CNIC;
	}
};









/*Customer attributes Initialization*/
class Customer :public User
{
private:
	Shopping* S = new Shopping;
	Inventory* I = new Inventory;
	Feedback* F = new Feedback;
	Payment* P = new Payment;
public:

	Customer()
	{

	}

	Customer(string Name, string Password, string Phone, string Address, string CNIC, char Gender)
	{
		setName(Name);
		setPass(Password);
		setCNIC(CNIC);
		setPhone(Phone);
		setAddress(Address);
		setGender(Gender);
	}
	
	void setThisItemCart(string Name, double Cost)
	{
		S->settotalItems(Name);
		S->setCost(Cost);
	}
	
	
	void DisplayItems()
	{
		cout << "*********************************************************************************" << endl;
		cout << "The entire Inventory is Displayed below:                     " << endl;
		I->displayItemInventory();
		cout << endl << endl;
		cout << "*********************************************************************************" << endl;
	}
	
	void FeedbackWrite()
	{
		string file = "Feedback.bin";
		string h;
		cout << "*********************************************************************************" << endl;
		cout << "Thank you for Shopping with us! Kindly drop your review below:                     " << endl;
		cin >> h;
		Feedback p(h);
		F->addFeedback<Feedback>(file, p);
		
		cout << endl << endl;
		cout << "*********************************************************************************" << endl;
	}

	void DisplayFeedback()
	{
		cout << "*********************************************************************************" << endl;
		cout << "Here are all of our previous reviews                     " << endl;
		Feedback F;
		F.displayFeedback();
		cout << endl << endl;
		cout << "*********************************************************************************" << endl;
	}

	void LoginCustomer()
	{
		Customer A;
		string name, pass;
		string file = "Customer.bin";
		cout << "*********************************************************************************" << endl;
		cout << "Enter Customer's login credintials:" << endl;
		cin >> name;
		cout << endl;
		cout << "Enter Customer password:";
		cin >> pass;
		cout << endl;
		while (!(read<Customer>(file, name, pass, A)))
		{
			cout << "Enter correct credentials!" << endl;
			cout << "Enter Customer's Username credintials:" << endl;
			cin >> name;
			cout << endl;
			cout << "Enter Customer's password:";
			cin >> pass;
			cout << endl;
		}
		cout << "Credintials matches!" << endl;
		cout << "*********************************************************************************" << endl;
	}


	void setTotalBill(double n)
	{
		P->setBill(n);
	}


	void RegisterCustomer()
	{
		Customer A;
		system("CLS");
		cout << "*********************************************************************************" << endl;
		string n, p, p2, ph, add, c;
		char g;
		string file = "Customer.bin";
		cout << "Enter a valid 13 digits cnic: ";
		cin >> c;
		while (!(cniclenCheck(c)))
		{
			cout << "Enter a valid 13 digit cnic" << endl;
			cin >> c;
		}
		cout << "Enter you Passwrd: ";
		cin >> p;
		cout << endl;
		cout << "Enter you Passwrd again: ";
		cin >> p2;
		while (p != p2)
		{
			cout << "Passwords do not match" << endl;
			cout << "Re-enter valid Password: ";
			cin >> p2;
			cout << endl;
		}
		cout << endl;
		cout << "Enter your Name: ";
		cin >> n;
		cout << endl;
		cout << "Enter your Gender: ";
		cin >> g;
		cout << endl;
		cout << "Enter your Phone number: ";
		cin >> ph;
		cout << endl;
		cout << "Enter your address: ";
		cin >> add;
		cout << endl;

		Customer C(n, p, ph, add, c, g);
		write<Customer>(file, C);
		cout << "*********************************************************************************" << endl;

	}


	bool checkAvail(string name)
	{
		if (I->searchInventory(name) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



};
























/*     Manager Class       */
class Manager :public User
{
private:
	Inventory* I = new Inventory;
public:
	Manager()
	{

	}
	Manager(string Name, string Password, string Phone, string Address, string CNIC, char Gender)
	{
		setName(Name);
		setPass(Password);
		setCNIC(CNIC);
		setPhone(Phone);
		setAddress(Address);
		setGender(Gender);
	}
	/*Function used by the admin to view the entire Catalog*/
	void DisplayInventory()
	{
		cout << "*********************************************************************************" << endl;
		cout << "The entire Inventory is Displayed below:                     " << endl;
		I->displayItemInventory();
		cout << endl << endl;
		cout << "*********************************************************************************" << endl;
	}

	/*Function used by the admin to update an item*/
	void updateInventory()
	{
		string name, price;
		cout << "*********************************************************************************" << endl;
		cout << "Enter the Name of the item to want to search with the updated price    " << endl;
		cout << endl;
		cout << "Item name: ";
		cin >> name;
		cout << endl;
		cout << "What would you like the new price to be?" << endl;
		cin >> price;
		cout << endl;
		I->updateItemInventory(name, price);
		cout << "*********************************************************************************" << endl;
	}

	/*This function will be used to add a new items in catalog*/
	void addInventory()
	{
		string file = "Inventory.bin";
		string name, price;
		cout << "*********************************************************************************" << endl;
		cout << "               Enter the Name of the item to want to add in the Inventory    " << endl;
		cout << endl;
		cout << "Item name: ";
		cin >> name;
		cout << endl;
		cout << "What would you like the new price to be?" << endl;
		cin >> price;
		cout << endl;
		Inventory C(name, price);
		I->addItemInventory(file, C);
		cout << "*********************************************************************************" << endl;
	}

	/*This function will be used to delete an item based on its name*/
	void deleteInventory()
	{
		string name;
		cout << "*********************************************************************************" << endl;
		cout << "Enter the Name of the item to want to add in the Inventory    " << endl;
		cout << endl;
		cout << "Item name: ";
		cin >> name;
		cout << endl;
		I->deleteitemInventory(name);
		cout << "*********************************************************************************" << endl;
	}

	void LoginManager()
	{
		Manager A;
		string name, pass;
		string file = "Manager.bin";
		cout << "*********************************************************************************" << endl;
		cout << "Enter Manager's login credintials:" << endl;
		cin >> name;
		cout << endl;
		cout << "Enter Manager's password:";
		cin >> pass;
		cout << endl;
		while (!(read<Manager>(file, name, pass, A)))
		{
			cout << "Enter correct credentials!" << endl;
			cout << "Enter Manager's Username credintials:" << endl;
			cin >> name;
			cout << endl;
			cout << "Enter Manager's password:";
			cin >> pass;
			cout << endl;
		}
		cout << "Credintials matches!" << endl;
		cout << "*********************************************************************************" << endl;
	}

};













/*    Admin Class      */
class Admin :public User
{
private:
	//Manager* m;
	Catalog* cata = new Catalog;
	Manager* M = new Manager;
public:
	Admin()
	{

	}
	Admin(string n, string p)
	{
		setName(n);
		setPass(p);
		//Catalog* cata = new Catalog;
		
	}
	/*Function used by the admin to view the entire Catalog*/
	void DisplayCatalog()
	{
		cout << "*********************************************************************************" << endl;
		cout << "The entire Catalog is Displayed below:         " << endl;
		cata->displayItem();
		cout << endl << endl;
		cout << "*********************************************************************************" << endl;
	}

	/*Function used by the admin to update an item*/
	void updateCatalog()
	{
		string name, price;
		cout << "*********************************************************************************" << endl;
		cout << "Enter the Name of the item to want to search with the updated price    " << endl;
		cout << endl;
		cout << "Item name: ";
		cin >> name;
		cout << endl;
		cout << "What would you like the new price to be?" << endl;
		cin >> price;
		cout << endl;
		cata->updateItem(name, price);
		cout << "*********************************************************************************" << endl;
	}

	/*This function will be used to add a new items in catalog*/
	void addCatalog()
	{
		string file = "Catalog.bin";
		string name, price;
		cout << "*********************************************************************************" << endl;
		cout << "    Enter the Name of the item to want to add in the catalog    " << endl;
		cout << endl;
		cout << "Item name: ";
		cin >> name;
		cout << endl;
		cout << "What would you like the new price to be?" << endl;
		cin >> price;
		cout << endl;
		Catalog C(name, price);
		cata->addItem(file, C);
		cout << "*********************************************************************************" << endl;
	}

	/*This function will be used to delete an item based on its name*/
	void deleteCatalog()
	{
		string name;
		cout << "*********************************************************************************" << endl;
		cout << "    Enter the Name of the item to want to add in the catalog    " << endl;
		cout << endl;
		cout << "Item name: ";
		cin >> name;
		cout << endl;
		cata->deleteitem(name);
		cout << "*********************************************************************************" << endl;
	}

	/*This function will register a new Manager*/
	void makeManager()
	{
		Manager A;
		system("CLS");
		cout << "*********************************************************************************" << endl;
		string n, p, p2, ph, add, c;
		char g;
		string file = "Manager.bin";
		cout << "Enter a valid 13 digits cnic: ";
		cin >> c;
		while (!(cniclenCheck(c)))
		{
			cout << "Enter a valid 13 digit cnic" << endl;
			cin >> c;
		}
		cout << "Enter you Password: ";
		cin >> p;
		cout << endl;
		cout << "Enter you Password again: ";
		cin >> p2;
		while (p != p2)
		{
			cout << "Passwords do not match" << endl;
			cout << "Re-enter valid Password: ";
			cin >> p2;
			cout << endl;
		}
		cout << endl;
		cout << "Enter your Name: ";
		cin >> n;
		cout << endl;
		cout << "Enter your Gender: ";
		cin >> g;
		cout << endl;
		cout << "Enter your Phone number: ";
		cin >> ph;
		cout << endl;
		cout << "Enter your address: ";
		cin >> add;
		cout << endl;

		Manager C(n, p, ph, add, c, g);
		write<Manager>(file, C);
		cout << "*********************************************************************************" << endl;
	}


	void LoginAdmin()
	{
		Admin A;
		string adminn, adminp;
		string file = "Admin.bin";
		cout << "*********************************************************************************" << endl;
		cout << "Enter admin login credintials:" << endl;
		cin >> adminn;
		cout << endl;
		cout << "Enter admins password:";
		cin >> adminp;
		cout << endl;
		while (!(read<Admin>(file, adminn, adminp, A)))
		{
			cout << "Enter correct credentials:" << endl;
			cout << "Enter admin Username credintials:" << endl;
			cin >> adminn;
			cout << endl;
			cout << "Enter admin's password:";
			cin >> adminp;
			cout << endl;
		}
		cout << "Credintials matches!" << endl;
		cout << "*********************************************************************************" << endl;
	}


};



int main()
{
	int choice = 9;
	do
	{
		cout << "*********************************************************************************" << endl;
		cout << endl << endl << endl;
		cout << "                     Welcome to the Annonymous Store!                            " << endl;
		cout << endl << endl << endl;
		cout << "                     Press 1 to Login as a Customer                              " << endl;
		cout << "                     Press 2 to Signup as a Customer                              " << endl;
		cout << "                     Press 3 to Login as a Manager                               " << endl;
		cout << "                     Press 4 to Login as an Admin                               " << endl;
		cout << "                     Press 0 to exit                                            " << endl;
		cout << endl << endl << endl;
		cin >> choice;
		while (!(choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4))
		{
			cout << "Enter Correct option" << endl;
			cin >> choice;
		}

		if (choice == 1)
		{
			
			Customer C;
			C.LoginCustomer();
			system("CLS");
			int c3 = 7;
			cout << "*********************************************************************************" << endl;
			cout << endl << endl;
			cout << "                   Press 1 Start Shopping                               " << endl;
			cout << "                   Press 2 to view feedbacks from our previous Customers" << endl;
			cout << endl << endl;
			cin >> c3;
			while (!(c3 == 1 || c3 == 2 ))
			{
				cout << "Enter Correct option" << endl;
				cin >> c3;
			}
			if (c3 == 1)
			{
				string n;
				double num;
				double Pp = 0;
				C.DisplayItems();
				cout << "Enter the item name you want to purchase: ";
				cin >> n;
				cout << endl;
				cout << "Enter the Price: ";
				cin >> num;
				cout << endl;
				if (C.checkAvail(n) == true)
				{
					Pp += num;
				}
				int c4 = 7;
				cout << "Want to continue?";
				cin >> c4;
				while (c4 != 0)
				{
					cout << "Enter the item name you want to purchase: ";
					cin >> n;
					cout << endl;
					cout << "Enter the Price: ";
					cin >> num;
					cout << endl;
					if (C.checkAvail(n) == true)
					{
						Pp += num;
					}
					cout << "Want to continue?";
					cin >> c4;
				}
				cout << "Total bill = " << Pp << endl;
				C.setTotalBill(Pp);
				int c6 = 7;
				cout << "*********************************************************************************" << endl;
				cout << "Press 1 for COD or press 2 for online payment:";
				cin >> c6;
				while (!(c6 == 1 || c6 == 2))
				{
					cout << "Enter Correct option" << endl;
					cin >> c6;
				}
				if (c6 == 1)
				{
					system("CLS");
					COD Cash;
					Cash.setBill(Pp);
					Cash.checkPayment();
				}
				if (c6 == 2)
				{
					int c7 = 7;
					cout << "Press 1 for bank transfer or 2 for JazzCash:";
					cin >> c7;
					while (!(c7 == 1 || c7 == 2))
					{
						cout << "Enter Correct option" << endl;
						cin >> c7;
					}

					if (c7 == 1)
					{
						Bank B;
						B.setBill(Pp);
						B.BankType();
					}

					if (c7 == 2)
					{
						Jazzcash J;
						J.setBill(Pp);
						J.JazzcashType();
					}

				}

				C.FeedbackWrite();
				
			}
			if (c3 == 2)
			{
				system("CLS");
				C.DisplayFeedback();
			}




		}

		if (choice == 2)
		{
			Customer C;
			C.RegisterCustomer();
			system("CLS");
			int c3 = 7;
			cout << "*********************************************************************************" << endl;
			cout << endl << endl;
			cout << "                   Press 1 Start Shopping                               " << endl;
			cout << "                   Press 2 to view feedbacks from our previous Customers" << endl;
			cout << endl << endl;
			cin >> c3;
			while (!(c3 == 1 || c3 == 2))
			{
				cout << "Enter Correct option" << endl;
				cin >> c3;
			}
			if (c3 == 1)
			{
				string n;
				double num;
				double Pp = 0;
				C.DisplayItems();
				cout << "Enter the item name you want to purchase: ";
				cin >> n;
				cout << endl;
				cout << "Enter the Price: ";
				cin >> num;
				cout << endl;
				if (C.checkAvail(n) == true)
				{
					Pp += num;
				}
				int c4 = 7;
				cout << "Want to continue?";
				cin >> c4;
				while (c4 != 0)
				{
					cout << "Enter the item name you want to purchase: ";
					cin >> n;
					cout << endl;
					cout << "Enter the Price: ";
					cin >> num;
					cout << endl;
					if (C.checkAvail(n) == true)
					{
						Pp += num;
					}
					cout << "Want to continue?";
					cin >> c4;
				}
				cout << "Total bill = " << Pp << endl;
				C.setTotalBill(Pp);
				int c6 = 7;
				cout << "*********************************************************************************" << endl;
				cout << "Press 1 for COD or press 2 for online payment:";
				cin >> c6;
				while (!(c6 == 1 || c6 == 2))
				{
					cout << "Enter Correct option" << endl;
					cin >> c6;
				}
				if (c6 == 1)
				{
					system("CLS");
					COD Cash;
					Cash.setBill(Pp);
					Cash.checkPayment();
				}
				if (c6 == 2)
				{
					int c7 = 7;
					cout << "Press 1 for bank transfer or 2 for JazzCash:";
					cin >> c7;
					while (!(c7 == 1 || c7 == 2))
					{
						cout << "Enter Correct option" << endl;
						cin >> c7;
					}

					if (c7 == 1)
					{
						Bank B;
						B.setBill(Pp);
						B.BankType();
					}

					if (c7 == 2)
					{
						Jazzcash J;
						J.setBill(Pp);
						J.JazzcashType();
					}

				}
				C.FeedbackWrite();

			}
			if (c3 == 2)
			{
				system("CLS");
				C.DisplayFeedback();
			}



		}

		if (choice == 3)
		{
			Manager M;
			M.LoginManager();
			system("CLS");
			int c = 7;
			cout << "*********************************************************************************" << endl;
			cout << endl << endl;
			cout << "                     Press 1 to add a new item                              " << endl;
			cout << "                     Press 2 display the Entire Inventory                         " << endl;
			cout << "                     Press 3 to update the Inventory                              " << endl;
			cout << "                     Press 4 to delete an Inventory                                  " << endl;
			cout << endl << endl;
			cin >> c;
			while (!( c == 1 || c == 2 || c == 3 || c == 4 ))
			{
				cout << "Enter Correct option" << endl;
				cin >> c;
			}
			if (c == 1)
			{
				int c2 = 6;
				M.addInventory();
				cout << "Wanna add another item?" << endl;
				cin >> c2;
				while (c2 != 0)
				{
					M.addInventory();
					cout << "Wanna add another item?" << endl;
					cin >> c2;
				}
				system("CLS");
			}
			if (c == 2)
			{
				M.DisplayInventory();
			}
			if (c == 3)
			{
				M.updateInventory();
			}
			if (c == 4)
			{
				M.deleteInventory();
			}


		}

		if (choice == 4)
		{
			Admin A;
			A.LoginAdmin();
			system("CLS");
			int c = 7;
			cout << "*********************************************************************************" << endl;
			cout << endl << endl;
			cout << "                     Press 1 to Make a new Manager                              " << endl;
			cout << "                     Press 2 display the Entire Catalog                         " << endl;
			cout << "                     Press 3 to update the Catalog                              " << endl;
			cout << "                     Press 4 to delete an item                                  " << endl;
			cout << "                     Press 5 to add a new item                                  " << endl;
			cout << endl << endl;
			cin >> c;
			while (!(c == 1 || c == 2 || c == 3 || c == 4 || c==5))
			{
				cout << "Enter Correct option" << endl;
				cin >> c;
			}
			if (c == 1)
			{
				A.makeManager();
			}

			if (c == 2)
			{
				A.DisplayCatalog();
			}
			if (c == 3)
			{
				A.updateCatalog();
			}
			if (c == 4)
			{
				A.deleteCatalog();
			}
			if (c == 5)
			{
				A.addCatalog();
			}


			
		}





		cout << "*********************************************************************************" << endl;
	} while (choice != 0);
	

}





















/*

void Start()
{
	int c = 5;
	do
	{
		system("CLS");
		cout << "******************************************" << endl;
		cout << "*                                        *" << endl;
		cout << "*                                        *" << endl;
		cout << "*                                        *" << endl;
		cout << "*                                        *" << endl;
		cout << "*    Welcome to to Maam Hira's Store     *" << endl;
		cout << "*    Press 1 for to Register             *" << endl;
		cout << "*    Press 2 for to Login                *" << endl;
		cout << "*    Press 0 for to Exit                 *" << endl;
		cout << "*                                        *" << endl;
		cout << "*                                        *" << endl;
		cout << "*                                        *" << endl;
		cout << "*                                        *" << endl;
		cout << "******************************************" << endl;

		cout << "Please choose(0,1,2): ";
		cin >> c;
		while (c < 0 && c > 2)
		{
			cout << "Invalid input. Enter valid option(0,1,2): ";
			cin >> c;
		}
		switch (c)
		{
		case 0:
			cout << endl << endl << endl << "***********************" << endl;
			cout << "Thank You for shopping!" << endl;
			cout << "***********************" << endl;
			break;
		case 1:
			int cn = 4;
			system("CLS");
			cout << "******************************************" << endl;
			cout << "*                                        *" << endl;
			cout << "*                                        *" << endl;
			cout << "*                                        *" << endl;
			cout << "*                                        *" << endl;
			cout << "*    Welcome to the Registration Page    *" << endl;
			cout << "*    Press 1 for Customer                *" << endl;
			cout << "*    Press 0 for to Exit                 *" << endl;
			cout << "*                                        *" << endl;
			cout << "*                                        *" << endl;
			cout << "*                                        *" << endl;
			cout << "*                                        *" << endl;
			cout << "******************************************" << endl;

			cout << "Please choose(0,1): ";
			cin >> cn;
			while (cn < 0 && cn > 1)
			{
				cout << "Invalid input. Enter valid option(0,1,2): ";
				cin >> cn;
			}
			switch (cn)
			{
			case 0:
				cout << endl << endl << endl << "***********************" << endl;
				cout << "Thank You for shopping!" << endl;
				cout << "***********************" << endl;
				break;
			case 1:
				Register();
				break;
			default:
				cout << "Invalid Input" << endl;
				system("pause");
			}








			break;
		case 2:
			//Login();










			break;
		default:
			cout << "Invalid Input" << endl;
			system("pause");
		}








	} while (c != 0);





}


*/



