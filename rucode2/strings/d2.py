a = input().strip()
b = input().strip()


def z_f(s):
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

    return z_func


z = z_f(b + '_' + a)
res = []
for i, el in enumerate(z):
    if el == len(b):
        res.append(i - len(b))

print(len(res))
print(' '.join(map(str, sorted(res))))