#include <iostream>
#include <vector>
#include <limits>

#include "menu.cpp"

/**
 * @author Eugene Gusarov
 * Algorithm of find prime - sieve of Eratosthenes
 */

int n;

//class Primes
//{
//public:
//    Primes(uint32_t max); // контейнер простых чисел в диапазоне 1..max
//    Primes(); // контейнер простых чисел без верхней границы
//    class Iterator{…};
//    Iterator begin();
//    Iterator end();  // для контейнера без верхней границы end() достижим только в пустом контейнере
//    uint32_t size();
//    uint32_t operator[](uint32_t index);    ??? шо це такое
//};

int main() {
    menu::greeting();
    std::cout << "Please input limit" << std::endl;
    do {
        std::cin >> n;
        if (!std::cin) {
            std::cout << "Wrong symbol!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (n < 1) {
            std::cout << "Wrong limit!" << std::endl;
            std::cin.clear();
        } else {
            break;
        }
    } while (true);
    find_prime::find_Prime_1_to_n(n);
    return 0;
}
