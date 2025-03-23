/*Маурина Мария Иу8-25 
вариант 14. лабораторная работа 4 
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
#include <algorithm>

int main() {
	std::deque<Book> book_deq;
	std::list<Book> book_list;

	std::ifstream in("input.txt");
	for (int i = 0; i < 3; i++) {
		std::string fio, name, publish;
		int year, pages;
		getline(in, fio);
		getline(in, name);
		getline(in, publish);
		in >> year >> pages;
		in.ignore();
		book_deq.push_back(Book(fio, name, publish, year, pages));
		//std::cout << fio<< " / "<< name << " / "<< publish << " / " << year << " / " << pages << " / "<< "\n";
	}
	in.close();
	//std::cout << book_deq[0];

	std::ofstream of("output.txt");
	of << " Deque = default" << "\n";
	for (int i = 0; i < 3; i++) {
		of << book_deq[i];
	}
	sort(book_deq.begin(), book_deq.end());
	of <<"\n"<< " Deque = sort" << "\n";
	for (int i = 0; i < 3; i++) {
		of << book_deq[i];
	}
	
	copy(book_deq.begin(),book_deq.end(), std::back_inserter(book_list) );
	of << "\n" << " List" << "\n";
	for (const auto& elem : book_list) {
		of << elem;
	}
	return 0;
}