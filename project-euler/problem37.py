from math import sqrt

def isPrime(n):
    if n == 1:
        return False
    for m in range(2, int(sqrt(n) + 1)):
        if n % m == 0:
            return False
    return True

def isTruncPrime(n):
    s = str(n)
    if not isPrime(n):
        return False
    for m in range(1, len(s)):
        if not isPrime(int(s[:m])):
            return False
        if not isPrime(int(s[m:])):
            return False
    return True

n = 10
l = []
while len(l) < 11:
    if isTruncPrime(n):
        l.append(n)
    n += 1

print(l)
print(sum(l))
