array =  [1,2,3,4,5]

def func(arr):
    if not arr:
        return 0
    else:
        popped = arr.pop()
        return func(arr) + 1    

print(func(array))        