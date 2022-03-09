import csv
from operator import delitem
from matplotlib import pyplot as plt


with open("ketto_sima.csv","r") as csv_file:
    
    reader = csv.reader(csv_file,delimiter = " ")
    ns1 = []
    ts1 = []
    for line in reader:
        print(line)
        n1 = int(line[0])
        t1 = float(line[1])
        ns1.append(n1)
        ts1.append(t1)
with open("ketto_pthread.csv","r") as csv_file:
    
    reader = csv.reader(csv_file,delimiter = " ")
    ns2 = []
    ts2 = []
    for line in reader:
        print(line)
        n2 = int(line[0])
        t2 = float(line[1])
        ns2.append(n2)
        ts2.append(t2)
    
    

plt.figure()
plt.plot(ns1,ts1)
plt.plot(ns2,ts2)
plt.show()
