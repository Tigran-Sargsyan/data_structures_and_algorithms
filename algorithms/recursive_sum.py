array =  [1,2,3,4,5]

def func(arr):
    if not arr:
        return 0
    else:
        popped = arr.pop()
        return popped + func(arr)    


print(func(array))
        