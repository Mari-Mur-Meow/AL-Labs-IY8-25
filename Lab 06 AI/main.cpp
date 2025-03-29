/*
Вариант 5/
Реализовать класс «Массив – последовательность Фибоначчи». 
Поля:указатель на массив и его размерность. 
Конструкторы: конструктордляинициализации полей (через параметры передается обычныймассив). 
Принеобходимости добавить свои функции. 
При недопустимыхпараметрахобъекта создается исключение (массив не является последовательностьюФибоначчи). 
Для исключения создать класс, производныйотinvalid_argument.
Дополнительно созданный класс для исключениякроменаследуемых полей (необходимо их также использовать) 
содержитполякласса «Массив – последовательность Фибоначчи» для недопустимогообъекта и метод для печати всех данных. 
Продемонстрироватьработусобъектами в случае возникновения исключения и его обработкиибезвозникновения исключения.
*/

#include <iostream>
#include <exception>

class FibonacciArrayException : public std:: invalid_argument{ // класс для ошибок, производный от invalid_argument
    int* invalid_array;
    size_t invalid_size;

public:
    FibonacciArrayException(const std::string& message, int* arr, size_t size) // конструтор с параметрами 
        : invalid_argument(message), invalid_array(new int[size]), invalid_size(size)//список инициализации 
        {
        for (size_t i = 0; i < size; ++i) {
            invalid_array[i] = arr[i];
        }
    }

    ~FibonacciArrayException(){ // деструктор 
        delete[] invalid_array;
    }

    void printInvalidData() const { // вывод ошибочных данных 
        std::cout << "Invalid Fibanachi sequence data:" << std::endl;
        std::cout << "Size: " << invalid_size << std::endl;
        std::cout << "Array elements: ";

        for (size_t i = 0; i < invalid_size; ++i) {
            std::cout << invalid_array[i] << " ";
        }

        std::cout << std::endl;
        std::cout << "Error message: " << what() << std::endl;
    }
};


class Fibonacci_array // класс последовательность фибоначчи
{
    int *array;
    size_t size;

    // функция для проверки элементов последовательности на соотвествие последовательности фибоначчи 
    bool isFibonacciSequence(int* arr, size_t s) const {
        if (s == 0) return false;
        if (s == 1) return arr[0] == 0;
        if (s == 2) return arr[0] == 0 && arr[1] == 1;
        if (arr[0] != 0 || arr[1] != 1) { // проверка для всех, не смотря на рамзер массива 
            return false;
        }
        for (size_t i = 2; i < s; ++i) {
            if (arr[i] != arr[i-1] + arr[i-2]) { // поэлементная проверка каждого 
                return false;
            }
        }
        return true;
    }

public:
    Fibonacci_array( int* arr, size_t s) {
        if (! isFibonacciSequence(arr, s)) { // выполнение проверки 
            throw FibonacciArrayException("Provided array is not a Fibonacci sequence", arr, s); // выворд ошибки 
        }

        size = s;
        array = new int[size];
        for (size_t i = 0; i < size; i++){
            array[i] = arr[i];
        }
    }
    ~Fibonacci_array(){
        delete[] array;
    }

    void print() const { 
        std::cout << "Fibanachi sequence with " << size << " elements: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    // Без исключения
    try { // контролируемый блок 
        int correct_arr[] = {0, 1, 1, 2, 3, 5, 8};
        Fibonacci_array fa1(correct_arr, 7);
        fa1.print();
    } catch (const FibonacciArrayException& e) {
        e.printInvalidData();
    }


    std::cout << std::endl;

    // С исключением
    try {
        int false_arr[] = {0, 1, 13, 3, 5, 8}; 
        Fibonacci_array fa2(false_arr, 6);
        std::cout << "Successfully created FibonacciArray object:" << std::endl;
        fa2.print();
    } catch (const FibonacciArrayException& e) {
        std::cout << "Caught FibonacciArrayException:" << std::endl;
        e.printInvalidData();
    }

    return 0;
}