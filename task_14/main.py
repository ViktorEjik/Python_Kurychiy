def main():
    N, M = eval(input())
    max_elem_len = len(str(N))
    max_mul_len = len(str(N*N))
    len_patern = 2*max_elem_len + 6 + max_mul_len
    count_col = M // len_patern
    while count_col * len_patern + 3 * (count_col - 1) >= M:
        count_col -= 1

    print('='*M)
    for i in range(1, N + 1, count_col):
        for j in range(1, N+1):
            string = []
            for k in range(count_col):
                if i + k <= N:
                    string.append(
                        f"{i+k:.>{max_elem_len}}"
                        f".*.{j:.<{max_elem_len}}"
                        f".=.{(i+k)*j:.<{max_mul_len}}"
                    )
            print('.|.'.join(string))
        print('='*M)


if __name__ == '__main__':
    main()
