#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#include <queue>
#include <ctime>
using namespace std;

#define ll unsigned long long
const int inf = 2147483647;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 0;
	map<string, ll> PersMoney, SityRes, SityMoney;
	map<string, string> PersSity;
	set<pair<ll, string>> MoneySity;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string pers, sity;
		ll money;
		cin >> pers >> sity >> money;
		PersMoney[pers] = money;
		MoneySity.erase({SityMoney[sity], sity});
		SityMoney[sity] += money;
		MoneySity.insert({ SityMoney[sity], sity });
		PersSity[pers] = sity;
	}
	int m, k;
	cin >> m >> k;
	for (int i = 0; i < k; i++) {
		int nt;
		string pers, sity;
		cin >> nt >> pers >> sity;
		if (MoneySity.size() == 1 || (--MoneySity.end())->first > (--(--MoneySity.end()))->first) {
			SityRes[(--MoneySity.end())->second] += nt - t;
		}
		t = nt;
		string town = PersSity[pers];
		MoneySity.erase({SityMoney[town],town });
		MoneySity.erase({ SityMoney[sity], sity });
		SityMoney[town] -= PersMoney[pers];
		SityMoney[sity] += PersMoney[pers];
		MoneySity.insert({ SityMoney[town],town });
		MoneySity.insert({ SityMoney[sity], sity });
		PersSity[pers] = sity;
	}
	if (MoneySity.size() == 1 || (--MoneySity.end())->first > (--(--MoneySity.end()))->first) {
		SityRes[(--MoneySity.end())->second] += m - t;
	}

	for (auto i : SityRes) {
		if (i.second > 0) cout << i.first << " " << i.second << "\n";
	}
	return 0;
}



#include <bits/stdc++.h>

using namespace std;

int n, m, k;
map<string, string> current_city;
map<string, long long> mapik;
map<string, long long> city_money;
set<pair<long long, string>> money;
map<string, int> answer;

struct info {
	int day;
	string name;
	string city;
};

string _find() {
	if(money.empty())
		return "";
	if((int) money.size() == 1)
		return money.begin()->second;

	pair<long long, string> a = *money.begin();
	money.erase(a);
	pair<long long, string> b = *money.begin();

	if(a.first == b.first) {
		money.insert(a);
		return "";
	} else {
		money.insert(a);
		return a.second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		string name, city;
		long long m;
		cin >> name >> city >> m;

		current_city[ name ] = city;
		mapik[ name ] = m;
		money.erase({city_money[ city ], city});
		city_money[ city ] -= m;
		money.insert({city_money[ city ], city});
	}
	cin >> m >> k;
	vector<info> a(k + 2);
	a[ 0 ] = {0, "", ""};
	for(int i = 1; i <= k; i++)
		cin >> a[ i ].day >> a[ i ].name >> a[ i ].city;
	a[ k + 1 ] = {m, "", ""};

	for(int i = 1; i < k + 2; i++) {
		int d = a[ i ].day - a[ i - 1 ].day;
		if(d) {
			string header = _find();
			if(header != "")
				answer[ header ] += d;
		}

		money.erase({city_money[ current_city[ a[ i ].name ] ], current_city[ a[ i ].name ]});
		city_money[ current_city[ a[ i ].name ] ] += mapik[ a[ i ].name ];
		money.insert({city_money[ current_city[ a[ i ].name ] ], current_city[ a[ i ].name ]});

		money.erase({city_money[ a[ i ].city ], a[ i ].city});
		city_money[ a[ i ].city ] -= mapik[ a[ i ].name ];
		money.insert({city_money[ a[ i ].city ], a[ i ].city});

		current_city[ a[ i ].name ] = a[ i ].city;
	}

	for(auto &[name, res] : answer)
		cout << name << ' ' << res << endl;
}



#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define int int64_t
using namespace std;


string calc_top_city(const set<pair<int, string>> &city_set) {
    // Return leader city.
    // If two best cities have same values, return empty string.
    auto top_city = city_set.end();
    --top_city;
    auto second_city = top_city;
    --second_city;
    if (top_city->first != second_city->first || city_set.size() == 1) {
        return top_city->second;
    } else {
        return "";
    }
}

void
change_worth(set<pair<int, string>> &city_set, map<string, int> &city_worth, const string &city, int worth_diff) {
    // Update all values related to change in city worth
    city_set.erase({city_worth[city], city});
    city_worth[city] += worth_diff;
    city_set.emplace(city_worth[city], city);
}


int32_t main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n;

    map<string, string> billionaire_city;
    map<string, int> billionaire_worth;
    map<string, int> top_city_days;
    map<string, int> city_worth;
    set<pair<int, string>> city_set;

    for (int i = 0; i < n; ++i) {
        string name, city;
        int worth;
        cin >> name >> city >> worth;
        billionaire_city[name] = city;
        billionaire_worth[name] = worth;

        if (!top_city_days.count(city)) {
            top_city_days[city] = 0;
            city_worth[city] = worth;
            city_set.emplace(worth, city);
        } else {
            change_worth(city_set, city_worth, city, worth);
        }
    }

    cin >> m >> k;

    vector<vector<pair<string, string>>> travels(m + 1);
    for (int i = 0; i < k; ++i) {
        int day;
        string name, city;
        cin >> day >> name >> city;
        travels[day].emplace_back(name, city);
        // initialize all seen cities
        if (!top_city_days.count(city)) {
            top_city_days[city] = 0;
            city_worth[city] = 0;
            city_set.emplace(0, city);
        }
    }

    // Calculate top city every day
    string current_top_city = calc_top_city(city_set);
    for (int i = 1; i <= m; ++i) {
        top_city_days[current_top_city] += 1;
        if (!travels[i].empty()) {
            for (const auto &[name, city_to] : travels[i]) {
                string city_from = billionaire_city[name];
                int worth = billionaire_worth[name];

                change_worth(city_set, city_worth, city_from, -worth);
                change_worth(city_set, city_worth, city_to, worth);

                billionaire_city[name] = city_to;
            }
            current_top_city = calc_top_city(city_set);
        }
    }

    map<string, int> top_cities_filtered;
    for (const auto &[city, days] : top_city_days) {
        if (days != 0 && !city.empty()) {
            top_cities_filtered.emplace(city, days);
        }
    }

    for (const auto &[city, days] : top_cities_filtered) {
        cout << city << ' ' << days << '\n';
    }
}