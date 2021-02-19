from random import randint

n = 1000000
s = 'a'*n

content = s + '\n' + s

with open('input.txt', 'w+') as f:
    f.write(content);
