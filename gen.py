from random import *
import os

while 1:
    with open("input.txt", "w") as data:
        for i in range(10):
            data.write(f"{randint(-10 , 10)} ")
        os.system("./test.exe < input.txt")
        a = int(input())
        if (a==0):
            break
        else:
            continue
    # os.system("my.exe < input.txt > my.dat")
    # with open("ac.dat", "r") as data:
    #     ac = data.read()
    # with open("my.dat", "r") as data:
    #     my = data.read()

    #     if(ac != my):
    #         break