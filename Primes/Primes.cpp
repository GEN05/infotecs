#include <fstream>
#include <cmath>

MyPrime::MyPrime() = default;

void MyPrime::build() {
    if (Size == 0) {
        std::vector<bool> sieveOfEratosthenes;
        sieveOfEratosthenes.resize(maximum - 32);
        for (ui i = 2; i * i < sieveOfEratosthenes.size(); i++) {
            if (!sieveOfEratosthenes[i]) {
                for (ui j = i * i; j < sieveOfEratosthenes.size(); j += i) {
                    sieveOfEratosthenes[j] = true;
                }
            }
        }
        for (ui i = 1; i < sieveOfEratosthenes.size(); i++) {
            if (!sieveOfEratosthenes[i]) {
                push_back(i);
            }
        }
    }
}

void MyPrime::build_to_n(ui max) {
    if (Size == 0) {
        std::vector<bool> sieveOfEratosthenes;
        sieveOfEratosthenes.resize(max + 1);
        for (ui i = 2; i * i <= max; i++) {
            if (!sieveOfEratosthenes[i]) {
                for (ui j = i * i; j <= max; j += i) {
                    sieveOfEratosthenes[j] = true;
                }
            }
        }
        for (ui i = 1; i < sieveOfEratosthenes.size(); i++) {
            if (!sieveOfEratosthenes[i]) {
                push_back(i);
            }
        }
    } else if (max > Size) {
        if (Size - max >= 10000) {
            clear();
            build_to_n(max);
            return;
        } else {
            for (int i = Size; i <= max; i++) {
                if (isPrime(i)) {
                    push_back(i);
                }
            }
        }
    }
}

void MyPrime::build_n(ui max) {
    if (Size == 0) {
        std::vector<bool> sieveOfEratosthenes;
        if (maximum / 6 < max) {
            sieveOfEratosthenes.resize(max + 1);
        } else {
            sieveOfEratosthenes.resize(max * 6);
        }
        for (ui i = 2; i * i < sieveOfEratosthenes.size(); i++) {
            if (!sieveOfEratosthenes[i]) {
                for (ui j = i * i; j < sieveOfEratosthenes.size(); j += i) {
                    sieveOfEratosthenes[j] = true;
                }
            }
        }
        for (ui i = 1; i < sieveOfEratosthenes.size() && Size < max; i++) {
            if (!sieveOfEratosthenes[i]) {
                push_back(i);
            }
        }
        if (Size < max) {
            for (int i = prime[prime.size() - 1]; i < maximum && Size < max; i++) {
                if (isPrime(i)) {
                    push_back(i);
                }
            }
        }
    } else if (max > Size) {
        if (Size - max >= 10000) {
            clear();
            build_n(max);
            return;
        } else {
            for (int i = prime[prime.size() - 1]; i < maximum && Size < max; i++) {
                if (isPrime(i)) {
                    push_back(i);
                }
            }
        }
    }
}

void MyPrime::write() {
    console ? to_console() : to_file();
}

void MyPrime::resize(ui size) {
    prime.resize(size);
}

void MyPrime::clear() {
    prime.clear();
    Size = 0;
}

void MyPrime::push_back(ui value) {
    prime.push_back(value);
    Size++;
}

bool MyPrime::isPrime(ui k) {
    for (ui i = 2; i <= sqrt(k); i++) {
        if (k % i == 0) {
            return false;
        }
    }
    return true;
}

void MyPrime::to_console() {
    switch (special) {
        case 1:
            for (int i : prime) {
                for (int j = 2; j < 10; j++) {
                    if (pow(pow(2, j) - 1, 2) - 2 == i) {
                        std::cout << i << std::endl;
                    }
                }
            }
            break;
        case 2:
            for (int i : prime) {
                for (int j = 1; j < 31; j++) {
                    if (pow(2, j) - 1 == i) {
                        std::cout << i << std::endl;
                    }
                }
            }
            break;
        case 3:
            for (ui i = 0; i < prime.size() && (toN ? prime[i] : i) < _max; i++) {
                std::cout << prime[i] << std::endl;
            }
            break;
        case 4:
            for (int i : prime) {
                for (int j = 0; j < 6; j++) {
                    if (pow(2, pow(2, j)) + 1 == i) {
                        std::cout << i << std::endl;
                    }
                }
            }
            break;
        default:
            throw std::exception();
    }
}

void MyPrime::to_file() {
    std::string filename;
    std::cout << "";
    std::cout << "Please input filename with type. Example: out.txt" << std::endl;
    std::cin >> filename;
    std::ofstream out;
    if (filename.empty()) {
        out.open("out.txt");
    } else {
        out.open(filename);
    }
    if (out.is_open()) {
        switch (special) {
            case 1:
                for (int i : prime) {
                    for (int j = 2; j < 10; j++) {
                        if (pow(pow(2, j) - 1, 2) - 2 == i) {
                            out << i << std::endl;
                        }
                    }
                }
                break;
            case 2:
                for (int i : prime) {
                    for (int j = 0; j < 31; j++) {
                        if (pow(2, j) - 1 == i) {
                            out << i << std::endl;
                        }
                    }
                }
                break;
            case 3:
                for (ui i = 0; i < prime.size() && (toN ? prime[i] : i) < _max; i++) {
                    out << prime[i] << std::endl;
                }
                break;
            case 4:
                for (int i : prime) {
                    for (int j = 0; j < 6; j++) {
                        if (pow(2, pow(2, j)) + 1 == i) {
                            out << i << std::endl;
                        }
                    }
                }
                break;
            default:
                throw std::exception();
        }
    }
    out.close();
}

void MyPrime::go() {
    limited ? (toN ? build_to_n(_max) : build_n(_max)) : build();
}