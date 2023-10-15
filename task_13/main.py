def main():
    string = input()
    patern = input()
    k = 0
    ans = None
    i = 0
    while i < len(string):
        if string[i] == patern[k] or patern[k] == '@':
            if ans is None:
                ans = i
            k += 1
            i += 1
        else:
            i = (ans if ans is not None else i) + 1
            k = 0
            ans = None
        if k >= len(patern):
            print(ans)
            return
    if k >= len(patern):
        print(ans)
        return
    print(-1)


if __name__ == '__main__':
    main()