#pragma GCC optimize 03
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <map>
#include <tuple>
#include <math.h>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <random>
#include <chrono>

typedef long long ll;
typedef long double ld;

#define int long long

const int INF = 1e6 + 3;

using namespace std;

void FasIO() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

vector<int> p;
vector<int> r;
//vector<int> s;
vector<int> message;
vector<int> read;

void init(int n) {
    p.resize(n);
    r.resize(n, 0);
    message.resize(n, 0);
    read.resize(n,0);
    //s.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
}

int find_p(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = find_p(p[v]);
}

int find_m(int v) {
    if (p[v] == v) {
        return message[v];
    }
    return message[v] + find_m(p[v]);
}

void union_set(int a, int b) {
    a = find_p(a);
    b = find_p(b);
    if (a == b) {
        return;
    }
    if (r[a] == r[b]) {
        r[a]++;
    }
    if (r[a] < r[b]) {
        swap(a, b);
    }
    p[b] = a;
    message[b] -= message[a];
}

signed main() {
    FasIO();
    int n, m;
    cin >> n >> m;
    init(n);
    int zerg = 0;
    for (int w = 0; w < m; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            i = ((i + zerg) % n + n) % n;
            int pred = find_p(i);
            message[pred]++;
            zerg = ((30 * zerg + 239) % INF + INF) % INF;
        }
        if (t == 2) {
            int i, j;
            cin >> i >> j;
            i = ((i + zerg) % n + n) % n;
            j = ((j + zerg) % n + n) % n;
            if (find_p(i) != find_p(j)) {
                union_set(i, j);
                zerg = ((13 * zerg + 11) % INF + INF) % INF;
            }
        }
        if (t == 3) {
            int i;
            cin >> i;
            i = ((i + zerg) % n + n) % n;
            //cout << message[i] << "\n";
            int temp = find_m(i);
            temp -= read[i];
            cout << temp << "\n";
            zerg = ((100500 * zerg + temp) % INF + INF) % INF;
            read[i]+=temp;
        }
    }
    return 0;
}

Вход
100000 300000
1 40488
2 68736 37818
1 60706
1 22315
1 86830
2 55517 37818
2 77756 37818
2 46480 77756
2 37818 88423
2 97910 68736
2 55474 88423
1 79834
1 25900
1 95951
2 55205 37818
1 76111
1 3440
1 91673
1 5270
1 69286
2 55474 32057
1 46193
2 54143 37818
2 37818 49528
2 70917 46480
2 55205 47723
1 87679
1 24798
2 2210 68736
1 55242
1 70025
1 75771
2 37818 44550
1 22961
1 32061
1 71704
1 84442
2 54143 41415
2 41080 68736
2 55377 44550
1 19529
2 54862 41080
2 57465 46480
1 20041
1 38176
2 30306 77756
1 8522
1 22996
2 11763 97910
1 72810
2 32057 22913
1 56127
1 16658
2 69150 88423
2 55517 25109
1 79436
2 38966 55474
1 13078
1 95849
2 98694 22913
2 69150 15908
1 39329
2 37818 88767
2 97910 97875
1 91046
2 48923 11763
1 60981
2 54143 19946
2 30735 19946
2 1397 54143
1 44703
2 69965 55517
2 8249 47723
1 83691
1 43362
1 96929
1 42348
2 30306 92548
2 11763 30543
2 31370 46480
1 70308
2 57945 92548
1 11162
1 29273
2 88423 70567
1 25093
2 55377 9849
2 31370 73688
2 31370 94617
1 4318
1 33558
2 57465 68797
1 14293
1 30




А это ответ
13863
1
23606
24296
25342
1
25873
22039
0
15962
25011
25776
16764
3592
23441
14692
19585
24699
24537
2
24503
15991
16420
25987
3805
10236
10647
24124
15559
1
23146
4847
21192
1480
12196
25653
8872
24864
23356
25660
25733
25553
24931
25780
24866
15223
18821
17554
2
7015
23364
11185
25930
6
13622
25359
22746
24640
0
25048
25211
24503
10194
25870
1
25972
16955
2
17692
12828
2
1
25863
25199
22216
22590
25247
22139
25635
10417
25409
25789
20121
25304
25574
25145
17813
20053
25955
2
15469
15338
1
19190
1
1461
1
2
2
24592
25894
21517
24476
16498
0
25851
25473
22129
14794
25946
23679
24075
25006
25206
25263
22674
23601
1909
1
24503
1
21517
20088
3586
23656
23542
25460
0
0
1
0
1
20707
23282
25732
22979
21340
25977
24005
23166
11508
1
24174
17539
0
1
25960
24791
25496
2
21268
12110
0
21155
2
0
2983
25672
21779
25986
8358
22380
0
2
10777
25953
0
0
24667
17151
1788
2228
25423
0
25024
25524
2006
8665
25987
25508
25704
0
25130
25966
23999
24205
23475
3
25989
1926
20766
0
25743
20330
20418
24233
3566
2
25621
0
14771
18577
4


wrong answer 3rd numbers differ - expected: '23606', found: '25999'