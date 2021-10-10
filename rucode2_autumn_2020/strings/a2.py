s = input().strip()

prefixes = [0]

c = 0
for i in range(1, len(s)):
    while c > 0 and s[i] != s[c]:
        c = prefixes[c - 1]

    if s[i] == s[c]:
        c += 1

    prefixes.append(c)

print(' '.join(map(str, prefixes)))