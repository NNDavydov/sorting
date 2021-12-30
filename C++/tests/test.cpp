// Copyright Davydov Nikolay 2021 <davy.nikola@gmail.com>
#include <gtest/gtest.h>
#include <vector>
#include <list>

#include "bubble_sort.hpp"
#include "merge_sort.hpp"
#include "bitonic_sort.hpp"
#include "quick_sort.hpp"

class TestGenerationEnvironment : public ::testing::Test {
protected:
    std::vector<int> sort_vec1;
    std::vector<long> sort_vec2;
    std::list<int> sort_list1;

    std::vector<int> vec1;
    std::vector<long> vec2;
    std::list<int> list1;

    void SetUp() override {
        vec1 = sort_vec1;
        vec2 = sort_vec2;
        list1 = sort_list1;

        std::sort(sort_vec1.begin(), sort_vec1.end());
        std::sort(sort_vec2.begin(), sort_vec2.end(), [](long a, long b) {
            return a > b;
        });
        sort_list1.sort([](int a, int b) {
            return a <= b;
        });
    }

public:
    TestGenerationEnvironment() noexcept: sort_vec1(512), sort_vec2(128), sort_list1(64) {
        for (auto &el: sort_vec1) el = static_cast<int>(random());
        for (auto &el: sort_vec2) el = random();
        for (auto &el: sort_list1) el = static_cast<int>(random());
    }
};

TEST_F(TestGenerationEnvironment, BUBBLE_SORT) {
    bubble_sort::bubble_sort(vec1.begin(), vec1.end());
    bubble_sort::bubble_sort(vec2.begin(), vec2.end(), [](long a, long b) {
        return a > b;
    });
    bubble_sort::bubble_sort(list1.begin(), list1.end(), [](int a, int b) {
        return a <= b;
    });
    EXPECT_EQ(vec1, sort_vec1);
    EXPECT_EQ(vec2, sort_vec2);
    EXPECT_EQ(list1, sort_list1);
}

TEST_F(TestGenerationEnvironment, BITONIC_SORT) {
    bitonic_sort::bitonic_sort(vec1.begin(), vec1.end());
    bitonic_sort::bitonic_sort(vec2.begin(), vec2.end(), [](long a, long b) {
        return a > b;
    });
    bitonic_sort::bitonic_sort(list1.begin(), list1.end(), [](int a, int b) {
        return a <= b;
    });
    EXPECT_EQ(vec1, sort_vec1);
    EXPECT_EQ(vec2, sort_vec2);
    EXPECT_EQ(list1, sort_list1);
}

TEST_F(TestGenerationEnvironment, MERGE_SORT) {
    merge_sort::merge_sort(vec1.begin(), vec1.end());
    merge_sort::merge_sort(vec2.begin(), vec2.end(), [](long a, long b) {
        return a > b;
    });
    merge_sort::merge_sort(list1.begin(), list1.end(), [](int a, int b) {
        return a <= b;
    });
    EXPECT_EQ(vec1, sort_vec1);
    EXPECT_EQ(vec2, sort_vec2);
    EXPECT_EQ(list1, sort_list1);
}

TEST_F(TestGenerationEnvironment, QUICK_SORT) {
    quick_sort::quick_sort(vec1.begin(), vec1.end());
    quick_sort::quick_sort(vec2.begin(), vec2.end(), [](long a, long b) {
        return a > b;
    });
    EXPECT_EQ(vec1, sort_vec1);
    EXPECT_EQ(vec2, sort_vec2);
}
