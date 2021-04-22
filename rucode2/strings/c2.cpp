#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define alphabet_len 51
#define mod 1000000321


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    const int s_len = s.length();

    std::vector<unsigned long long> pows(s_len + 1, 1);
    std::vector<unsigned long long> hashes(s_len + 1, 0);
    for (auto i = 0; i < s_len; i++) {
        hashes[i + 1] = (s.at(i) + hashes[i] * alphabet_len) % mod;
        pows[i + 1] = (pows[i] * alphabet_len) % mod;
    }

    int m;
    std::cin >> m;

    for (auto i = 0; i < m; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        a--;
        b--;
        c--;
        d--;

        unsigned long long h_1 = (mod + hashes[b + 1] - ((hashes[a] * pows[b - a + 1]) % mod)) % mod;
        unsigned long long h_2 = (mod + hashes[d + 1] - ((hashes[c] * pows[d - c + 1]) % mod)) % mod;

        if (h_1 == h_2)
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }

    return 0;
}
