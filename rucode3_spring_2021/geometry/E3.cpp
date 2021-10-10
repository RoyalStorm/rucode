n = int(input().strip())
coordinates = [list(map(int, input().strip().split())) for _ in range(n)]

cp = lambda x1, y1, x2, y2: x1 * y2 - y1 * x2

positive_cp = 0
negative_cp = 0
for i in range(n):
    x_1 = coordinates[(i + 1) % n][0] - coordinates[i][0]
    y_1 = coordinates[(i + 1) % n][1] - coordinates[i][1]
    x_2 = coordinates[i][0] - coordinates[(i - 1 + n) % n][0]
    y_2 = coordinates[i][1] - coordinates[(i - 1 + n) % n][1]

    cp_res = cp(x_1, y_1, x_2, y_2)

    if cp_res > 0:
        positive_cp += 1
    elif cp_res < 0:
        negative_cp += 1

print('YES' if positive_cp * negative_cp == 0 else 'NO')