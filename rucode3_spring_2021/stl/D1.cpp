#include <iostream>
#include <set>

using namespace std;

const int max_free_rooms = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < max_free_rooms; ++i)
        s.insert(i + 1);

    for (int i = 0; i < n; ++i) {
        int room;
        cin >> room;

        if (room > 0) {
            auto reserved_room = *s.lower_bound(room);
            
            cout << reserved_room << '\n';
            s.erase(reserved_room);
        } else
            s.insert(-room);
    }

    return 0;
}