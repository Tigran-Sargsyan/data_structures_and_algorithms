def quicksort(arr):

    if len(arr) < 2:
        return arr

    if len(arr) == 2:
        if arr[0] < arr[1]:
            return arr
        else:
            arr[0],arr[1]=arr[1],arr[0]
            return arr

    else:
        pivot_index = len(arr) // 2
        pivot = arr[pivot_index]
        less = [arr[i] for i in range(len(arr)) if arr[i] <= pivot and i != pivot_index]
        greater = [i for i in arr if i > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

k  = [91, 61, 94, 31, 80, 54, 81, 95, 67, 21, 57, 44, 85, 47, 46, 80, 36, 81, 94, 1]
print(k)
print(quicksort(k))
