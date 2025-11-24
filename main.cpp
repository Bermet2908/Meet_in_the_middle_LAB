#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/dynamic_array.hpp"

int main() {
    std::string filename;

    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream in_file(filename);
    if (!in_file.is_open()) {
        std::cout << "Could not open file.\n";
        return 1;
    }

    IntDynamicArray numbers;

    std::string line;
    if (std::getline(in_file, line)) {
        std::stringstream ss(line);
        int value;
        char comma;

        while (ss >> value) {
            numbers.push_back(value);
            if (ss.peek() == ',') {
                ss >> comma; // skip comma
            }
        }
    }

    std::size_t n = numbers.size();
    if (n == 0) {
        std::cout << "The file contained no data.\n";
        return 1;
    }

    std::cout << "The median of the dataset is ";

    if (n % 2 == 1) {
        std::cout << numbers.at(n / 2);
    } else {
        int left = numbers.at(n / 2 - 1);
        int right = numbers.at(n / 2);
        int sum = left + right;

        if (sum % 2 == 0) {
            std::cout << (sum / 2);
        } else {
            std::cout << (sum / 2.0);
        }
    }

    std::cout << "." << std::endl;

    return 0;
}


