def main():
    count = 0
    max_elem = None
    while elem := input():
        if count == 0:
            count += 1
            max_elem = elem
        elif max_elem == elem:
            count += 1
        else:
            count -= 1

    return eval(max_elem)


if __name__ == '__main__':
    print(main())
