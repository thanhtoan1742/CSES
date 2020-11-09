n = 4

def to_bin(x, n = 0):
    x = bin(x)[2:]
    while len(x) < n:
        x = '0' + x
    return x

for i in range(1 << n):
    print(to_bin(i, n))