#include <string>
#include <iostream>

class Book {
    friend struct BookHasher;
    std::string fio = "";
    std::string name = "";
    std::string publish = "";
    int year = 0;
    int pages = 0;
    inline friend std::ostream& operator<<(std::ostream& out, const Book& book);

public:
    bool operator<(const Book& other) const {
        return fio < other.fio;
    }
    bool operator==(const Book& ob2) const
    {
        return  fio == ob2.fio && name == ob2.name && publish == ob2.publish && year == ob2.year && pages == ob2.pages;
    }
    Book() {
        fio = "";
        name = "";
        publish = "";
        year = 0;
        pages = 0;
    } // конструктор без параметров

     // Конструктор с параметрами
    Book(const std::string& Fio, const std::string& Name, const std::string& Publish, int Year, int Pages)
        : fio(Fio), name(Name), publish(Publish), year(Year), pages(Pages) {
    }

    Book(const Book& current) : fio(current.fio), name(current.name), publish(current.publish), year(current.year), pages(current.pages) {};// конструктор копирования

    // Конструктор перемещения
    Book(Book&& current) noexcept
        : fio(std::move(current.fio)),
        name(std::move(current.name)),
        publish(std::move(current.publish)),
        year(current.year),
        pages(current.pages) {
        current.year = 0;
        current.pages = 0;
    }

    // Оператор присваивания с копированием
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

    // Оператор присваивания с перемещением
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
};

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << "FIO: " << book.fio << ", Name: " << book.name << ", Publish: " << book.publish << ", Year: " << book.year << ", Pages: " << book.pages << "\n";
    return out;
}

// Хешер для Person 
struct BookHasher
{
    // Хешеры для отдельных полей 
    std::hash<std::string> fhash;
    std::hash<std::string> nhash;
    std::hash<std::string> phash;
    std::hash<int> yhash;
    std::hash<int> ghash;
    size_t operator()(const Book& ob) const
    {
        const size_t coef = 2'946'901; // 5171;// 11171;// 103141;// 2'946'901; 
        // Получаем комбинированный хеш 
        return (
            coef * coef * coef * coef * fhash(ob.fio) +
            coef * coef * coef * nhash(ob.name) +
            coef * coef * phash(ob.publish) +
            coef* yhash(ob.year)+
            ghash(ob.pages)
            );
    }
};