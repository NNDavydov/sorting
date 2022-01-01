# Copyright Davydov Nikolay 2021
import unittest
import random

from bubble_sort import bubble_sort
from merge_sort import merge_sort
from quick_sort import quick_sort


class TestSort(unittest.TestCase):
    def setUp(self):
        self.arr1 = [random.randint(0, 1000) for i in range(100)]
        self.arr2 = [random.randint(0, 1000) for j in range(256)]

        self.sort_arr1 = self.arr1.copy()
        self.sort_arr1.sort()
        self.sort_arr2 = self.arr2.copy()
        self.sort_arr2.sort(reverse=True)

    def test_bubble_sort(self):
        bubble_sort(self.arr1)
        bubble_sort(self.arr2, lambda x,y: x>y)
        self.assertEqual(self.arr1, self.sort_arr1)
        self.assertEqual(self.arr2, self.sort_arr2)

    def test_merge_sort(self):
        merge_sort(self.arr1)
        merge_sort(self.arr2, lambda x, y: x > y)
        self.assertEqual(self.arr1, self.sort_arr1)
        self.assertEqual(self.arr2, self.sort_arr2)

    def test_quick_sort(self):
        self.arr1 = quick_sort(self.arr1)
        self.arr2 = quick_sort(self.arr2, lambda x, y: x > y)
        self.assertEqual(self.arr1, self.sort_arr1)
        self.assertEqual(self.arr2, self.sort_arr2)
