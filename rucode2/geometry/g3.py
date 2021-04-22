from math import fabs

n = int(input().strip())

x = []
y = []
for i in range(0, n):
    a, b = map(int, input().strip().split())

    if i == 0:
        x.insert(n - 1, a)
        y.insert(n - 1, b)

    x.insert(i, a)
    y.insert(i, b)

res = 0
for i in range(0, n):
    res += (x[i] * y[i + 1]) - (x[i + 1] * y[i])

print(fabs(res) / 2)