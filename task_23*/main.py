def LookSay():
    yield 1
    seq = '1'
    while True:
        count = 1
        new_seq = ''
        for i in range(len(seq)):
            if i + 1 < len(seq) and seq[i] == seq[i+1]:
                count += 1
            else:
                new_seq += str(count) + str(seq[i])
                count = 1
        yield from map(int, new_seq)
        seq = new_seq
