def main():
    max = int(input())
    second_max = None

    while num := int(input()):
        if num < max:
            second_max = num
            break
        elif max < num:
            second_max = max
            max = num
            break
    if second_max is None:
        print('NO')
        return

    while num := int(input()):
        if second_max < num < max:
            second_max = num
        elif max < num:
            second_max = max
            max = num
    print(second_max)


if __name__ == '__main__':
    main()
