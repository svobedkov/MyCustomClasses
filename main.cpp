#include <iostream>
#include "headers.h"

int main_menu();

int stack_f();

template<typename T>
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
                break;
            case 3:
                break;
            default:
                std::cout << "WRONG INPUT" << std::endl;
        }
    }
}

int main_menu() {
    int var;
    std::cout << "Choose container:" << std::endl << "1.Stack" << std::endl << "2.Queue" << std::endl << "3.Deque" << std::endl << "0.Exit" << std::endl;
    std::cin >> var;
    std::cin.clear();
    std::cin.ignore();
    return var;
}

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

