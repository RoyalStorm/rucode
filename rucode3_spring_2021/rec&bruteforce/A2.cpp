#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 1; i <= n; i++)
        a.push_back(i);
    do{
        bool take = true;
        for(int i = 0; i < n - 1; i++)
            if(abs(a[i] - a[i + 1]) < k)
                take = false;
        if(take){
            for(auto i: a)
                cout << i << ' ';
            cout << '\n';
        }
    } while(next_permutation(a.begin(), a.end()));
}