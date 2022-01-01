# Copyright Davydov Nikolay 2021
def bubble_sort(arr, cmp=lambda a, b: a < b):
    for i in range(0, len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if not cmp(arr[i], arr[j]):
                arr[i], arr[j] = arr[j], arr[i]
