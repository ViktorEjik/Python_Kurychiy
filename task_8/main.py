def main():
    segments = list(eval(input()))
    n = len(segments)

    points = [None] * (n * 2)

    for i in range(n):
        points[i * 2] = (segments[i][0], False)
        points[i * 2 + 1] = (segments[i][1], True)

    points = sorted(points, key=lambda x: x[0])
    result = 0
    counter = 0

    for i in range(0, n * 2):
        if i > 0 and points[i][0] > points[i - 1][0] and counter > 0:
            result += points[i][0] - points[i - 1][0]
        if points[i][1]:
            counter -= 1
        else:
            counter += 1
    return result


if __name__ == '__main__':
    print(main())
