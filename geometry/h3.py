from math import fabs


def square(x, y):
    res = 0
    for i in range(0, len(x) - 1):
        res += (x[i] * y[i + 1]) - (x[i + 1] * y[i])

    return fabs(res) / 2


a_x, a_y = map(int, input().strip().split())
b_x, b_y = map(int, input().strip().split())
c_x, c_y = map(int, input().strip().split())

p_x, p_y = map(int, input().strip().split())

X_pab = [p_x, a_x, b_x, p_x]
Y_pab = [p_y, a_y, b_y, p_y]

X_pbc = [p_x, b_x, c_x, p_x]
Y_pbc = [p_y, b_y, c_y, p_y]

X_pca = [p_x, c_x, a_x, p_x]
Y_pca = [p_y, c_y, a_y, p_y]

X_abc = [a_x, b_x, c_x, a_x]
Y_abc = [a_y, b_y, c_y, a_y]

eps = 1e-8

t = square(X_pab, Y_pab) + square(X_pbc, Y_pbc) + square(X_pca, Y_pca)
t2 = square(X_abc, Y_abc)

if (square(X_pab, Y_pab) + square(X_pbc, Y_pbc) + square(X_pca, Y_pca)) - square(X_abc, Y_abc) < eps:
    print('In')
else:
    print('Out')