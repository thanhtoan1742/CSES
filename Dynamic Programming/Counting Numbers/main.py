def cal(h, l):
    return 9**l

# 155729 -> 154989
# 100729 -> 98989
def LVN(a):
    di = -1
    s = str(a)
    n = len(s)
    for i in range(1, n):
        if s[i] == s[i - 1]:
            di = i
            break

    if di < 0:
        return a

    en = ''.join([str(9 - i%2) for i in range(n)])
    if s[di] == '0':
        while s[di] == '0':
            di -= 1
        if di == 0 and s[di] == '1':
            return int(en[0:n - 1])

    return s[0:di] + chr(ord(s[di]) - 1) + en[0:n - 1 - di]



def cn(a):
    if a < 10:
        return a

    s = str(LVN(a))

    res = (9**len(s) - 9)//8
    for i in range(len(s)):
        start = (i == 0)
        end = int(s[i]) + (i == len(s) - 1)
        for c in range(start, end):
            if i > 0 and c == int(s[i - 1]):
                continue
            res += cal(c, len(s) - i - 1);

    return res


def bf(a):
    res = 0
    for i in range(1, a + 1):
        s = str(i)
        u = 1
        for j in range(1, len(s)):
            if s[j] == s[j - 1]:
                u = 0
        res += u

    return res


a, b = map(int, input().split())
print(cn(b) - cn(a - 1))
