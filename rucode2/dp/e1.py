n = int(input().strip())
a = [int(x) for x in input().strip().split()]

res = 0
down_or_up = None
last = a[0]
for i in range(1, n):
    if last == a[i]:
        res += 1
    elif a[i] < last:
        if down_or_up == 'd':
            res += 1
        else:
            down_or_up = 'd'
    elif down_or_up == 'u':
        res += 1
    else:
        down_or_up = 'u'

    last = a[i]

print(res)

"""
3
1 1 1

5
1 2 3 1 2

5
1 2 1 3 2

2
1 1

5
4 3 2 1 0

4
5 5 8 5
"""
