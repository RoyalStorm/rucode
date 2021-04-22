#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> pref_open(s.size());
    vector<int> pref_close(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '(') {
            pref_open[i] = 1;
            if (i > 0) {
                pref_open[i] += pref_open[i - 1];
                pref_close[i] += pref_close[i - 1];
            }
        } else {
            pref_close[i] = 1;
            if (i > 0) {
                pref_close[i] += pref_close[i - 1];
                pref_open[i] += pref_open[i - 1];
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        if ((pref_open[r] - (l == 0 ? 0 : pref_open[l - 1])) == (pref_close[r] - (l == 0 ? 0 : pref_close[l - 1])))
            cout << 1;
        else
            cout << 0;
    }

    return 0;
}