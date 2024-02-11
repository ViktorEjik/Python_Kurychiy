import re


reg = r'{}'.format(input())
while s := input():
    f = re.search(reg, s)
    if f is None:
        print('<NONE>')
        continue
    print(f'{f.start()}: {f.group()}')
    i = 1
    for g in f.groups():
        if g:
            print(f'{i}/{f.start(i)}: {g}')
        i += 1
    for name, str in f.groupdict().items():
        if str:
            print(f'{name}/{f.start(name)}: {str}')
