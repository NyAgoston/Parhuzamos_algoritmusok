import csv
from operator import delitem
from matplotlib import pyplot as plt

with open("adatok.csv","r") as csv_file:
    
    reader = csv.reader(csv_file,delimiter = " ")
    ns = []
    ts = []
    for line in reader:
        print(line)
        n = int(line[0])
        t = float(line[1])
        ns.append(n)
        ts.append(t)
    

plt.figure()
plt.plot(ns,ts)
plt.show()
