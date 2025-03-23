#include<iostream>
#include <string>
using namespace std;
#pragma once

class invoice {
protected:
	string name;
	double balance;
	double percent;
	int years;
public:
	invoice();
	invoice(string nam, double balanc, double percen, int year);
	virtual double sum();
	virtual void print();
	/*string get_name();
	double get_balance();
	double get_percent();
	int get_years();*/

};

class privilege : public invoice {
	double privpercent;
public:
	privilege();
	privilege(string nam, double balanc, double percen, int year, double priv);
	void print();
	double sum();
	//double get_privpercent();
};
