# -* encoding: utf-8
import json

def replace_keys(html, dictionary, key):
    print("replace now")

    for i in range(len(dictionary[key])):
        placeholder = "__{0}__".format(i)
        html = html.replace(placeholder, dictionary[key][i])

    return html


def tmp():
    for i in range(38):
        s = "__"+str(i)
        print("<td>{0}<td>".format(s))


def main():
    """
    main
    :return:
    """
    html = ""
    with open('template.html') as htmlf:
        for s in htmlf:
            html += s

    d = {}
    with open('keymaps.json') as jsonf:
        d = json.load(jsonf)

    html = replace_keys(html, d, "BASE")

    with open("keymap_generated.html", "w") as html_out:
        html_out.write(html)

if __name__ == '__main__':
    main()