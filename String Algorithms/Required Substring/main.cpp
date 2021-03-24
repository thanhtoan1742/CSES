#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
 
#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)
 
using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxN = 1000 + 10;
const ll MOD = 1e9 + 7;

int n, m;
string rs;

ll f[maxN], g[maxN], p[maxN];
vector<int> prisf;

void preprocess() {
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1]*26)%MOD;

    for (int l = 1; l < m; ++l) 
        if (rs.substr(0, l) == rs.substr(m - l, l))
            prisf.push_back(l);
}

ll dp() {
    f[m] = g[m] = 1;
    for (int i = m + 1; i <= n; ++i) {
        g[i] = (p[i - m] - f[i - m] + MOD)%MOD;
        for (auto l: prisf) {
            int j = i - m + l;
            g[i] = (g[i] - g[j] + MOD)%MOD;
        }
        f[i] = (f[i - 1]*26 + g[i]) % MOD;
        // cerr << g[i] << "\n";
    }

    return f[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> rs;
    m = rs.size();

    preprocess();
    ll res = dp();
    cout << res << "\n";
}