import threading
import random
import time
import numpy as np

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

    measures = {100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000,10500,11000,11500,12000,12500,13000,13500,14000,14500,15000,15500}
    num_of_threads = 4
    

    for measure in measures:
        solutions = []
        
        N = measure
        #matrix = [[random.random() for i in range(N)] for j in range(N)]
        matrix = np.random.rand(N,N)
        
        threads = []
        start = time.time()

        for i in range(num_of_threads):
            threads.append(threading.Thread(target=infnorm, args=(matrix,i + 1)))
            threads[i].start()    
        
        for i in range(num_of_threads):
            threads[i].join()

        solution = max(solutions)
        end = time.time()

        #print("The matrixes infinit norm is: ",solution) 
        print("Matrix size:",measure,"Elapsed time:",end - start)

        fo = open("python.csv","a")

        fo.write("1 "+str(measure)+" "+str(end - start)+"\n")


        fo.close()

        del solution