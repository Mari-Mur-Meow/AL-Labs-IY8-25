//Маурина В14
#include <iostream>
#include <string>
#include "invoice.h"

using namespace std;
template <typename _Ty>
static void static_print(_Ty s) {
	s.print(); cout << endl;
}

int main() {
	invoice Bank1("Masha", 485250, 20, 4);
	privilege bank2("Kolia", 48500, 2, 10, 23);
	cout << "Dynamic"<< endl;
	invoice* in;
	in = &Bank1;
	in->print();
	cout << endl;
	in = &bank2;
	in->print();
	cout << endl;
	cout << "Static" << endl;
	static_print(Bank1);
	cout << endl;
	static_print(bank2);
	cout << "Sum" << endl;
	double sum1 = Bank1.sum();
	double sum2 = bank2.sum();
	cout << "sum1=" << sum1<<endl;
	cout << "sum2 = " << sum2;
}



