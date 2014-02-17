perfectSquares = {x*x: x for x in range(1, 1000)}

count = [0] * 1001
for a in range(1, 1001):
    for b in range(a + 1, 1001):
        c = perfectSquares.get(a**2 + b**2)
        if c and c != a and c != b:
            p = a + b + c
            if p <= 1000:
                count[p] += 1
            if p == 120:
                print(a, b, c)

print(count[120])
print(count.index(max(count)))
