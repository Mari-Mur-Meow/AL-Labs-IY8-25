#include "invoice.h"

invoice::invoice() {
	name = ' ';
	balance = 0;
	percent = 0;
	years = 0;
}
invoice::invoice(string nam, double balanc, double percen, int year) {
	name = nam;
	balance = balanc;
	percent = percen;
	years = year;
 }
double invoice::sum() {
	double sum;
	sum = this->balance;
	for (int i = 0; i < this->years; i++) {
		sum += sum * (this->percent);
	}
	return sum;
}
void invoice::print() {
	cout << "FIO: " << name << endl;
	cout << "Nach. balance: " << balance << endl;
	cout << "Percent: " << percent << endl;
	cout << "Years: " << years << endl;
 }
/*string invoice::get_name() {
	return this->name;
}
double invoice::get_balance(){
	return this->balance;
}

double invoice::get_percent() {
	return this->percent;
}

int invoice::get_years() {
	return this->years;
}*/

privilege::privilege() : invoice() {
	privpercent = 0;
}

privilege::privilege(string nam, double balanc, double percen, int year, double priv)
	: invoice (nam, balanc, percen ,year) {
	privpercent = priv;
}

void privilege::print() {
	invoice::print();
	cout << "privpercent: " << privpercent << endl ;
}

double privilege::sum() {
	double sum;
	double percen;
	percen = this->percent + this->privpercent;
	sum = this->balance;
	for (int i = 0; i < this->years; i++) {
		sum += sum * percen;
	}
	return sum;
}
/*
double privilege::get_privpercent() {
	return this->privpercent;
}*/