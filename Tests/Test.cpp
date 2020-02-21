//
// Created by 2000a on 13.02.2020.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(PrimesTest, With_Limit_to_n) {
    long long int count = 1;
    MyPrime mp;
    std::vector<int> ch;
    for (int k = 1; k <= 1000; k++) {
        for (int i = 1; i <= k; i++) {
            if (MyPrime::isPrime(i)) {
                ch.push_back(i);
            }
        }
        _max = k;
        limited = true;
        toN = true;
        mp.go();
        ASSERT_THAT(mp.prime, ch);
        count++;
        ch.clear();
    }
    std::cout << std::endl << count << " tests complete" << std::endl;
}

TEST(PrimesTest, With_Limit_n) {
    long long int count = 1;
    MyPrime mp;
    std::vector<int> ch;
    for (int k = 1; k <= 100; k++) {
        for (int i = 1; ch.size() < k; i++) {
            if (MyPrime::isPrime(i)) {
                ch.push_back(i);
            }
        }
        _max = k;
        limited = true;
        toN = false;
        mp.go();
        ASSERT_THAT(mp.prime, ch);
        count++;
        ch.clear();
    }
    std::cout << std::endl << count << " tests complete" << std::endl;
}
//
//TEST(PrimesTest, Without_Limit) {
//    long long int count = 1;
//    MyPrime mp;
//    std::vector<int> ch;
//    for (int i = 1; i < INT32_MAX - 32; i++) {
//        if (MyPrime::isPrime(i)) {
//            ch.push_back(i);
//        }
//    }
//    limited = false;
//    mp.go();
//    ASSERT_THAT(mp.prime, ch);
//    count++;
//    std::cout << std::endl << count << " tests complete" << std::endl;
//}
