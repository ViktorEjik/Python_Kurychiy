def get_arrey():
    is_poss = True
    is_neg = True
    arr = list()
    while num := int(input()):
        arr.append(num)
        if num > 0:
            is_neg = False
        elif num < 0:
            is_poss = False
    return (is_poss, is_neg, arr)


def max_subarray(arr):
    current_sum = max(0, arr[0])
    best_sum = current_sum
    for x in arr[1:]:
        current_sum = max(x, current_sum + x)
        best_sum = max(best_sum, current_sum)
    return best_sum


def main():
    is_poss, is_neg, arr = get_arrey()
    if is_poss:
        print(sum(arr))
    elif is_neg:
        print(max(arr))
    else:
        print(max_subarray(arr))



if __name__ == '__main__':
    main()
