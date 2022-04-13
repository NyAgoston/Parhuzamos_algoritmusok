#python collections modul
#python itertools combinations
#strings modul alphabet variable
from timeit import default_timer as timer

def check(guess):
    password = ['q','u','k','o']
    if guess == password:
        return True
    else:
        return False
    
def bruteforce():
    characters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    
    guess = ['a','a','a','a']

    N = len(characters)
    for i in range(N):
        guess[0] = characters[i]
        for j in range(N):
            guess[1] = characters[j]
            for k in range(N):
                guess[2] = characters[k]
                for l in range(N):
                    guess[3] = characters[l]
                    if check(guess):
                        return print("kesz!, Megoldas: ",guess)
                    

start = timer()


bruteforce()

end = timer()
print("Eltelt ido:",end - start)

        
        
    





