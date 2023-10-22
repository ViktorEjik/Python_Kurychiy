from collections import Counter


def main():
    arr = list()
    while x := input():
        arr.append(x)
    arr = ' '.join(arr).split()
    count = Counter(arr).most_common()
    try:
        print(count[0][0] if count[0][1] != count[1][1] else '---')
    except Exception:
        print(count[0][0])


if __name__ == '__main__':
    main()
