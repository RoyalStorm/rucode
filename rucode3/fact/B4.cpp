#include <bits/stdc++.h>

using namespace std;

bool prime[10000001];
short int cnt_p[10000001];

void precalc(){
    memset(prime, true, sizeof prime);
    for(int i = 2; i <= 10000000; i++){
        if(prime[i]){
            cnt_p[i]++;
            for(int j = 2 * i; j <= 10000000; j += i)
                prime[j] = false, cnt_p[j]++;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    precalc();
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
        if(cnt_p[i] >= 3)
            cout << i << ' ';
}







#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f first
#define s second
#define bust ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 1e7 + 1;
int mind[N];


int main()
{
    bust
    int n;
    cin >> n;
    for (int i = 2; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
            if (mind[j] == 0) mind[j] = i;
    }
    for (int i = 2; i < N; ++i)
    {
        if (mind[i] == i)
        {
            for (int j = i + i; j < N; j += i)
                mind[j] = 0;
        }
    }
    for (int i = 2; i < N; ++i)
    {
        if (mind[i] == i)
        {
            for (int j = i + i; j < N; j += i)
                ++mind[j];
            mind[i] = 1;
        }
    }
    for (int i = 30; i <= n; ++i)
    {
        if (mind[i] > 2)
            cout << i << " ";
    }
    cout << "\n";
	return 0;
}