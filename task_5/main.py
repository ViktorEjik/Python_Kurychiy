def main():
    str1 = input()
    str2 = input()
    for i in range(1, len(str1)):
        index = 0
        for j in range(len(str1)):
            for k in range(j, len(str1), i):
                if index >= len(str2):
                    break
                if str1[k] == str2[index]:
                    index += 1
                else:
                    index = 0
                    break
                if len(str2) == index and k + i >= len(str1):

                    print(i)
                    return
            else:
                continue
            break
    print('No')


if __name__ == '__main__':
    main()
