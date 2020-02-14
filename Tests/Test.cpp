//
// Created by 2000a on 13.02.2020.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        find_prime obj{};

        ClassDeclaration() = default;
    };
}

TEST_F(ClassDeclaration, With_Limit) {
    long long int count = 1;
    std::vector<int> ch;
    for (int k = 1; k <= 1000; k++) {
        for (int i = 1; i <= k; i++) {
            if (find_prime::isPrime(i)) {
                ch.push_back(i);
            }
        }
        ASSERT_THAT(obj.find_Prime_1_to_n(k), ch);
        count++;
        ch.clear();
    }
    std::cout << std::endl << count << " tests complete" << std::endl;
}

TEST_F(ClassDeclaration, Without_Limit) {
    long long int count = 1;
    int y = UINT8_MAX;
    std::vector<int> ch;
    for (int i = 1; i < y; i++) {
        if (find_prime::isPrime(i)) {
            ch.push_back(i);
        }
    }
    for (int i = 1; i < y; i++) {
        ASSERT_THAT(ch, obj.find_prime_());
        count++;
    }
    std::cout << std::endl << count << " tests complete" << std::endl;
}