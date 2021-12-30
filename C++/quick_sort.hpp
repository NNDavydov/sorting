// Copyright Davydov Nikolay 2021 <davy.nikola@gmail.com>

#ifndef SORTING_QUICK_SORT_HPP
#define SORTING_QUICK_SORT_HPP

#include <algorithm>
#include <functional>

namespace quick_sort {
    template<typename It, typename Compare = std::less<>>
    void quick_sort(It first, It last, Compare cmp = Compare{}) {
        const std::size_t distance = std::distance(first, last);
        if (distance < 2) return;

        const auto pivot = *first;
        auto pivot_pos = std::partition(first, last, [&pivot, &cmp](auto &item) {
            return cmp(item, pivot);
        });

        auto iter = std::find(first, last, pivot);
        if (pivot_pos > iter) {
            std::iter_swap(iter, std::prev(pivot_pos));
            pivot_pos = std::prev(pivot_pos);
        } else { std::iter_swap(iter, pivot_pos); }

        quick_sort(first, pivot_pos, cmp);
        quick_sort(std::next(pivot_pos), last, cmp);
    }
}

#endif //SORTING_QUICK_SORT_HPP
