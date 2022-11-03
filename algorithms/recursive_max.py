array =  [1,2,3,4,5,44]

def func(arr):
    if len(arr) == 1:
        return arr[0]
    else:
        popped = arr.pop()
        if func(arr) > popped:
            return func(arr)
        else:
            return popped         

print(func(array))        