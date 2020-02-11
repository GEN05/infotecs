#include <vector>

#include "write.cpp"

/**
 * @author Eugene Gusarov
 */

bool is_toN;

class find_prime {
public:
    static void fill(std::vector<bool> sieveOfEratosthenes) {
        std::vector<int> answer;
        for (int i = 1; i < sieveOfEratosthenes.size(); i++) {
            if (!sieveOfEratosthenes[i]) {
                answer.push_back(i);
            }
        }
        write::write_to(answer);
    }

    static void find_Prime_1_to_n(int n) {
        std::vector<bool> sieveOfEratosthenes;
        sieveOfEratosthenes.resize(n + 1);
        for (int i = 2; i * i <= n; i++) {
            if (!sieveOfEratosthenes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieveOfEratosthenes[j] = true;
                }
            }
        }
        fill(sieveOfEratosthenes);
    }

    static void find_prime_() {
        int max = UINT32_MAX / 10;
        std::vector<bool> sieveOfEratosthenes;
        sieveOfEratosthenes.resize(max);
        for (int i = 2; i * i <= max; i++) {
            if (!sieveOfEratosthenes[i]) {
                for (int j = i * i; j <= max; j += i) {
                    sieveOfEratosthenes[j] = true;
                }
            }
        }
        fill(sieveOfEratosthenes);
    }

    static void check(bool flag) {
        is_toN = flag;
    }

    static void to_N(int n) {
        if (is_toN) {
            find_Prime_1_to_n(n);
        } else {
            find_prime_();
        }
    }
};
