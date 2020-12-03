import random

n = 20
m = 20

fc = f'{n} {m}\n'
for i in range(n):
    a = random.randint(1, 10)
    fc += f'{a} '

na = 1
for i in range(m):
    t = random.randint(1, 3)
    k = random.randint(1, na)
    if (t == 1):
        u = random.randint(1, n)
        v = random.randint(0, 10)
        fc += f'\n{t} {k} {u} {v}'
    if (t == 2):
        v = random.randint(1, n)
        u = random.randint(1, v)
        fc += f'\n{t} {k} {u} {v}'

    if (t == 3):
        fc += f'\n{t} {k}'
        na += 1

with open('input.txt', 'w') as f:
    f.write(fc)
