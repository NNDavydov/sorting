// Copyright Davydov Nikolay 2021 <davy.nikola@gmail.com>

#ifndef SORTING_BUBBLE_SORT_HPP
#define SORTING_BUBBLE_SORT_HPP

#include <algorithm>
#include <functional>

namespace bubble_sort {
    template<typename It, typename Compare=std::less<>>
    void bubble_sort(It first, It last, Compare cmp = Compare{}) {
        for (auto i = first; i != std::prev(last); ++i) {
            for (auto j = std::next(i); j != last; ++j) {
                if (!cmp(*i, *j)) {
                    std::iter_swap(i, j);
                }
            }
        }
    }
}

#endif //SORTING_BUBBLE_SORT_HPP
