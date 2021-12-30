// Copyright Davydov Nikolay 2021 <davy.nikola@gmail.com>

#ifndef SORTING_BITONIC_SORT_HPP
#define SORTING_BITONIC_SORT_HPP

#include <algorithm>
#include <functional>

namespace bitonic_sort {
    template<typename It, typename Compare = std::less<>>
    inline void comp_and_swap(It iter1, It iter2, bool direction, Compare cmp = Compare{}) {
        if (direction != cmp(*iter1, *iter2)) std::iter_swap(iter1, iter2);
    }

    template<typename It, typename Compare = std::less<>>
    void merge(It first, It last, bool direction, Compare cmp = Compare{}) {
        std::size_t distance = std::distance(first, last);

        if (distance < 2) return;

        It mid = std::next(first, distance / 2);
        It temp1 = first;
        It temp2 = mid;

        while (temp2 != last) {
            comp_and_swap(temp1, temp2, direction, cmp);
            ++temp1;
            ++temp2;
        }

        merge(first, mid, direction, cmp);
        merge(mid, last, direction, cmp);
    }

    template<typename It, typename Compare = std::less<>>
    void sort(It first, It last, bool direction, Compare cmp = Compare{}) {
        std::size_t distance = std::distance(first, last);

        if (distance < 2) return;

        It mid = std::next(first, distance / 2);
        sort(first, mid, true, cmp);
        sort(mid, last, false, cmp);
        merge(first, last, direction, cmp);
    }

    template<typename It, typename Compare = std::less<>>
    void bitonic_sort(It first, It last, Compare cmp = Compare{}) {
        sort(first, last, true, cmp);
    }
}

#endif //SORTING_BITONIC_SORT_HPP
