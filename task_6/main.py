def down_diag(arr, i, j, seq):
    while j > -1 and i < len(arr):
        arr[i][j] = seq
        seq = seq + 1 if seq < 9 else 0
        i += 1
        j -= 1
    return i-1, j+1, seq


def top_diag(arr, i, j, seq):
    while j < len(arr[0]) and -1 < i:
        arr[i][j] = seq
        seq = seq + 1 if seq < 9 else 0
        i -= 1
        j += 1
    return i+1, j-1, seq


def main():
    m, n = eval(input())
    arr = [[0 for _ in range(m)] for j in range(n)]
    i, j, seq = 0, 0, 0
    while i < n and j < m:
        i, j, seq = down_diag(arr, i, j, seq)
        if i + 1 >= len(arr):
            i, j, seq = top_diag(arr, i, j+1, seq)
        else:
            i, j, seq = top_diag(arr, i+1, j, seq)

        if j+1 >= len(arr[0]):
            i += 1
        else:
            j += 1
    for row in arr:
        print(*row)


if __name__ == '__main__':
    main()
