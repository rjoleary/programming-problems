from fractions import Fraction

def isSpecial(a, b, c, d):
    f = Fraction(a * 10 + b, c * 10 + d)
    if f >= 1:
        return False
    if b == d and f == Fraction(a, c):
        return True
    if b == c and f == Fraction(a, d):
        return True
    if a == d and f == Fraction(b, c):
        return True
    if a == c and f == Fraction(b, d):
        return True
    return False

specials = [Fraction(a * 10 + b, c * 10 + d)
            for a in range(1, 10)
            for b in range(1, 10)
            for c in range(1, 10)
            for d in range(1, 10)
            if isSpecial(a, b, c, d)]

print(specials)
print(specials[0] * specials[1] * specials[2] * specials[3])
