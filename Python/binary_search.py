import sys
#                             lst        search
# python binary_search.py  2,4,6,8,10      10

def binary_search(lst, search):
    low = 0
    high = len(lst) - 1

    for iteration, i in enumerate(lst, 1):   
        mid = int((high + low) // 2)
        
        if lst[mid] == search:
            return iteration, lst[mid]

        elif lst[mid] > search:
            high = mid - 1

        elif lst[mid] < search:
            low = mid + 1



num, s = binary_search([int(i) for i in sys.argv[1].split(',')], int(sys.argv[2]))

print("Iteration Count: {}, Search_Item: {}".format(num, s))

