import os
from itertools import permutations 
import random
word = "abcdefghijklmnopqrstuvwxyz"
word = list(word) 
with open('input' , 'w') as f:
    dic = dict()
    for i in range(100):
        random.shuffle(word)
        string = word[:random.randint(15, 15)]
        f.write("".join(string) + '\n')
        dic["".join(string)] = 1
    f.write('\n')
    for i in range(100):
        a = random.choice(list(dic.keys()))
        b = random.choice(list(dic.keys()))
        f.write(a + ' ' + b + '\n')
    f.close()