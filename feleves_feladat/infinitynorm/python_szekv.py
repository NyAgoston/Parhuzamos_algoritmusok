from random import *
import time
#numpy
#pypy

solutions = []
       
N = 10000
matrix = [[randint(1,100) for i in range(N)] for j in range(N)]
start = time.time()
for i in range(N):
    for k in range(N):
        sum += abs(matrix[i][k])
        solutions.append(sum);
        
solution = max(solutions)


end = time.time()

print("The matrixes infinit norm is: ",solution) 
print("Elapsed time:",end - start)