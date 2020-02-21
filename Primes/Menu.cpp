/**
 * @author Eugene Gusarov
 */

#include <iostream>
#include <ctime>
#include <limits>
#include <fstream>
#include "Primes.h"

typedef uint32_t ui;

ui n;
bool flag = true, first = true;

class menu {
public:

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
        _max = n;
        std::cout << "1: Primes from 1 to " << n << std::endl;
        std::cout << "2: " << n << " numbers of primes" << std::endl;
        ui choose;
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
                toN = true;
                break;
            case 2:
                toN = false;
                break;
            default:
                throw std::runtime_error("Undefined error");
        }
    }

    static void menu_Modes() {
        std::cout << "0: Exit" << std::endl;
        std::cout << "1: Primes with border" << std::endl;
        std::cout << "2: Primes without border" << std::endl;
        ui choose;
        do {
            std::cin >> choose;
            if (!std::cin || choose < 0 || choose > 2) {
                std::cout << "Wrong input!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);
        switch (choose) {
            case 0:
                flag = false;
                break;
            case 1:
                limited = true;
                menu_With_Border();
                break;
            case 2:
                limited = false;
                break;
            default:
                throw std::runtime_error("Undefined error");
        }
    }

    static void menu_Write() {
        std::cout << "1: Write to console" << std::endl;
        std::cout << "2: Write to file ..." << std::endl;
        ui choose;
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
                console = true;
                break;
            case 2:
                console = false;
                break;
            default:
                throw std::runtime_error("Undefined error");
        }
    }

    static void menu_Special_Primes() {
        std::cout << "1: Carol primes" << std::endl;
        std::cout << "2: Mersenne primes" << std::endl;
        std::cout << "3: Classic primes" << std::endl;
        std::cout << "4: Fermat primes" << std::endl;
        ui choose;
        do {
            std::cin >> choose;
            if (!std::cin || choose < 1 || choose > 4) {
                std::cout << "Wrong input!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);
        switch (choose) {
            case 1:
                special = 1;
                break;
            case 2:
                special = 2;
                break;
            case 3:
                special = 3;
                break;
            case 4:
                special = 4;
                break;
            default:
                throw std::runtime_error("Undefined error");
        }
    }

    static void greeting() {
        MyPrime Prime;
        std::cout << "Please choose what you want:" << std::endl;
        std::ofstream output;
        while (true) {
            menu_Modes();
            if (!flag) break;
            menu_Write();
            menu_Special_Primes();
            ui start_time = clock();
            Prime.go();
            ui semi_time = clock();
            Prime.write();
            ui final_time = clock();
            std::string filename;
            std::cout << "Please input filename with type. Example: out.txt" << std::endl;
            std::cin >> filename;
            if (filename.empty()) {
                output.open("stat.txt", std::ios::app | std::ios::ate);
            } else {
                output.open(filename, std::ios::app | std::ios::ate);
            }
            time_t i;
            struct tm *tm;
            time(&i);
            tm = localtime(&i);
            if (output.is_open()) {
                output << asctime(tm)
                       << std::endl << "is limited: " << limited
                       << std::endl << "is console: " << console
                       << std::endl << "is to N: " << toN
                       << std::endl << "limit: " << _max
                       << std::endl << "special mode: " << special
                       << std::endl << "calculate time: " << semi_time - start_time
                       << std::endl << "write time: " << final_time - semi_time
                       << std::endl << "total time: " << final_time - start_time
                       << std::endl << std::endl;
            }
        }
        output.close();
    }
};
