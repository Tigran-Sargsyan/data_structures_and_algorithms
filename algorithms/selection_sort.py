def find_smallest(arr):
    smallest = arr[0]
    smallest_index = 0
    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index

def selection_sort(arr):
    newArr = []
    for i in range(len(arr)):
        smallest_index = find_smallest(arr)
        newArr.append(arr.pop(smallest_index))
        print(newArr)
    return newArr

print(selection_sort([2,5,3,9,4]))