#include <bits/stdc++.h>

#define int int64_t

using namespace std;

vector<vector<int>> ans;
vector<int> cur;

void cnt(int rem, int mn = -1){
    if(rem == 0) {
        ans.push_back(cur);
        return;
    }
    for(int i = 1; i <= min(rem, mn != -1 ? mn : (int)LLONG_MAX); i++){
        cur.push_back(i);
        cnt(rem - i, min(i, mn != -1 ? mn : (int)LLONG_MAX));
        cur.pop_back();
    }
}

int32_t main() {
    int n;
    cin >> n;
    cnt(n);
    for(const auto& i: ans){
        for(auto j: i)
            cout << j << ' ';
        cout << '\n';
    }
}



#include <iostream> 
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long ull;
const ull MD = 1000000007;

template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (auto& i : a)
        cin >> i;
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    for (auto& i : a)
        cout << i << ' ';
    return out;
}

int n;
vector<int> a;

void rec(int s, int last)
{
    if (s == n)
    {
        cout << a << '\n';
        return;
    }
    if (s > n)
        return;
    for (int i = 1; i <= min(last, n - s); i++)
    {
        a.push_back(i);
        rec(s + i, i);
        a.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    rec(0, n);
}