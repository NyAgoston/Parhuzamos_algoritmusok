from random import *
import time
import numpy as np
#numpy
#pypy

solutions = []
sum = 0;
N = 100
matrix = np.random.rand(N,N)
start = time.time()
for i in matrix:
    for k in matrix:
        sum = sum + abs(k)

    solutions.append(sum);
        
solution = max(solutions)


end = time.time()

print("The matrixes infinit norm is: ",solution) 
print("Elapsed time:",end - start)