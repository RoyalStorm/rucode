s = input().strip()

z_func = [0]

l = r = -1
for i in range(1, len(s)):
    z_func.append(0)

    if i <= r:
        z_func[i] = min(r - i + 1, z_func[i - l])

    while i + z_func[i] < len(s) and s[z_func[i]] == s[i + z_func[i]]:
        z_func[i] += 1

    if i + z_func[i] - 1 > r:
        r = i + z_func[i] - 1
        l = i

z_func[0] = len(s)
print(' '.join(map(str, z_func)))