#include <gtest/gtest.h>

#include "Primes/Find_prime.cpp"
#include "Primes/Menu.cpp"
#include "Primes/Primes.cpp"
#include "Tests/Test.cpp"
#include "Primes/Primes.cpp"

/**
  * @author Eugene Gusarov
  * @details Algorithm of find prime - sieve of Eratosthenes
  */

int main(int argc, char *argv[]) {
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
