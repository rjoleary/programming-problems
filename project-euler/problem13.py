# Since python has built-in big integers, the solution is easy.
print(str(sum(map(int, open('problem13.txt').read().split())))[:10])
