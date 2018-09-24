# -* encoding: utf-8 *-

PATH = 'default/keymap.c'
import re
import enum

class State(enum.Enum):
    COMMENT_1LINE = 0
    COMMENT_MULTI = 1
    NORMAL = 2

# コメントの除去
def remove_comments(src):
    result = ""
    state = State.NORMAL
    pass_flag = False
    l = len(src)
    for i in range(l-1):
        if pass_flag:
            pass_flag = False
            continue
        c, c_next = src[i], src[i+1]
        if state==State.NORMAL:
            if c =='/' and c_next =='/':
                state = State.COMMENT_1LINE
            elif c == '/' and c_next =='*':
                state = State.COMMENT_MULTI
                pass_flag = True
            else:
                result += c
        elif state==State.COMMENT_1LINE:
            if c != '\\' and c_next == '\n':
                state = State.NORMAL
        elif state==State.COMMENT_MULTI:
            if c == '*' and c_next == '/':
                state = State.NORMAL
                pass_flag = True
    return result

def process_brc(s, stack):
    for i in range(s.count('(')):
        stack.append('(')
    for i in range(s.count(')')):
        stack.pop()


# keymapsの抽出
def exploit_keymaps(src):
    src = src.split('\n')

    results = []
    r = []
    stack = []
    start = False
    for s in src:
        if "KEYMAP(" in s:
            start = True

        if start is True:
            r.append(s)

        process_brc(s, stack)

        if len(stack) == 0 and start is True:
            tmp = ''.join(r).replace(' ', '')
            tmp = tmp[0:-2] if tmp[-2:] == '),' else tmp
            results.append(tmp)
            r = []
            start = False

    return results

def main():
    print("convert keymap to json...")

    src = ""

    with open(PATH, encoding="utf-8") as f:
        for s in f:
            src += s

    # parse開始
    src = remove_comments(src)

    r = exploit_keymaps(src)

    for i in r:
        print(i.split(','))

if __name__ == '__main__':
    main()
