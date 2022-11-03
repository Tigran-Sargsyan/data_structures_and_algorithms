import random

def bin_search(arr,item):
    low = 0
    high = len(arr) - 1
    count = 0
    while low<=high:
        count += 1
        mid = (low + high) // 2
        guess = arr[mid]
        
        if guess == item:
            print("Found ",item," in ", count, " moves.")
            return item

        if guess > item:
            high = mid - 1

        else:
            low = mid + 1    

    return None    
num = random.randint(1,101)
bin_search(range(1,101),num)
