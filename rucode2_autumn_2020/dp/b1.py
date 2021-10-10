s1 = input().strip()
s2 = input().strip()

lcs = [[0 for _ in range(0, len(s2) + 1)] for _ in range(0, len(s1) + 1)]
for i in range(0, len(s1)):
    for j in range(0, len(s2)):
        if s1[i] == s2[j]:
            lcs[i][j] = lcs[i - 1][j - 1] + 1
        else:
            lcs[i][j] = max((lcs[i][j - 1], lcs[i - 1][j]))

res = []
indexes = []
i, j = len(s1) - 1, len(s2) - 1
while i >= 0 and j >= 0:
    if s1[i] == s2[j]:
        res.append(s1[i])
        indexes.append([i, j])
        i, j = i - 1, j - 1
    elif lcs[i - 1][j] > lcs[i][j - 1]:
        i -= 1
    else:
        j -= 1

a = []
b = []
for i in indexes:
    a.append(i[0] + 1)
    b.append(i[1] + 1)

print(len(res))
print(' '.join(map(str, list(reversed(a)))))
print(' '.join(map(str, list(reversed(b)))))
