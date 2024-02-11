def main():
    x, y = 0, 0
    last_move = None
    while command := input().split():

        match command:
            case ["move", vect]:
                match vect:
                    case "s":
                        y -= 1
                        last_move = vect
                    case "n":
                        y += 1
                        last_move = vect
                    case "w":
                        x -= 1
                        last_move = vect
                    case "e":
                        x += 1
                        last_move = vect
                    case _:
                        print(f"Cannot move to {vect}")

            case ["move"]:
                match last_move:
                    case "s":
                        y -= 1
                    case "n":
                        y += 1
                    case "w":
                        x -= 1
                    case "e":
                        x += 1
                    case _:
                        pass

            case ["retreat"]:
                match last_move:
                    case "s":
                        y += 1
                    case "n":
                        y -= 1
                    case "w":
                        x += 1
                    case "e":
                        x -= 1
                    case _:
                        pass

            case ["info", 'x']:
                print(x)
            case ['info', 'y']:
                print(y)
            case ['info', 'xy']:
                print(x, y)

            case ["say", *message]:
                print(*message)
            case _:
                pass

    print(x, y)


if __name__ == '__main__':
    main()
