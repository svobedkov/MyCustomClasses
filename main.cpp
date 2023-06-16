#include <iostream>
#include "headers.h"

int main_menu();

int stack_f();
int queue_f();
int deque_f();

template<typename T>
/*!
 * Выбор типа значений, для deque
 * @tparam T Тип значений
 */
int deque_int() {
    deque<T> my_stack;
    int var;
    while (true) {
        system("cls");
        std::cout << "Stack:" << std::endl;
        my_stack.map();
        std::cout << std::endl;
        std::cout << "Choose container:" << std::endl << "1.Push front" << std::endl << "2.Push back" << std::endl << "3.Pop front" << std::endl << "4.Pop back" << std::endl << "5.Clear" << std::endl << "0.Exit" << std::endl;
        std::cin >> var;
        std::cin.clear();
        std::cin.ignore();
        switch (var) {
            case 0:
                return 0;
            case 1:
                T x;
                std::cout << "Input: ";
                std::cin >> x;
                my_stack.push_front(x); // CHECK THIS
                break;
            case 2:
                T y;
                std::cout << "Input: ";
                std::cin >> y;
                my_stack.push_back(y); // CHECK THIS
                break;
            case 3:
                my_stack.pop_front();
                break;
            case 4:
                my_stack.pop_back();
                break;
            case 5:
                my_stack.clear();
                break;
        }
    }
}

template<typename T>
/*!
 * Выбор типа значений, для stack
 * @tparam T Тип значений
 */
int stack_int() {
    stack<T> my_stack;
    int var;
    while (true) {
        system("cls");
        std::cout << "Stack:" << std::endl;
        my_stack.map();
        std::cout << std::endl;
        std::cout << "Choose container:" << std::endl << "1.Push" << std::endl << "2.Pop" << std::endl << "3.Clear" << std::endl << "0.Exit" << std::endl;
        std::cin >> var;
        std::cin.clear();
        std::cin.ignore();
        switch (var) {
            case 0:
                return 0;
            case 1:
                T x;
                std::cout << "Input: ";
                std::cin >> x;
                my_stack.push(x); // CHECK THIS
                break;
            case 2:
                my_stack.pop();
                break;
            case 3:
                my_stack.clear();
                break;
        }
    }
}

template<typename T>
/*!
 * Выбор типа значений, для queue
 * @tparam T Тип значений
 */
int queue_int() {
    queue<T> my_stack;
    int var;
    while (true) {
        system("cls");
        std::cout << "Stack:" << std::endl;
        my_stack.map();
        std::cout << std::endl;
        std::cout << "Choose container:" << std::endl << "1.Push" << std::endl << "2.Pop" << std::endl << "3.Clear" << std::endl << "0.Exit" << std::endl;
        std::cin >> var;
        std::cin.clear();
        std::cin.ignore();
        switch (var) {
            case 0:
                return 0;
            case 1:
                T x;
                std::cout << "Input: ";
                std::cin >> x;
                my_stack.push(x); // CHECK THIS
                break;
            case 2:
                my_stack.pop();
                break;
            case 3:
                my_stack.clear();
                break;
        }
    }
}

int main() {
    while (true) {
        system("cls");
        switch (main_menu()) {
            case 0:
                return 0;
            case 1:
                stack_f();
                break;
            case 2:
                queue_f();
                break;
            case 3:
                deque_f();
                break;
            default:
                std::cout << "WRONG INPUT" << std::endl;
        }
    }
}

/*!
 * Главное меню
 */
int main_menu() {
    int var;
    std::cout << "Choose container:" << std::endl << "1.Stack" << std::endl << "2.Queue" << std::endl << "3.Deque" << std::endl << "0.Exit" << std::endl;
    std::cin >> var;
    std::cin.clear();
    std::cin.ignore();
    return var;
}

/*!
 * Управление stack'ом
 */
int stack_f() {
    system("cls");
    int temp;
    while (true) {
        system("cls");
        std::cout << "Choose type of data:" << std::endl << "1.int" << std::endl << "2.char" << std::endl << "3.double" << std::endl << "0.Exit" << std::endl;
        std::cin >> temp;
        system("cls");
        std::cin.clear();
        std::cin.ignore();
        switch (temp) {
            case 0:
                return 0;
            case 1:
                stack_int<int>();
                break;
            case 2:
                stack_int<char>();
                break;
            case 3:
                stack_int<double>();
                break;
            default:
                std::cout << "WRONG INPUT" << std::endl;
                break;
        }
    }
}

/*!
 * Управление очередью
 */
int queue_f() {
    system("cls");
    int temp;
    while (true) {
        system("cls");
        std::cout << "Choose type of data:" << std::endl << "1.int" << std::endl << "2.char" << std::endl << "3.double" << std::endl << "0.Exit" << std::endl;
        std::cin >> temp;
        system("cls");
        std::cin.clear();
        std::cin.ignore();
        switch (temp) {
            case 0:
                return 0;
            case 1:
                queue_int<int>();
                break;
            case 2:
                queue_int<char>();
                break;
            case 3:
                queue_int<double>();
                break;
            default:
                std::cout << "WRONG INPUT" << std::endl;
                break;
        }
    }
}

/*!
 * Управление деком
 */
int deque_f() {
    system("cls");
    int temp;
    while (true) {
        system("cls");
        std::cout << "Choose type of data:" << std::endl << "1.int" << std::endl << "2.char" << std::endl << "3.double" << std::endl << "0.Exit" << std::endl;
        std::cin >> temp;
        system("cls");
        std::cin.clear();
        std::cin.ignore();
        switch (temp) {
            case 0:
                return 0;
            case 1:
                deque_int<int>();
                break;
            case 2:
                deque_int<char>();
                break;
            case 3:
                deque_int<double>();
                break;
            default:
                std::cout << "WRONG INPUT" << std::endl;
                break;
        }
    }
}