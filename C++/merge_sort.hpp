// Copyright Davydov Nikolay 2021 <davy.nikola@gmail.com>

#ifndef SORTING_MERGE_SORT_HPP
#define SORTING_MERGE_SORT_HPP

#include <algorithm>
#include <functional>

namespace merge_sort {
    template<typename It, typename Out, typename Compare=std::less<>>
    void merge(It first1, It last1, It first2, It last2, Out out, Compare cmp = Compare{}) {
        while (first1 != last1 && first2 != last2) {
            if (cmp(*first1, *first2)) {
                *out = *first1;
                ++first1;
            } else {
                *out = *first2;
                ++first2;
            }
            ++out;
        }

        std::copy(first1, last1, out);
        std::copy(first2, last2, out);
    }

    template<typename It, typename Compare=std::less<>>
    void merge_sort(It first, It last, Compare cmp = Compare{}) {
        std::size_t distance = std::distance(first, last);

        if (distance < 2) return;

        std::vector<typename It::value_type> vec(first, last);
        auto mid = std::next(vec.begin(), distance/2);
        merge_sort(vec.begin(), mid, cmp);
        merge_sort(mid, vec.end(), cmp);

        merge(vec.begin(), mid, mid, vec.end(), first, cmp);
    }
}


#endif //SORTING_MERGE_SORT_HPP
