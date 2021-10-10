//Дейкстра для разреженных графов

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
const int INF = 1000000000;

struct X_{
    int x;
    int y1;
    int y2;
    int id;
    bool l;
};

bool comp(X_ u, X_ v) {
    if (u.x != v.x)
        return u.x < v.x;
    else
        return u.y1 > v.y1;
}

bool comp1(pair<int, int> u, pair<int, int> v) {
    return v.second > u.second;
}

int main() {
    int n;
    cin >> n;

    vector<X_> XS;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y2 < y1) swap(y1, y2);
        if (x2 < x1) swap(x1, x2);

        XS.push_back({x1, y1, y2, i,true});
        XS.push_back({x2, y1, y2, i,false});
    }
    sort(XS.begin(), XS.end(), comp);

    vector<bool> used(1e5);
    set<pair<int, int>, decltype(&comp1)> s(comp1);
    int ans = 1;
    s.insert({XS[0].y1, XS[0].y2});
    used[XS[0].id] = true;

    for (int i = 1; i < 2*n; i++) {
        if (XS[i].l) {
            auto u = s.lower_bound({std::numeric_limits<int>::min(), XS[i].y2});
            if (u == s.end() || u->first > XS[i].y1) {
                ans++;
                used[XS[i].id] = true;
                s.insert({XS[i].y1, XS[i].y2});
            }
        } else {
            if (used[XS[i].id]) {
                s.erase({XS[i].y1, XS[i].y2});
            }
        }
    }

    cout << ans;
}




#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Event {
    Event() {};
    Event(int x, int y1, int y2, int type): x(x), y1(y1), y2(y2), type(type) {}
    int x;
    int y1;
    int y2;
    int type;
};

bool operator<(const Event& first, const Event& second) {
    if (first.x == second.x) {
        return first.y1 < second.y1;
    }
    else {
        return first.x < second.x;
    }
}
int main() {
    int n;
    cin >> n;
    vector<Event> events(2*n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events[2*i] = Event(min(x1,x2), min(y1,y2), max(y1, y2), 0);
        events[2*i+1] = Event(max(x1, x2), min(y1, y2), max(y1, y2), 1);
    }
    sort(events.begin(), events.end());
    set<pair<int,int> > work;
    int answer = 0;
    for (int i = 0; i < 2*n; ++i) {
        if (events[i].type == 0) {
            auto pos = work.upper_bound(make_pair(events[i].y2, events[i].y1));
            if (pos == work.end()) {
                work.insert(make_pair(events[i].y2, events[i].y1));
            }
            else if (!(pos->second < events[i].y1)) {
                work.insert(make_pair(events[i].y2, events[i].y1));
            }
        }
        else {
            if (work.count(make_pair(events[i].y2, events[i].y1)) == 1) {
                ++answer;
            }
            work.erase(make_pair(events[i].y2, events[i].y1));
        }
    }
    cout << answer << endl;
}






#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct MyCell {

	int first;
	int second;

	MyCell(int a, int b) : first(a), second(b) {};

	bool operator < (const MyCell& c) const {
		return second < c.second;
	}
};

struct Rectangle {
	pair<int, int> left;
	pair<int, int> right;
};

int main() {

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N{ 0 };
	cin >> N;

	vector<Rectangle> rects(N);
	for (int i = 0; i < N; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x2 < x1) {
			swap(x1, x2);
			swap(y1, y2);
		}

		rects[i].left = pair<int, int>(x1, y1);
		rects[i].right = pair<int, int>(x2, y2);
	}

	map<int, vector<pair<int, int>>> line;

	for (int i = 0; i < N; ++i) {

		if (line.find(rects[i].left.first) == line.end()) {
			line[rects[i].left.first] = vector<pair<int, int>>(1, pair<int, int>(i, 0));
		}
		else {
			line[rects[i].left.first].push_back(pair<int, int>(i, 0));
		}

		if (line.find(rects[i].right.first) == line.end()) {
			line[rects[i].right.first] = vector<pair<int, int>>(1, pair<int, int>(i, 1));
		}
		else {
			line[rects[i].right.first].push_back(pair<int, int>(i, 1));
		}
	}

	set<MyCell> opened;

	int answer{ 0 };
	for (auto ptr = line.begin(); ptr != line.end(); ++ptr) {

		for (auto p : ptr->second) {

			MyCell cell(min(rects[p.first].left.second, rects[p.first].right.second), max(rects[p.first].left.second, rects[p.first].right.second));

			if (p.second == 1) {
				opened.erase(cell);
			}
			else {
				auto ptr = opened.lower_bound(cell);

				if (ptr == opened.end() || ptr->first > cell.second) {
					answer += 1;
					opened.insert(cell);
				}
			}
		}
	}

	cout << answer;

	return 0;
}