#include <vector>
#include <cmath>

#include "write.cpp"

/**
 * @author Eugene Gusarov
 */

bool is_toN;

class find_prime {
public:
    static std::vector<int> find_Prime_1_to_n(int n) {
        std::vector<bool> sieveOfEratosthenes;
        std::vector<int> answer;
        sieveOfEratosthenes.resize(n + 1);
        for (int i = 2; i * i <= n; i++) {
            if (!sieveOfEratosthenes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieveOfEratosthenes[j] = true;
                }
            }
        }
        for (int i = 1; i < sieveOfEratosthenes.size(); i++) {
            if (!sieveOfEratosthenes[i]) {
                answer.push_back(i);
            }
        }
        write::write_to(answer);
        return answer;
    }

    static std::vector<int> find_prime_() {
        int max = UINT8_MAX;
        std::vector<bool> sieveOfEratosthenes;
        std::vector<int> answer;
        sieveOfEratosthenes.resize(max);
        for (int i = 2; i * i <= max; i++) {
            if (!sieveOfEratosthenes[i]) {
                for (int j = i * i; j <= max; j += i) {
                    sieveOfEratosthenes[j] = true;
                }
            }
        }
        for (int i = 1; i < sieveOfEratosthenes.size(); i++) {
            if (!sieveOfEratosthenes[i]) {
                answer.push_back(i);
            }
        }
        write::write_to(answer);
        return answer;
    }

    static void check(bool ch) {
        is_toN = ch;
    }

    static void to_N(int n) {
        if (is_toN) {
            find_Prime_1_to_n(n);
        } else {
            find_prime_();
        }
    }

    static bool isPrime(int n) { // only for test
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};
