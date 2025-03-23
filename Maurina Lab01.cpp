/*Вариант 13 Маурина Мария ИУ8-25
Класс - программа- антивирус. Параметры (поля класса): название, число вредоносных программ в базе.
Статус доступа всех полей private. Класс включает: конструктор, при необходимости функции доступа к полям,
функцию печати параметров.
Вывести на печать параметры антивирусов и антивирус с самой большой базой вредоносных программ.*/

#include <iostream> 
#include <string>
#include <vector> 
#include <fstream> 
using namespace std;
class antivirus {
private:
	string name;
	int all;
public:
	antivirus() {
		all = 0;
		name = "";
	}

	void set(string nam, int nom) {
		name = nam;
		all = nom;
	}

	antivirus(string nam, int nom) {
		name = nam;
		all = nom;
	}
	void set_all(int nom) {
		all = nom;
	}

	void set_name(string nam) {
		name = nam;
	}

	int get_all() {
		return all;
	}

	string get_name() {
		return name;
	}

	void print() const {
		cout << "name:" << name << ", kol-vo: " << all;
	}

	string printo() const {
		return "name: " + name + " " + " kol-vo: " + to_string(all);
	}
};

int main() {
	ifstream f;
	ofstream out;
	f.open("baza.txt");
	out.open("out.txt");
	vector <antivirus> vecanti;
	while (!f.eof()) {
		string str;
		int nom;
		f >> str >> nom;
		vecanti.push_back(antivirus(str, nom));
		vecanti.back().print();
		out << "name:" << vecanti.back().get_name() << " " << " kol-vo: " << vecanti.back().get_all() << endl;
		cout << endl;
	}
	int maxn = 0;
	int maxi;
	for (int i = 0; i < vecanti.size(); i++) {
		if (vecanti[i].get_all() > maxn) {
			maxn = vecanti[i].get_all();
			maxi = i;
		}
	}
	cout << endl;
	cout << " max. baza"; out << endl << " max. baza ";
	vecanti[maxi].print(); out << vecanti[maxi].printo();
}
