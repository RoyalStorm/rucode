n, s, f = map(int, input().strip().split())
m = [[int(i) for i in input().strip().split()] for j in range(0, n)]

s -= 1
f -= 1

inf = 9e6

used = []
distance = []
for _ in range(0, n):
    used.append(False)
    distance.append(inf)

distance[s] = 0


def dks():
    for i in range(0, n):
        min_dist = inf
        v = -1

        for j in range(0, n):
            if used[j] is False and distance[j] < min_dist:
                min_dist = distance[j]
                v = j

        if v < 0:
            break

        for j in range(0, n):
            if used[j] is False and m[v][j] != -1:
                if distance[v] + m[v][j] < distance[j]:
                    distance[j] = distance[v] + m[v][j]

        used[v] = True

    return distance[f]


res = dks()
print(res if res != inf else -1)