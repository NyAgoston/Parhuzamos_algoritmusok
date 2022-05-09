import csv
from operator import delitem
from matplotlib import pyplot as plt
ns0 = []
ts0 = []
ns2 = []
ts2 = []
ns3 = []
ts3 = []
ns4 = []
ts4 = []
ns5 = []
ts5 = []
ns6 = []
ts6 = []
ns7 = []
ts7 = []
ns8 = []
ts8 = []
ns10 = []
ts10 = []

with open("data.csv","r") as csv_file:
    
    reader = csv.reader(csv_file,delimiter = " ")
    
    
    for line in reader:
        print(line)
        if int(line[0]) == 0:
            n1 = int(line[1])
            t1 = float(line[2])
            ns0.append(n1)
            ts0.append(t1)
        elif int(line[0]) == 2:
            n2 = int(line[1])
            t2 = float(line[2])
            ns2.append(n2)
            ts2.append(t2)
        elif int(line[0]) == 3:
            n2 = int(line[1])
            t2 = float(line[2])
            ns3.append(n2)
            ts3.append(t2)
        elif int(line[0]) == 4:
            n2 = int(line[1])
            t2 = float(line[2])
            ns4.append(n2)
            ts4.append(t2)
        elif int(line[0]) == 5:
            n2 = int(line[1])
            t2 = float(line[2])
            ns5.append(n2)
            ts5.append(t2)
        elif int(line[0]) == 6:
            n2 = int(line[1])
            t2 = float(line[2])
            ns6.append(n2)
            ts6.append(t2)
        elif int(line[0]) == 7:
            n2 = int(line[1])
            t2 = float(line[2])
            ns7.append(n2)
            ts7.append(t2)
        elif int(line[0]) == 8:
            n2 = int(line[1])
            t2 = float(line[2])
            ns8.append(n2)
            ts8.append(t2)
        elif int(line[0]) == 10:
            n2 = int(line[1])
            t2 = float(line[2])
            ns10.append(n2)
            ts10.append(t2)
            
plt.figure()
plt.plot(ns0,ts0,label = "szekv")
plt.plot(ns2,ts2,label = "2-thread")
plt.plot(ns3,ts3,label = "3-thread")
plt.plot(ns4,ts4,label = "4-thread")
plt.plot(ns5,ts5,label = "5-thread")
plt.plot(ns6,ts6,label = "6-thread")
plt.plot(ns7,ts7,label = "7-thread")
plt.plot(ns8,ts8,label = "8-thread")
plt.plot(ns10,ts10,label = "10-thread")


plt.legend()
plt.show()
