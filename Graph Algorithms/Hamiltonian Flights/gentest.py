n = 20
m = 0

edge = []

for u in range(n):
    for v in range(n):
        if u != v:
            edge.append((u + 1, v + 1))

m = len(edge)
print(n, m)
for e in edge:
    print(e[0], e[1])