from random import *
# import os

# while 1:
with open("input.out", "w") as data:
    n = randint(3 , 10)
    m = randint(3 , 10)
    data.write(f"{n}\n")
    data.write(f"{m}\n")
    ar=[]
    for i in range(n):
        ar.append(randint(0 , 100))
    ar.sort()
    arr = []
    for i in range(m):
        arr.append(randint(0 , 100))
    arr.sort()
    for i in range(0,n):
        data.write(f"{ar[i]} ")
    data.write('\n')
    for i in range(0,m):
        data.write(f"{arr[i]} ")
    data.write('\n')
            # data.write(f"{randint(-10 , 10)} ")
        # os.system("./test.exe < input.txt")
        # a = int(input())
        # if (a==0):
            # break
        # else:
            # continue
    # os.system("my.exe < input.txt > my.dat")
    # with open("ac.dat", "r") as data:
    #     ac = data.read()
    # with open("my.dat", "r") as data:
    #     my = data.read()

    #     if(ac != my):
    #         break