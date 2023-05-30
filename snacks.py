#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
with open('input1.txt') as f:
    line = f.readline()
    N, X = map(int, line.split())
    line = f.readline()
    L = list(map(int, line.strip().split()))


# insert your code here
minutes = 0
L.sort()

item = L.pop()
while item != None:
    if item + L.

while len(L) > 0:
    eat = min(L)
    L.remove(eat)

    if len(L) > 0:
        eat_possible = min(L)
        #print(eat, eat_possible)

        if eat + eat_possible <= X:
            L.remove(eat_possible)
    
    minutes = minutes + 1

    #print(L)

print(minutes)  # print the result
