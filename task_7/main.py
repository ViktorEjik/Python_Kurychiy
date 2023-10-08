def main():
    arr = []
    count = 0
    while elem := input():
        arr.append(elem)

    m, n = len(arr), len(arr[0])

    for i in range(m - 1):
        for j in range(n - 1):
            if arr[i][j] == '#' and arr[i][j+1] == '.' and arr[i+1][j] == '.':
                count += 1

    for i in range(m - 1):
        if arr[i][n-1] == '#' and arr[i + 1][n-1] == '.':
            count += 1

    for i in range(n - 1):
        if arr[m - 1][i] == '#' and arr[m - 1][i+1] == '.':
            count += 1
    if arr[m-1][n-1] == '#':
        count += 1

    print(count)


if __name__ == '__main__':
    main()
