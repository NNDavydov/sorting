# Copyright Davydov Nikolay 2021
def quick_sort(arr, cmp=lambda a, b: a < b):
    if len(arr) < 2:
        return arr

    pivot = arr[0]
    less = [i for i in arr[1:] if cmp(i, pivot)]
    greater = [i for i in arr[1:] if not cmp(i, pivot)]
    return quick_sort(less, cmp) + [pivot] + quick_sort(greater, cmp)
