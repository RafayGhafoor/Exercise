def quicksort(array):

    if len(array) < 2: # If array consists of only one item or is empty, return the lst
        return array
    
    pivot = array[0]
#    if array[0] > array[(len(array)-1) // 2]:
    less_arr = [i for i in array[1:] if i <= pivot]
    greater_arr = [i for i in array[1:] if i >= pivot]
  
    sorted_array = quicksort(less_arr) + [pivot] + quicksort(greater_arr)
    return sorted_array

    
    
    
x = quicksort([5,2,6])
print(x)
