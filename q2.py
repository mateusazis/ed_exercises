import sys

def perfect_square(n):
    s = 0
    i = 1
    while i <= n and s < n:
        s += i
        i += 2
    return s == n


if __name__ == '__main__':
    n = int(sys.argv[1])

    print("yes" if perfect_square(n) else "no")