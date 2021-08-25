import random

con = ''

n = 15
k = 4
con += f'{n} {k}\n'
for u in range(1, n):
    v = random.randint(0, u - 1);
    con += f'{u + 1} {v + 1}\n'

open('input.txt', 'w+').write(con)
