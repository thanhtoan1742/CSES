d = ['D', 'R', 'U', 'L']
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

p = input()
res = 0
visiting = [[False for y in range(7)] for x in range(7)]

def dfs(x, y, i):
    global res
    if i == len(p):
        if x == 6 and y == 0:
            res += 1
        return

    visiting[x][y] = True

    for j in range(4):
        if p[i] == '?' or p[i] == d[j]:
            u = x + dx[j]
            v = y + dy[j]
            if u < 0 or v < 0 or u > 6 or v > 6:
                continue
            if visiting[u][v]:
                continue

            dfs(u, v, i + 1)

    #visiting[x][y] = False


dfs(0, 0, 0)
print(res)