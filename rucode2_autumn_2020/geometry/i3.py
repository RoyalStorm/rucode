def cp(x_1, y_1, x_2, y_2):
    return x_1 * y_2 - y_1 * x_2


n = int(input().strip())
coordinates = [list(map(int, input().strip().split())) for _ in range(0, n)]

positive_cp = 0
negative_cp = 0
for i in range(0, n):
    x_1 = coordinates[(i + 1) % n][0] - coordinates[i][0]
    y_1 = coordinates[(i + 1) % n][1] - coordinates[i][1]
    x_2 = coordinates[i][0] - coordinates[(i - 1 + n) % n][0]
    y_2 = coordinates[i][1] - coordinates[(i - 1 + n) % n][1]

    if cp(x_1, y_1, x_2, y_2) > 0:
        positive_cp += 1
    else:
        negative_cp += 1

print('Yes' if positive_cp * negative_cp == 0 else 'No')