s1 = input().strip()
s2 = input().strip()

l = [[0 for j in range(0, len(s2) + 1)] for i in range(0, len(s1) + 1)]

for i in range(0, len(s1) + 1):
    l[i][0] = i
for i in range(0, len(s2) + 1):
    l[0][i] = i

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        l[i][j] = min(l[i - 1][j] + 1, l[i][j - 1] + 1, l[i - 1][j - 1] + (0 if s1[i - 1] == s2[j - 1] else 1))

print(l[len(s1)][len(s2)])
