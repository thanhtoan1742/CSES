// https://www.youtube.com/watch?v=GlI17WaMrtw&t=456s
// discrete mathematic about catalan number.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
template<typename T>
using vec = vector<T>;
template<typename T, size_t N>
using ar = array<T, N>;

const ll MOD = 1e9 + 7;

int n;
string s;
int t, o;

ll prodM(int begin, int end) {
    ll res = 1;
    for (int i = begin; i <= end; ++i)
        res = res*i % MOD;
    return res;
} 

ll powM(ll a, ll b) {
    if (b == 0)
        return 1 % MOD;
 
    ll t = powM(a, b/2);
    t = t*t % MOD;
    if (b&1)
        t = t*a % MOD;
    return t;
}

ll divM(ll a, ll b) {
    return a * powM(b, MOD - 2) % MOD;
}

ll comb(int n, int k) {
    ll a = prodM(k + 1, n);
    ll b = prodM(2, n - k);
    return divM(a, b);
}

ll cal(int n, string const& s) {
    if (n&1)
        return 0;
    int t = n - s.size();
    int o = n/2 - count_if(s.begin(), s.end(), [](char c){return c == '(';});

    if (o == 0)
        return 1;

    return (comb(t, o) - comb(t, o - 1) + MOD) % MOD;
}

bool valid(string const& s) {
    int u = 0;
    for (int i = 0; i < s.size(); ++i) {
        u += s[i] == '(' ? 1 : -1;
        if (u < 0)
            return 0;
    }
    return 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;
    if (!valid(s)) {
        cout << "0\n";
        return 0;
    }

    cout << cal(n, s) << "\n";
}
