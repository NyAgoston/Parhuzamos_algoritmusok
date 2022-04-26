import threading

def worker(array):
    for i in range (len(array)):
        print(array[i])
	

if __name__ == "__main__":
    
    array = [1,3,2,5,4,9,6,7,8]
    
    threads = []
	# creating threads
    
    for i in range(4):
        threads[i] = threading.Thread(target=worker, args=(array,))
    
	# starting threads
    for i in range(4):
        threads[i].start()
    
    # joining threads
    for i in range(4):
        threads[i].join()

	# threads completly executed
    print("Done!")
