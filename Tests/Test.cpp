////
//// Created by 2000a on 13.02.2020.
////
//#include <gtest/gtest.h>
//#include <gmock/gmock.h>
//
//using testing::Eq;
//
//namespace {
//    class Testing : public testing::Test {
//    public:
//        find_prime obj{};
//
//        Testing() = default;
//    };
//}
//
//TEST_F(Testing, With_Limit) {
//    long long int count = 1;
//    std::vector<int> ch;
//    for (int k = 1; k <= 1000; k++) {
//        for (int i = 1; i <= k; i++) {
//            if (find_prime::isPrime(i)) {
//                ch.push_back(i);
//            }
//        }
//        ASSERT_THAT(obj.build_to_n(k), ch);
//        count++;
//        ch.clear();
//    }
//    std::cout << std::endl << count << " tests complete" << std::endl;
//}
//
//TEST_F(Testing, Without_Limit) {
//    long long int count = 1;
//    int y = UINT8_MAX;
//    std::vector<int> ch;
//    for (int i = 1; i < y; i++) {
//        if (find_prime::isPrime(i)) {
//            ch.push_back(i);
//        }
//    }
//    for (int i = 1; i < y; i++) {
//        ASSERT_THAT(ch, obj.build());
//        count++;
//    }
//    std::cout << std::endl << count << " tests complete" << std::endl;
//}
//
//TEST_F(Testing, n_prime_with_limit) {
//    long long count_test = 1;
//    int count = 300, i = 1;
//    std::vector<int> check;
//    while (count > check.size()) {
//        if (find_prime::isPrime(i))
//            check.push_back(i);
//        i++;
//    }
//    ASSERT_THAT(check, obj.build_n(count));
//}