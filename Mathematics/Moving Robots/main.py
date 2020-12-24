import numpy as np

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
n = 8
p = [(i, j) for j in range(n) for i in range(n)]
print(p)

empty_count = 0
total_count = 0
def rec(k):
    if not k:
        global empty_count
        global total_count
        empty_count += n*n - len(set(p))
        total_count += n*n

        # a = np.zeros((n, n), dtype=int)
        # for x, y in p:
        #     a[x][y] += 1
        # print(a, end='\n\n')

        return

    dir = [1 for i in range(len(p))]
    while 1:
        valid = 1
        for i in range(len(p)):
            (x, y) = p[i]
            x += dx[dir[i]]
            y += dy[dir[i]]
            p[i] = (x, y)
            if x == -1 or y == -1 or x == n or y == n:
                valid = 0

        if valid:
            rec(k - 1)

        for i in range(len(p)):
            x, y = p[i]
            x -= dx[dir[i]]
            y -= dy[dir[i]]
            p[i] = (x, y)

        end = 0
        i = 0
        while 1:
            if i == n:
                end = 1
                break

            dir[i] += 1
            if dir[i] == 4:
                dir[i] = 0
                i += 1
            else:
                break 
        if end:
            break

rec(2)
print(empty_count/total_count)