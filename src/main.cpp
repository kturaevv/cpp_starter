#include <iostream>

#include "hashmap.hpp"

int main() {
    HashMap<std::string, int> myMap;
    myMap.insert("apple", 5);
    myMap.insert("banana", 10);

    myMap.insert("orange", 14);
    myMap.remove("orange");

    std::cout << myMap.get("banana") << std::endl;
    std::cout << myMap.contains("banana") << std::endl;

    myMap.read();

    return 0;
}
