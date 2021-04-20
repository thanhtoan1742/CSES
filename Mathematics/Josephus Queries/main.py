def sign(a):
    if a > 0:
        return 1
    if a < 0:
        return -1
    return 0

def Josephus(n, k):
    res = 2*n + 1
    res -= (2*n - 2*k + 1)*(2**t  - sign(((n + 1)//2)/k))
    return res


ntest = int(input())
while ntest:
    ntest -= 1

    n, k = map(int, input().split())
    print(Josephus(n, k))