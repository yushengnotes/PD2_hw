#include <iostream>
#include <map>

int main() {
    // Creating a map m
    std::map<int, std::string> m;

    // Inserting values into the map
    m.insert({1, "apple"});
    m.insert({2, "banana"});
    m.insert({3, "cherry"});

    // Accessing elements using keys
    std::cout << "Element with key 1: " << m[1] << "\n";
    std::cout << "Element with key 2: " << m[2] << "\n";

    // Iterating over map
    std::cout << "Iterating over map:\n";
    for(auto it = m.begin(); it != m.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    }
}
