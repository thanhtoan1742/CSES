from genericpath import isdir
import os
from os import path as P, walk


GITHUB = "https://github.com/thanhtoan1742/CSES/tree/master"

def wrap_html(text, tag, attributes = ""):
    return "<{0} {2}>{1}</{0}>".format(tag, text, attributes)

def extract_category_task(dir):
    dir = dir[dir.find("CSES") + len("CSES/"):]
    if "/" in dir:
        return dir.split("/")
    else:
        return dir, None


ignored_list = ["docs", ".git"]
def generate_task_list_html(dir):
    if not P.isdir(dir):
        return ""

    child_dirs = os.listdir(dir)
    child_dirs.sort()

    category, task = extract_category_task(dir)
    if category == "":
        html = ""
    else:
        if task == None:
            html = wrap_html(category, "h2")
            html += "<ul>"
        else:
            html = wrap_html(task, "a", f"href='{GITHUB + '/' + category + '/' + task}' target=_blank")
            html = wrap_html(html, "li", "class=task")

    for child_dir in child_dirs:
        if child_dir in ignored_list:
            continue

        html += generate_task_list_html(P.join(dir, child_dir))

        
    if category != "" and task == None:
        html += "</ul>"
        html = wrap_html(html, "div", "class=task-list")
    if category == "":
        html = wrap_html(html, "div", "class=task-list-grid")
    return html




task_dir = P.abspath(P.join(P.dirname(__file__), '..'))

html = """\
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CSES Solutions Set</title>
    <link rel="stylesheet" href="style.css">
    <script src="script.js"></script>
</head>
<body>

<h1>CSES Solutions Set</h1>
<p>This is a list of solved problems.</p>
<h2><a href="https://github.com/thanhtoan1742/CSES">Github page for codes.</a></h2>

"""
html += generate_task_list_html(task_dir)
html += """

</body>
</html>
"""
open("index.html", "w+").write(html)
