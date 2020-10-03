#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

unordered_map<long long, int> m;

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    long long x;
    cin >> n >> x;
    m.reserve(n);

    long long res = 0;
    long long s = 0;
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        s += a;

        auto it = m.find(s - x);
        if (it != m.end()) res += it->second;

        it = m.find(s);
        if (it == m.end()) m[s] = 1;
        else it->second++;

    }
    cout << res << '\n';
}
