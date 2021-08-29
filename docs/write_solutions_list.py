import os
from os import walk
from os import path as P

sol_path = P.abspath(P.join(P.dirname(__file__), '..'))
remove_list = ["docs", ".git"]
html = """\
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>CSES Solutions Set</title>
	<link rel="stylesheet" href="style.css">
</head>
<body>

<h1>CSES Solutions Set</h1>
<p>This is a list of solved problems.</p>
<h2><a href="https://github.com/thanhtoan1742/CSES">Github page for codes.</a></h2>

"""

def wrap_html(text, wrapper):
	return "<{0}>{1}</{0}>".format(wrapper, text)

def problem_to_html(prob):
	return f"    <li class=\"task\">{prob}</li>\n"

first = True
def category_to_html(cat):
	global first
	html = f"<h2>{cat}<h2>\n<ul class=\"task-list\">\n"
	if not first:
		html = "</ul>\n\n" + html
	first = False
	return html


for root, dirs, files in walk(sol_path):
	r = root[root.find("CSES"):]
	if r == "CSES":
		for rem in remove_list:
			if rem in dirs:
				dirs.remove(rem)

		continue

	r = r[5:]
	if "/" in r:
		prob = r[r.find("/") + 1:]
		html_elem = problem_to_html(prob)
	else:
		cat = r
		html_elem = category_to_html(cat)

	html += html_elem

html += "</ul>\n\n</body>\n</html>"
print(html)

	# print(dirs)
	# print(files)

