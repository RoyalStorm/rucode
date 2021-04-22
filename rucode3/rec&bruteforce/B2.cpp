#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void make_seq(int n, int open = 0, int closed = 0, string s = "") {
    if (open + closed == 2 * n)
        cout << s << '\n';

    if (open < n)
        make_seq(n, open + 1, closed, s + '(');

    if (closed < open)
        make_seq(n, open, closed + 1, s + ')');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    make_seq(n);

    return 0;
}