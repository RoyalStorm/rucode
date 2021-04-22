#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;

	int s_len = s.length();

	const int alphabet_len = 51;
	std::vector<long long> pows(s_len, 1);

	for (size_t i = 1; i < pows.size(); ++i)
		pows[i] = pows[i - 1] * alphabet_len;

	std::vector<long long> hashes(s_len);
	for (size_t i = 0; i < s_len; ++i) {
		hashes[i] = (s.at(i) + 1) * pows[i];
		if (i > 0)
			hashes[i] += hashes[i - 1];
	}

	long res = 0;
	for (int i = 1; i <= s_len; ++i) {

		std::vector<long long> substr_hashes(s_len - i + 1);
		for (int j = 0; j < s_len - i + 1; ++j) {
			long long h = hashes[i + j - 1];
			if (j > 0)
				h -= hashes[j - 1];

			h *= pows[s_len - j - 1];
			substr_hashes[j] = h;
		}

		std::set<long long> s = std::set<long long>(substr_hashes.begin(), substr_hashes.end());
		res += s.size();
	}

	std::cout << res;
}