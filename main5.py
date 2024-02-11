import ast
import sys


def main():
    text = sys.stdin.read()

    try:
        tree = ast.parse(text)
    except:
        print(False)
        return
    print('If(' in ast.dump(tree))


if __name__ == '__main__':
    main()
