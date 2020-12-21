from math import sqrt

MOD = 1000000000 + 7
n = int(input())

i = 2
sn = sqrt(n)
res = 1
while i <= sn:
    p = 1
    s = 1
    while n % i == 0:
        p *= i
        s += p  
        n //= i

    res *= s
    i += 1

if n > 1:
    res *= n + 1

print(res)
