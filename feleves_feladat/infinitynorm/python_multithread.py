import threading
from random import *
import time

def infnorm(matrix,x):
    endpart = x * (N / num_of_threads)
    startpart = endpart - (N / num_of_threads)
    x = startpart;
    while x < endpart:
        sum = 0
        for j in range(N):
            sum += abs(matrix[i][j])
        solutions.append(sum);
        x+=1
   
if __name__ == "__main__":
    global solutions
   
    solutions = []
       
    N = 10000
    matrix = [[randint(1,100) for i in range(N)] for j in range(N)]
    num_of_threads = 5
    threads = []
    start = time.time()

    t1 = threading.Thread(target=infnorm, args=(matrix,1))
    t2 = threading.Thread(target=infnorm, args=(matrix,2))
    t3 = threading.Thread(target=infnorm, args=(matrix,3))
    t4 = threading.Thread(target=infnorm, args=(matrix,4))
    t5 = threading.Thread(target=infnorm, args=(matrix,5))
    threads.append(t1)
    threads.append(t2)
    threads.append(t3)
    threads.append(t4)
    threads.append(t5)

    for i in range(num_of_threads):
        threads[i].start()
    
    for i in range(num_of_threads):
        threads[i].join()

    solution = max(solutions)
    end = time.time()

    print("The matrixes infinit norm is: ",solution) 
    print("Elapsed time:",end - start)

    print("Done!")