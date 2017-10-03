'''
This module contains exercises for Recursion and Divide and Conquer
chapters in Grokking's Algorithm.
'''

import sys

# Returns the sum of the list. (Ex. 4.1)
def sumIt(lst):
    if not lst:
        return 0
    else:
        return lst.pop(0) + sumIt(lst)


# Returns the number of elements in the list. (Ex. 4.2)
def countIt(lst):
    if not lst:
        return 0
    lst.pop(0)
    return 1 + countIt(lst)
    

# Finds maximum number in the list. (Ex. 4.3)
max_num = 0
def findMax(lst):
    global max_num
    if not lst:
        return max_num
    lst_item = lst.pop(0)
    if  max_num < lst_item:    
        max_num = lst_item
    return findMax(lst)
   
                
g = [int(i) for i in sys.argv[1].split(',')]
h = g[:]
i = g[:]
length = countIt(g)
summation = sumIt(h)
print("The Sum is {0}, Max is {2} and the length of the list {1}".format(summation, length, findMax(i)))
