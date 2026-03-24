"""
program for finding the squre root of number using itraive algorithm.
- 
  geting the number num by command line . note : you should only inter number on command line.
-
 the program print to you on the terminal the squre root of the number you enter. 
example:
 $ python squreRoot.py 25

output : 5.0

"""
import sys
import random


def main():
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("please enter valid number")
        exit()

    if n == 0:
        sr = 0
    else:
        sr =  squreRootof(n)
    print(sr)


def squreRootof(n):
    x = random.randint(1, 9)
    while True:
        a = n/x
        y = (x + a)*0.5;

        if (y - x) < 0.001 and (y - x) >= 0:
            return y
        x = y
        

if __name__ == "__main__":

    main()


