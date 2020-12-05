n = int(input().strip())
z = [int(x) for x in input().strip().split()]

p = [0 for _ in range(n)]

for i in range(1, n):
    for j in range(z[i] - 1, -1, -1):
        if p[i + j] > 0:
            break
        else:
            p[i + j] = j + 1

print(*p)