#include <fmt/core.h>

#include "hashmap.hpp"

int main() {
    fmt::print("CPP Starter Project!\n");

    auto hmap = HashMap<std::string, int>::init();

    hmap.insert("apple", 5);
    hmap.insert("banana", 10);

    hmap.insert("orange", 14);
    hmap.remove("orange");

    hmap.get("banana");
    hmap.contains("banana");

    hmap.read();

    return 0;
}
