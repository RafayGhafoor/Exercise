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
        return lst[0] + sumIt(lst[1:])


# Returns the number of elements in the list. (Ex. 4.2)
def countIt(lst):
    if not lst:
        return 0
    return 1 + countIt(lst[1:])
    

# Finds maximum number in the list. (Ex. 4.3)
def findMax(lst):
    if len(lst) == 2:
        return lst[1] if lst[0] < lst[1]  else lst[0]

    max_num = findMax(lst[1:])

    if lst[0] < max_num:
        return max_num

    else:
        return lst[0]


# Find least number in the list. (Supplementary)
def findLeast(lst):
    if len(lst) == 2:
        return lst[0] if lst[0] < lst[1] else lst[1]
    z = findLeast(lst[1:])
    if lst[0] > z:
        return z
    else:
        return lst[0]

   
                
g = [int(i) for i in sys.argv[1].split(',')]
print("The Sum is {0}, Max is {2}, length of the list {1} and Least value is {3}".format(sumIt(g[:]), countIt(g[:]), findMax(g[:]), findLeast(g[:])))
