import re

GLASS = r'[aouieAOUIE]'
SOGL ='[qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM\']'
START_GLASS = r'^[aouieAOUIE]'
get_word =lambda x: re.search(r'(^[^A-Za-z\']*)([a-zA-Z\']+)(.*)', x)


def pig_latin(word: str):
    flag = bool(re.match(r'.*[A-Z].*', word))
    char_r = ''
    char_l = ''
    if not word or not re.findall(GLASS, word):
        return word
    
    tmp = get_word(word)
    char_l = tmp.group(1)
    word = tmp.group(2)
    char_r = tmp.group(3)
    
    if not word or not re.findall(GLASS, word):
        return char_l + word + pig_latin(char_r)

    if re.findall(GLASS+'+', word)[0] == word:
        return char_l + word + 'yay' + pig_latin(char_r)
    if re.match(START_GLASS, word):
        if len(re.findall(GLASS, word)) - len(re.findall('.*[aouieAOUIE]{2}.*', word)) == 1:
            word += 'yay'
        else:
            word = word.lower()
            word = re.sub(r'^([aouie]+[^aouie]*)(.*)', r'\2\1ay', word)
            if flag:
                word = word[0].upper()+word[1:]
    elif re.match('^{}'.format(SOGL), word):
        word = word.lower()
        word = re.sub(r'^({}+)(.*)'.format(SOGL), r'\2\1ay', word)
        if flag:
            word = word[0].upper()+word[1:]
    return char_l + word + pig_latin(char_r)
    


if __name__ == '__main__':
    i=0
    while s := input():
        s_l = map(pig_latin, s.split())
        print(*s_l)
