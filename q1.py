import sys
import math

def isPrime(n):
    if n % 2 == 0:
        return n == 2

    for i in range(3, int(math.ceil(math.sqrt(n))), 2):
        if n % i == 0:
            return False
    return True

n = int(sys.argv[1])
i = 2

while n:
    if isPrime(i):
        print(i)
        n -= 1
    i += 1 if i == 2 else 2