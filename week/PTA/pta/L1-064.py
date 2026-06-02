import re
n=int(input())
for i in range(n):
    a=input()
    print(a)
    print('AI: ', end='')
    a = re.sub(r'(\s+)', ' ', a)
    a = list(a.strip().replace(' !', '!').replace(' ,', ',').replace(' .', '.').replace(' ?', '?').replace(' \'', '\''))
    for i in range(len(a)):
        if a[i].isupper() and a[i] != 'I':
            a[i] = a[i].lower()
    a = ''.join(a)
    a = re.sub(r'(\bcan you\b)', '_I can', a)
    a = re.sub(r'(\bcould you\b)', '_I could', a)
    a = re.sub(r'(\bI\b)', 'you', a)
    a = re.sub(r'(\bme\b)', 'you', a)
    a = re.sub(r'(\?)', '!', a)
    a = re.sub(r'(\b_I\b)', 'I', a)
    print(a)