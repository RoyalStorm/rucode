#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll ways[102][102];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  ways[1][1] = 1;
  for(int i = 2; i <= 100; i ++){
    ways[i][i] = 1;
    for(int j = i - 1; j >= 1; j --)
      ways[i][j] = ways[i][j + 1] + ways[i - j][j];
  }
  int n; ll p;
  cin >> n >> p;
  if(n == 0 && p == 0){
    cout << 0;
    return 0;
  }
  ++ p;
  if(ways[n][1] < p){
    cout << "N/A";
    return 0;
  }
  vector<int> ans;
  for(int take = 1; n > 0 && p > 0; take ++){
    if(ways[n][take] - ways[n][take + 1] >= p){
      n -= take;
      ans.push_back(take);
      -- take;
    }else{
      p -= (ways[n][take] - ways[n][take + 1]);
    }
  }
  cout << ans.size() << "\n";
  for(int x : ans)
    cout << x << " ";
}