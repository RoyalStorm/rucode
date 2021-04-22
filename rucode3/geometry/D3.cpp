from math import fabs

n = int(input().strip())

x = []
y = []
for i in range(n):
    a, b = map(int, input().strip().split())

    if i == 0:
        x.insert(n - 1, a)
        y.insert(n - 1, b)

    x.insert(i, a)
    y.insert(i, b)

res = sum([(x[i] * y[i + 1]) - (x[i + 1] * y[i]) for i in range(n)])
print(fabs(res) / 2)