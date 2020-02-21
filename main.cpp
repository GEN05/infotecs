#include <gtest/gtest.h>

#include "Primes/Menu.cpp"
#include "Primes/Primes.cpp"
#include "Tests/Test.cpp"

/**
  * @author Eugene Gusarov
  * @details Algorithm of find prime - sieve of Eratosthenes
  */

int main(int argc, char *argv[]) {
    std::cout << "Welcome!" << std::endl << "0: run tests" << std::endl << "else: start" << std::endl;
    int choose;
    std::cin >> choose;
    if (choose == 0) {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    } else {
        menu::greeting();
    }
    return 0;
}
