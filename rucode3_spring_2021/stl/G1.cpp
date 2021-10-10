#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, x;
	cin >> n >> m;
	set<pair<ll, ll>> s, vl, vr;
	vector<pair<ll, ll>> h;
	s.insert({ n, 0 });
	vl.insert({ 0, n });
	vr.insert({ 0, n });
	for (ll i = 0; i < m; i++) {
		//cout << i + 1 << " - ";
		cin >> x;
		if (x > 0) {
			ll maxi = (s.size() > 0)?(--s.end())->first : 0;
			if (maxi < x) {
				cout << -1 << "\n";
				h.push_back({ -1,-1 });
			}
			else {
				auto j = s.lower_bound({ maxi,0 });
				pair<ll, ll> d = *j;
				cout << d.second + 1 << "\n";
				s.erase(j);
				vr.erase({ d.second,d.first });
				vl.erase({ n - d.second - d.first,d.first });
				if (d.first > x) {
					s.insert({ d.first - x, d.second + x });
					vr.insert({ d.second + x, d.first - x });
					vl.insert({ n - d.first - d.second,d.first - x });
				}
				h.push_back({d.second, x});
			}
		}
		else {
			x *= -1;
			x--;
			if (h[x].second > 0) {
				pair<ll, ll> d = { h[x].first, h[x].second };
				ll pr = h[x].second + h[x].first, pl = n - h[x].first;
				auto jr = vr.lower_bound({ pr, 0 }), jl = vl.lower_bound({ pl,0 });
				if (jr != vr.end() && jr->first == pr) {
					d.second += jr->second;
					s.erase({ jr->second, jr->first });
					vl.erase({n - jr->first - jr->second,jr->second});
					vr.erase(jr);

				}
				if (jl != vl.end() && jl->first == pl) {
					d.second += jl->second;
					d.first = n - jl->second - jl->first;
					s.erase({ jl->second, n - jl->second - jl->first });
					vr.erase({ n - jl->first - jl->second,jl->second });
					vl.erase(jl);
				}
				s.insert({ d.second, d.first });
				vr.insert(d);
				vl.insert({ n - d.first - d.second, d.second });
			}
			h[x] = { -1,-1 };
			h.push_back({ -1,-1 });
		}
		/*cout << "\n-----------------\n";
		for (auto j : s) {
			cout << "{ " << j.first << " , " << j.second << " } ";
		}
		cout << "\n";
		for (auto j : vr) {
			cout << "{ " << j.first << " , " << j.second << " } ";
		}
		cout << "\n";
		for (auto j : vl) {
			cout << "{ " << j.first << " , " << j.second << " } ";
		}
		cout << "\n----------------\n";*/
	}
	return 0;
}






#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	map<int, pair<int, int>> requests;

	map<int, int> manager_start;
	map<int, set<int>> manager_length;

	int N{ 0 }, M{ 0 };
	cin >> N >> M;

	manager_start[1] = N;
	manager_length[N] = set<int>();
	manager_length[N].insert(1);

	std::vector<int> answer;

	for (int i = 0; i < M; ++i) {
		int request{ 0 };

		cin >> request;

		if (request > 0) {
			auto ptr = max_element(manager_length.begin(), manager_length.end());

			if (ptr->first >= request) {

				int start = *ptr->second.begin();

				manager_start.erase(start);
				if (ptr->first > request) {
					
					if (manager_length.find(ptr->first - request) == manager_length.end()) {
						manager_length[ptr->first - request] = set<int>();
					}
					manager_length[ptr->first - request].insert(start + request);

					manager_start[start + request] = ptr->first - request;
				}

				requests[i] = pair<int, int>(start, request);
				answer.push_back(start);

				ptr->second.erase(ptr->second.begin());
				if (ptr->second.size() == 0) {
					manager_length.erase(ptr);
				}
			}
			else {
				answer.push_back(-1);

				requests[i] = pair<int, int>(0, -1);
			}
		}
		else {
			request = -1 * request;
			request -= 1;

			if (requests[request].second != -1) {

				auto cell = requests[request];

				auto ptr = manager_start.lower_bound(cell.first);
				if (ptr != manager_start.end()) {
					if (cell.first + cell.second == ptr->first) {
						cell.second += ptr->second;

						manager_length[ptr->second].erase(ptr->first);
						if (manager_length[ptr->second].size() == 0) {
							manager_length.erase(ptr->second);
						}
						manager_start.erase(ptr);
						
					}
				}

				ptr = manager_start.lower_bound(cell.first);
				if (ptr != manager_start.begin()) {
					ptr--;

					if (ptr->first + ptr->second == cell.first) {
						cell.first = ptr->first;
						cell.second = ptr->second + cell.second;

						manager_length[ptr->second].erase(ptr->first);
						if (manager_length[ptr->second].size() == 0) {
							manager_length.erase(ptr->second);
						}
						manager_start.erase(ptr);
					}
				}

				manager_start[cell.first] = cell.second;
				manager_length[cell.second].insert(cell.first);
			}
		}
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}






#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<random>

using namespace std;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef long double ld;

struct mem_locator {

    struct mem_seg {
        s64 i; // начало блока
        s64 len; // длина
        bool is_free;
    };

    struct cmp_len {
        bool operator () (const mem_seg& Lhs, const mem_seg& Rhs) const {
            if (Lhs.len == Rhs.len) {
                return Lhs.i < Rhs.i;
            }
            return Lhs.len > Rhs.len;
        }
    };

    struct cmp_ind {
        bool operator () (const mem_seg& Lhs, const mem_seg& Rhs) const {
            return Lhs.i < Rhs.i;
        }
    };

    set<mem_seg, cmp_len> segs_len;
    set<mem_seg, cmp_ind> segs_ind;

    mem_locator(s64 len) {
        mem_seg val = { 0, len, true };
        segs_len.insert(val);
        segs_ind.insert(val);
    }
    

    // выделяет память длиной len
    // вернет номер начальной ячейки
    // вернет -1, если не удалось выделить
    s64 locate(s64 len) {

        s64 res = -1;
        if (!segs_len.empty() && segs_len.begin()->len >= len) {

            res = segs_len.begin()->i;

            // segs_ind
            {
                auto it = segs_ind.find({ segs_len.begin()->i });
                auto val = *it;
                segs_ind.erase(it);

                segs_ind.insert({ val.i, len, false });

                if (val.len != len) {
                    segs_ind.insert({ val.i + len, val.len - len, true });
                }
            }

            // segs_len
            {
                auto it = segs_len.begin();
                auto val = *it;
                segs_len.erase(it);

                if (val.len != len) {
                    segs_len.insert({ val.i + len, val.len - len, true });
                }
            }
        }
        return res;
    }

    // принимает начала блока, который был выделен ранее, и освобождает его
    void free(s64 i) {

        auto it = segs_ind.find({ i });

        if (it != segs_ind.begin() && next(it) != segs_ind.end() && prev(it)->is_free && next(it)->is_free) {

            s64 i = prev(it)->i;
            s64 len = prev(it)->len + it->len + next(it)->len;

            segs_len.erase(*prev(it));
            segs_len.erase(*next(it));

            segs_ind.erase(prev(it), next(it, 2));

            segs_ind.insert({ i, len, true });
            segs_len.insert({ i, len, true });
        }
        else if (it != segs_ind.begin() && prev(it)->is_free) {

            it = prev(it);

            s64 i = it->i;
            s64 len = it->len + next(it)->len;

            segs_len.erase(*it);

            segs_ind.erase(it, next(it, 2));

            segs_len.insert({ i, len, true });
            segs_ind.insert({ i, len, true });
        }
        else if (next(it) != segs_ind.end() && next(it)->is_free) {
            
            s64 i = it->i;
            s64 len = it->len + next(it)->len;

            segs_len.erase(*next(it));

            segs_ind.erase(it, next(it, 2));

            segs_len.insert({ i, len, true });
            segs_ind.insert({ i, len, true });
        }
        else {
            auto seg = *it;
            segs_ind.erase(it);

            seg.is_free = true;

            segs_ind.insert(seg);
            segs_len.insert(seg);
        }
    }
};

int main() {
    //ifstream cin("input.txt");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    s64 n, m;
    cin >> n >> m;

    mem_locator mem(n);

    vector<s64> Res;
    while (m--) {
        s64 k;
        cin >> k;

        if (k > 0) {
            Res.push_back(mem.locate(k));
            cout << (Res.back() != -1 ? Res.back() + 1 : -1) << "\n";
        }
        else {
            k = abs(k);
            k--;

            if (Res[k] >= 0) {
                mem.free(Res[k]);
            }

            Res.push_back(-101);
        }
    }

    return 0;
}