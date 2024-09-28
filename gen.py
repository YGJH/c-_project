import os
from itertools import permutations 
import random
print(2)

def generate_permutation(n):
    numbers = list(range(1, n + 1))
    random.shuffle(numbers)
    return numbers


for i in range(2):
    n , m = random.randint(1 , 7) , random.randint(1 , 7)
    print(f"{n} {m}")
    per = generate_permutation(n)
    for j in range(m):
        for k in per:
            print(f"{k} " , end='')
        print()
        per = generate_permutation(n)

