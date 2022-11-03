a =  [1,4,9,3,6,2,8]

def merge(left,right,arr):
    len_l = len(left)
    len_r = len(right)
    i,j,k = 0,0,0   # i for left subarray, j for right subarray
    
    while i < len_l and j < len_r:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i+=1
        else:
            arr[k] = right[j]
            j+=1
        k+=1

    while i < len_l:
        arr[k] = left[i]
        i+=1
        k+=1
    
    while j < len_r:
        arr[k] = right[j]
        j+=1
        k+=1

    return arr    

def mergesort(array):
    length = len(array)

    if length < 2:
        return array 

    else:
        left1 = []
        right1 = []
        mid = length // 2

        for i in range(mid):
            left1.append(array[i])
        
        for i in range(mid,length):
            right1.append(array[i])

        mergesort(left1)
        mergesort(right1)
        merge(left1,right1,array)

    return array

print(a," Random list")
mergesort(a)
print(a," Sorted list")

k  = [91, 61, 94, 31, 80, 54, 81, 95, 67, 21, 57, 44, 85, 47, 46, 80, 36, 81, 94, 1]
print(k)
print(mergesort(k))
