def selection_sort(lst):

    def findSmallest():
        smallest = lst[0]
        for i in lst:
            if i < smallest:
                smallest = i
        return smallest
    
    sorted_arr = []    
    
    for i in range(len(lst) - 1):
        x = findSmallest()
        lst.remove(x)
        sorted_arr.append(x)
        
    return sorted_arr

    
sorted_arr = selection_sort([97,99,12,15,18,23,100,101,45,21,63])
print(sorted_arr)
