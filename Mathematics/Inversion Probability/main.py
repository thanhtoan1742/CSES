a = [3, 2]
n = len(a)
b = [1 for i in range(n)]

cs = 0
ci = 0

while 1:
    print(b)
    cs += 1

    for i in range(n):
        for j in range(i):
            if b[j] > b[i]:
                ci += 1

    i = n - 1
    end = 0
    while 1:
        if i < 0: 
            end = 1
            break

        b[i] += 1
        if b[i] > a[i]:
            b[i] = 1
            i -= 1
        else:
            break

    if end:
        break

print(ci, cs)
print(ci/cs)