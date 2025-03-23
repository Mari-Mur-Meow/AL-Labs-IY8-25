/*Маурина Мария Иу8-25
вариант 14. лабораторная работа 5
условие 4 лр 
Обеспечить копирование одного контейнера в другой с помощью алгоритма
 std::copy. А также сортировку объектов в исходном контейнере, для шаблона list при
 сортировке использовать метод list::sort без параметров, для шаблона vector или deque
 при сортировке использовать алгоритм std::sort с двумя параметрами: итератор на начало
 и итератор на конец контейнера

Объект-книга(поля: ФИО автора, название, издательство, год издания, число страниц)
Сортировка по ФИО
Исходный контейнер deque, копируем в list
*/

#include "Source.cpp"
#include <deque>
#include <list>
#include <fstream>
#include <set>
#include <unordered_set>
#include <algorithm>

int main() {
	//std::deque<Book> book_deq;
	std::list<Book> book_list;
	std::unordered_set<Book,BookHasher> un_setBook;
	std::set<Book> setBook;

	std::ifstream in("input.txt");
	for (int i = 0; i < 4; i++) {
		std::string fio, name, publish;
		int year, pages;
		getline(in, fio);
		getline(in, name);
		getline(in, publish);
		in >> year >> pages;
		in.ignore();
		un_setBook.insert(Book(fio, name, publish, year, pages));
		setBook.insert(Book(fio, name, publish, year, pages));
		//std::cout << fio<< " / "<< name << " / "<< publish << " / " << year << " / " << pages << " / "<< "\n";
	}
	in.close();

	std::ofstream of("output.txt");
	of << " unsetBook" << "\n";
	for (const auto& elem : un_setBook) {
		of << elem;
	}

	of << "\n"<< "setBook" << "\n";
	for (const auto& elem : setBook) {
		of << elem;
	}

	copy(un_setBook.begin(), un_setBook.end(), std::back_inserter(book_list));

	of << "\n" << " List" << "\n";
	for (const auto& elem : book_list) {
		of << elem;
	}
	return 0;

	
}