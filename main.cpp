#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string name;
    std::cout << "What is your name? ";
    std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;
    return 0;
}