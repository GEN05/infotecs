/**
 * @author Eugene Gusarov
 */
#include <iostream>
#include <ctime>
#include <limits>

#include "find_prime.cpp"

int n;

class menu {
public:
    static void time_Now() {
        time_t i;
        struct tm *tm;
        time(&i);
        tm = localtime(&i);
        std::cout << asctime(tm) << std::endl;
    }

    static void menu_With_Border() {
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

        std::cout << "1: Primes from 1 to " << n << std::endl;
        std::cout << "2: " << n << " numbers of primes" << std::endl;
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
        switch (choose) {
            case 1:
                std::cout << "case 1" << std::endl;
                break;
            case 2:
                std::cout << "case 2" << std::endl;
                break;
            default:
                std::cout << "Undefined error";
        }
    }

    static void menu_Modes() {
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
        switch (choose) {
            case 1:
                std::cout << "case 1" << std::endl;
                find_prime::check(true);
                menu_With_Border();
                break;
            case 2:
                std::cout << "case 2" << std::endl;
                find_prime::check(false);
                break;
            default:
                std::cout << "Undefined error";
        }
    }

    static void menu_Write() {
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
        switch (choose) {
            case 1:
                std::cout << "case 1" << std::endl;
                write::check(true);
                break;
            case 2:
                std::cout << "case 2" << std::endl;
                write::check(false);
                break;
            default:
                std::cout << "Undefined error";
        }
    }

    static void menu_Special_Primes() {
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
        switch (choose) {
            case 1:
                std::cout << "case 1" << std::endl;
                break;
            case 2:
                std::cout << "case 2" << std::endl;
                break;
            case 3:
                std::cout << "case 3" << std::endl;
                break;
            default:
                std::cout << "Undefined error";
        }
        find_prime::
        to_N(n);
    }

    static void greeting() {
        time_Now();
        std::cout << "Good night!" << std::endl << "Please choose what you want:" << std::endl;
        menu_Modes();
        menu_Write();
        menu_Special_Primes();
    }
};

