#include <iostream>
#include "circularbuffer.h"

int main() {
    using namespace Buffer;

    // Создаем буфер с емкостью 5
    CircularBuffer buffer(3);

    // Добавляем элементы в конец буфера
    buffer.push_back('1');
    buffer.push_back('2');
    buffer.push_back('3');

    std::cout << "буфер после push_back('1'), push_back('2'), push_back('3'):" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    buffer.push_back('4');
    buffer.push_back('5');

    std::cout << "буфер после push_back('4'), push_back('5'):" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    // Доступ к первому и последнему элементу
    std::cout << "Front element: " << buffer.front() << std::endl;
    std::cout << "Back element: " << buffer.back() << std::endl;

    // Удаляем первый и последний элементы
    buffer.pop_front();
    buffer.pop_back();

    std::cout << "буфер после pop_front() and pop_back():" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    // Проверка заполненности буфера
    std::cout << "full? " << (buffer.full() ? "Yes" : "No") << std::endl;
    std::cout << "empty? " << (buffer.empty() ? "Yes" : "No") << std::endl;

    // Изменение емкости буфера
    buffer.set_capacity(10);
    std::cout << "емкость буфера после set_capacity(10): " << buffer.capacity() << std::endl;

    // Добавление элементов для демонстрации кругового буфера
    for (char ch = 'D'; ch <= 'H'; ++ch) {
        buffer.push_back(ch);
    }

    std::cout << "текущий буфер:" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    // Показать линейный вид буфера
    buffer.linearize();
    std::cout << "буфер после линеаризации:" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    buffer.insert(3, 'f');
    std::cout << "буфер после insert(3, 'f'):" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    buffer.clear();
    std::cout << "буфер после clear():" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    buffer.push_back('A');
    std::cout << "буфер после push_back('A'):" << std::endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
