import sys


a = sys.stdin.buffer.read()
a = a.decode('MACCYRILLIC')
a = a.encode('CP855')
a = a.decode('CP1251')
a = a.encode('KOI8-R')
a = a.decode('KOI8_R')
print(a)