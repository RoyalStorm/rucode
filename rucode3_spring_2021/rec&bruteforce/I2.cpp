#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	cout << "1";
	for (int i = 1; i < k; ++i) {
		cout << "0";
	}
}



#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fori for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const ll p = 1e9 + 7;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    cout << (k-1) % n + 1;
}


Крашится на тесте 10 10
Правильный ответ 9