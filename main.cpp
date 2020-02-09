#include <iostream>
#include <vector>
#include <ctime>
#include <limits>

/**
 * @author Eugene Gusarov
 * Algorithm of find prime - sieve of Eratosthenes
 */

std::vector<bool> sieveOfEratosthenes;
std::vector<int> answer;
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

void time_Now() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    std::cout << asctime(timeinfo) << std::endl;
}

void menu_With_Border() {
    std::cout << "1: Primes from 1 to ..." << std::endl;
    std::cout << "2: ... numbers of primes" << std::endl;
    int choose;
    do {
        std::cin >> choose;
        if (!std::cin || choose < 1 || choose > 2) {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
}

void menu_Modes() {
    std::cout << "1: Primes with border" << std::endl;
    std::cout << "2: Primes without border" << std::endl;
    int choose;
    do {
        std::cin >> choose;
        if (!std::cin || choose < 1 || choose > 2) {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
    if (choose == 1) {
        menu_With_Border();
    }
}

void menu_Write() {
    std::cout << "1: Write to console" << std::endl;
    std::cout << "2: Write to file ..." << std::endl;
    int choose;
    do {
        std::cin >> choose;
        if (!std::cin || choose < 1 || choose > 2) {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
}

void menu_Special_Primes() {
    std::cout << "1: Superprimes " << std::endl;
    std::cout << "2: Primes of Sofi Garmen" << std::endl;
    std::cout << "3: Classic primes" << std::endl;
    int choose;
    do {
        std::cin >> choose;
        if (!std::cin || choose < 1 || choose > 3) {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
}

void greeting() {
    time_Now();
    std::cout << "Good night!" << std::endl << "Please choose what you want:" << std::endl;
    menu_Modes();
    menu_Write();
    menu_Special_Primes();
}

void fill() {
    for (int i = 1; i < sieveOfEratosthenes.size(); i++) {
        if (!sieveOfEratosthenes[i]) {
            answer.push_back(i);
        }
    }
}

void find_Prime_1_to_n() {
    for (int i = 2; i * i <= n; i++) {
        if (!sieveOfEratosthenes[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieveOfEratosthenes[j] = true;
            }
        }
    }
    fill();
}

void write() {
    for (int i = 1; i <= n; i++) {
        if (!sieveOfEratosthenes[i]) {
            std::cout << i << std::endl;
        }
    }
}

int main() {
    greeting();
    do {
        std::cin >> n;
        if (!std::cin || n < 1) {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
    sieveOfEratosthenes.resize(n + 1);
    find_Prime_1_to_n();
    write();
    return 0;
}
