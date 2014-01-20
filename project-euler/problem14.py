def seqlength(n):
    if n == 1:
        return 0
    elif n % 2 == 0:
        return seqlength(n // 2) + 1
    else:
        return seqlength(n * 3 + 1) + 1

# Note that this brute-force and very slow.
print(max(((seqlength(n), n) for n in range(1, 1000000))))
