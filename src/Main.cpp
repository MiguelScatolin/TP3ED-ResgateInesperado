#include <iostream>

int main() {
    try {
        std::cout << "Teste";

        return 0;
    }
    catch (char exception[]) {
        std::cout << exception;
        return -1;
    }
}