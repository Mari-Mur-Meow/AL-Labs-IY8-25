#include <string>
#include <iostream>

class Book {
    std::string fio = "";
    std::string name = "";
    std::string publish = "";
    int year = 0;
    int pages = 0;
    inline friend std::ostream& operator<<(std::ostream& out, const Book& book);

public:
    Book() {
        fio = "";
        name = "";
        publish = "";
        year = 0;
        pages = 0;
    } // конструктор без параметров
    
     //  онструктор с параметрами
    Book(const std::string& Fio, const std::string& Name, const std::string& Publish, int Year, int Pages)
        : fio(Fio), name(Name), publish(Publish), year(Year), pages(Pages) {
    }

    Book(const Book& current) : fio(current.fio), name(current.name), publish(current.publish), year(current.year), pages(current.pages) {};// конструктор копировани€

    //  онструктор перемещени€
    Book(Book&& current) noexcept
        : fio(std::move(current.fio)),
        name(std::move(current.name)),
        publish(std::move(current.publish)),
        year(current.year),
        pages(current.pages) {
        current.year = 0;
        current.pages = 0;
    }

    // ќператор присваивани€ с копированием
    Book& operator=(const Book& current) {
        if (this != &current) {
            fio = current.fio;
            name = current.name;
            publish = current.publish;
            year = current.year;
            pages = current.pages;
        }
        return *this;
    }

    // ќператор присваивани€ с перемещением
    Book& operator=(Book&& current) noexcept {
        if (this != &current) {
            fio = std::move(current.fio);
            name = std::move(current.name);
            publish = std::move(current.publish);
            year = current.year;
            pages = current.pages;
            current.year = 0;
            current.pages = 0;
        }
        return *this;
    }
    bool operator<(const Book& other) const {
        return fio < other.fio;
    }
};

// ѕерегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << "FIO: " << book.fio << ", Name: " << book.name << ", Publish: " << book.publish << ", Year: " << book.year << ", Pages: " << book.pages << "\n";
    return out;
}
