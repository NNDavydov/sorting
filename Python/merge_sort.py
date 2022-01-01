# Copyright Davydov Nikolay 2021
def merge(arr1, arr2, res, cmp=lambda a, b: a < b):
    i = j = 0
    while i != len(arr1) and j != len(arr2):
        if cmp(arr1[i], arr2[j]):
            res.append(arr1[i])
            i += 1
        else:
            res.append(arr2[j])
            j += 1
    res += arr1[i:] + arr2[j:]


def merge_sort(arr, cmp=lambda a, b: a < b):
    if len(arr) < 2:
        return

    middle = len(arr) // 2
    left_array = arr[:middle]
    right_array = arr[middle:]
    arr.clear()

    merge_sort(left_array, cmp)
    merge_sort(right_array, cmp)
    merge(left_array, right_array, arr, cmp)
