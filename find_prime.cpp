/**
 * @author Eugene Gusarov
 */

#include "write.cpp"

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
};
