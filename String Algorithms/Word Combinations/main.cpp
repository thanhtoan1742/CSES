#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)
 
using namespace std;
using namespace __gnu_pbds;
const int maxN = 5e3 + 100;
const int maxK = 1e5 + 100;
const ll MOD = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Hashed {
    int len;
    ll val;

    Hashed(int _len = 0, ll _val = 0)
    : len(_len), val(_val) {
    }

    inline bool operator==(const Hashed& other) const & {
        return len == other.len && val == other.val;
    }
};

ll Hashing[maxK];

int n;
string s;
ll hs[maxN];

int k;
Hashed a[maxK];

ll f[maxN];

Hashed Hash(const string& s, ll* h = Hashing) {
    Hashing[0] = 0;
    for (int i = 1; i <= s.size(); ++i) {
        ll a = s[i - 1] - 'a';
    }
        
    return Hashed();
}

Hashed getHash(ll* h, int l, int r) {
    return Hashed();
}

ll dp() {
    f[0] = 0;
    for (int i = 0; i < n; ++i) {
        f[i + 1] = 0;
        for (int j = 0; j < k; ++j)
            if (i + 1 >= a[i].len && a[i] == getHash(hs, i - a[i].len + 1, i)) {
                f[i + 1] += f[i - a[j].len + 1];
                if (f[i + 1] >= MOD)
                    f[i + 1] -= MOD;
            }
    }

    return f[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    Hash(s, hs);

    cin >> k;
    for (int i = 0; i < k; ++i) {
        string t;
        cin >> t;
        a[i] = Hash(t); 
    }

    ll res = dp();
    cout << res << '\n';
}
