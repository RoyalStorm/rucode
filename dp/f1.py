n, k, t = map(int, input().strip().split())
T = [int(x) for x in input().strip().split()]
P = [int(x) for x in input().strip().split()]
S = [int(x) for x in input().strip().split()]

T, P, S = [list(x) for x in zip(*sorted(zip(T, P, S), key=lambda tup: tup[0]))]

d = [0 for i in range(0, n)]
for i in range(0, n):
    if S[i] <= T[i]:
        d[i] = P[i]

        for j in range(0, i):
            if abs(S[j] - S[i]) <= T[i] - T[j]:
                d[i] = max(d[i], d[j] + P[i])

print(max(d))

"""
2 РіР°РЅРіСЃС‚РµСЂР°, 10 СЃС‚РµРїРµРЅРµР№ РѕС‚РєСЂС‹С‚РѕСЃС‚Рё, 20 СЃРµРєРЅСѓРґ
2 10 20
РјРѕРјРµРЅС‚С‹ РІСЂРµРјРµРЅРё, РІ РєРѕС‚РѕСЂС‹Рµ РїСЂРёС…РѕРґСЏС‚ РіР°РЅРіСЃС‚РµСЂС‹
10 16
РёС… РґРµРЅСЊРіРё
10 11
РёС… С‚РѕР»С‰РёРЅР°
10 7

2 10 20
10 16
10 11
10 7

1 10 20
15
10
10
"""
