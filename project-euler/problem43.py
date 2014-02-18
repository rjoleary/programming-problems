from itertools import permutations
s = 0
for p in permutations('0123456789'):
    p = ''.join(p)
    if int(p[1:4]) % 2 == 0:
        if int(p[2:5]) % 3 == 0:
            if int(p[3:6]) % 5 == 0:
                if int(p[4:7]) % 7 == 0:
                    if int(p[5:8]) % 11 == 0:
                        if int(p[6:9]) % 13 == 0:
                            if int(p[7:10]) % 17 == 0:
                                print(p)
                                s += int(p)
print(s)
