triangle   = {n * (n + 1) / 2     for n in range(1000000)}
pentagonal = {n * (3 * n - 1) / 2 for n in range(1000000)}
hexagonal  = {n * (2 * n - 1)     for n in range(1000000)}
print(set.intersection(triangle, pentagonal, hexagonal))
