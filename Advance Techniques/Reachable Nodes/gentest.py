n = 50000
m = n - 1
content = f'{n} {m}\n'
for i in range(n - 1):
	content += f'{i + 1} {i + 2}\n'

with open('input.txt', 'w') as fo:
	fo.write(content)