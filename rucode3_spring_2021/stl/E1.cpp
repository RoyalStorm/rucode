#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

const ll INF = INT_MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> pos(n+1, -1);
    vector<ll> p(n + 1, -1);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    reverse(a.begin(), a.end());
    vector<ll> d(n + 1, INF);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
        if (d[j - 1] <= a[i] && a[i] < d[j])
        {
            p[i] = pos[j-1];
            d[j] = a[i];
            pos[j] = i;
        }
    }
    ll ans=0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] != -INF && d[i] != INF)
            ans ++;
    }
    cout << ans << '\n';
    ll t = pos[ans];
    vector<ll> pat;
    while (t != -1)
    {
        pat.push_back(t);
        t = p[t];
    }
    for (int i = 0; i < pat.size(); i++)
        cout << n-pat[i] << ' ';
}



#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <tr2/dynamic_bitset>

#define int int64_t

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

vector<int> v;

template<typename T>
ostream& operator<<(ostream &out, pair<T, T> &a){
    out << a.first << ' ' << a.second << '\n';
    return out;
}

template<typename T>
istream& operator>>(istream &in, pair<T, T> &a){
    in >> a.first >> a.second;
    return in;
}

template<typename T>
istream& operator>>(istream &in, vector<T> &a){
    for(auto &i: a)
        in >> i;
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a){
    for(auto &i: a)
        out << i << ' ';
    return out;
}

int32_t main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), idx(n, -1);
    cin >> a;
    vector<int> d(n + 1, INT_MIN), p(n + 1, -1);
    d[0] = INT_MAX;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i], greater<>()) - d.begin();
        if (d[j - 1] > a[i] && a[i] > d[j]) {
            d[j] = a[i];
            p[j] = i;
            idx[i] = p[j - 1];
        }
    }
    int cur = 0;
    while (cur < n && d[cur + 1] != INT_MIN)
        cur++;
    cout << cur << '\n';
    stack<int> ans;
    int last = p[cur];
    ans.push(last);
    while (idx[last] != -1) {
        last = idx[last];
        ans.push(last);
    }
    while (!ans.empty()) {
        cout << ans.top() + 1 << ' ';
        ans.pop();
    }
}