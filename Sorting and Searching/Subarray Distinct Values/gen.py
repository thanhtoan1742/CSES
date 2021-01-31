from random import randint
content = ''

n = 200000
k = 200000
content += str(n) + ' ' + str(k) + '\n'

for i in range(n):
    v = randint(1, 100000)
    content += str(v) + ' '


with open('input.txt', 'w+') as f:
    f.write(content)