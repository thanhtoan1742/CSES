n, a, b = [int(e) for e in input().split(' ')]
m = 6*n + 1

f0 = [0 for i in range(m)]
f1 = [0 for i in range(m)]

f0[0] = 1
for i in range(n):
    for j in range(m):
        f1[j] = 0
        for k in range(1, 7):
            if j >= k:
                f1[j] += f0[j - k]
    
    f0, f1 = f1, f0

sab = 0
s = 0
for i in range(m):
    s += f0[i]
    if a <= i and i <= b:
        sab += f0[i]


print('%.6f' % (sab/s))