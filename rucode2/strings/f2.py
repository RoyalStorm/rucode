import sys

s = sys.stdin.readline().strip()


def z(s):
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


z_func = z(s)
res = len(s)
for i, el in enumerate(z_func):
    if i + el == len(s):
        res = i
        break

print(res)