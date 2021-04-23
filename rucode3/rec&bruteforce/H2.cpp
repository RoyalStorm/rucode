#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int c[100][100];

void precalc(){
    for(int i = 0; i <= 32; i++)
        c[i][0] = 1;
    for(int i = 1; i <= 32; i++)
        for(int j = 1; j <= 32; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

int32_t main() {
    precalc();
    int n, k, p;
    cin >> n >> k >> p;
    int prev = -1;
    for(int i = 0; i < k; i++){
        for(int j = max(prev + 1, (int)1); j <= n; j++){
            if(p < c[n - j][k - i - 1]){
                prev = j;
                cout << j << ' ';
                break;
            }
            else
                p -= c[n - j][k - i - 1];
        }
    }
}






#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	vector<vector<ull>> c(n + 1, vector<ull>(k + 1));
	for (int i = 0; i <= n; i++)
		c[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	vector<int> ans(k);
	vector<bool> used(n + 1);
	for(int i=0; i<k; i++)
		for(int a=1; a<=n; a++)
			if (!used[a] && (!i || ans[i-1]<a))
			{
				if (p < c[n-a][k-i-1])
				{
					ans[i] = a;
					used[a] = true;
					break;
				}
				else
					p -= c[n - a][k - i - 1];
			}
	for (int i = 0; i < k; i++)
		cout << ans[i] << ' ';
}