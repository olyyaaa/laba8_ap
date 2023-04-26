// lab_12.08_AP.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <list>

void printList(const std::list<int>& numbers) {
    for (int n : numbers) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> numbers;
    int input;
    char choice;

    std::cout << "Enter '1' to read numbers from a file or '2' to read numbers from the keyboard: ";
    std::cin >> choice;

    if (choice == '1') {
        std::ifstream file("D://numbers.txt");
        while (file >> input) {
            numbers.push_back(input);
        }
    }
    else if (choice == '2') {
        std::cout << "Enter numbers (enter 0 to finish): ";
        while (std::cin >> input && input != 0) {
            numbers.push_back(input);
        }
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }

    std::cout << "Initial list: ";
    printList(numbers);

    for (auto it = numbers.begin(); it != numbers.end(); ) {
        if (*it % 2 == 0) {
            it = numbers.erase(it);
        }
        else {
            ++it;
        }
    }

    std::cout << "After removing even values: ";
    printList(numbers);

    int i = 1;
    for (auto& n : numbers) {
        if (i % 2 == 1) {
            n *= 2;
        }
        ++i;
    }

    std::cout << "After doubling values with odd indices: ";
    printList(numbers);

    std::list<int> sublist = { 1, 1, 1 };
    int position = 2; 
    auto it = numbers.begin();
    std::advance(it, position);
    numbers.insert(it, sublist.begin(), sublist.end());
    std::cout << "After inserting a sublist: ";
    printList(numbers);
}