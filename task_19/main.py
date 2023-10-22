def main():
    dic = dict()
    while True:
        line = input().split()
        if len(line) == 1:
            start = line[0]
            finish = input()
            break
        x, y = line
        try:
            dic[x].append(y)
        except:
            dic[x] = [y]
        try:
            dic[y].append(x)
        except:
            dic[y] = [x]
    states_pred = set()
    states = set(dic[start])
    while True:
        if states_pred == states:
            print('YES' if finish in states else "NO")
            return
        states_pred = states
        states = list()
        for s in states_pred:
            for st in dic[s]:
                states.append(st)
        states = set(states) | states_pred


if __name__ == '__main__':
    main()
