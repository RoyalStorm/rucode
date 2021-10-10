#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;
    int d[n][2];
    d[n - 1][0] = d[n - 1][1] = 1;
    for(int i = n - 2; i >= 0; i--){
        d[i][0] = d[i + 1][0] + d[i + 1][1];
        d[i][1] = d[i + 1][0];
    }
    for(int i = 0; i < n; i++){
        if(k < d[i][0])
            cout << 0;
        else{
            k -= d[i][0];
            cout << 1;
        }
    }
}





#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f first
#define s second
#define bust ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = INT_MAX;
const int mod = 1e9 + 7;



void solve ()
{
    ll n, k;
    cin >> n >> k;

    vector < ll > fib(n + 1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    vector < int > vc (n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (i != 0 && vc[i - 1] == 1) continue ;
        if (k >= fib[n - i])
        {
            k -= fib[n - i];
            vc[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << vc[i];
    cout << "\n";
}
int main()
{
    bust
    int t = 1;
    //cin >> t;
    //scanf("%d", &t);
    while (t--)
        solve();
	return 0;
}










#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> ans(n);
	vector<ull> fib(n + 2);
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	for (int i = 0; i < n; i++)
	{
		if (k < fib[n - i - 1])
			ans[i] = 0;
		else
		{
			ans[i] = 1;
			k -= fib[n - i - 1];
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << '\n';
}