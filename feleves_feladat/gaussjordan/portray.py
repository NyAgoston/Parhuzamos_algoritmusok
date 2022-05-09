import csv
from operator import delitem
from matplotlib import pyplot as plt
ns1 = []
ts1 = []
ns2 = []
ts2 = []

with open("data.csv","r") as csv_file:
    
    reader = csv.reader(csv_file,delimiter = " ")
    
    
    for line in reader:
        print(line)
        if int(line[0]) == 1:
            n1 = int(line[1])
            t1 = float(line[2])
            ns1.append(n1)
            ts1.append(t1)
        else:
            n2 = int(line[1])
            t2 = float(line[2])
            ns2.append(n2)
            ts2.append(t2)
            
plt.figure()
plt.plot(ns1,ts1,label = "szekv")

plt.plot(ns2,ts2,label = "omp")
plt.legend()
plt.show()
