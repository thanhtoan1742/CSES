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
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxN = 5000 + 10;
const ll MOD = 1e9 + 7;
const ll base = 263;

set<ll> se[maxN];
int f[maxN];

ll hashed(const string& a) {
    ll h = 0;
    for (int i = 0; i < a.size(); ++i)
        h = (h*base + a[i])%MOD;
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    string s;
    cin >> s;

    int n;
    cin >> n;
    while (n--) {
        string a;
        cin >> a;
        if (a.size() > s.size())
            continue;
        se[a.size()].insert(hashed(a));
    }

    n = s.size();
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        ll h = 0;
        for (int j = i; j < n; ++j) {
            h = (h*base + s[j])%MOD;
            if (se[j - i + 1].count(h))
                f[j + 1] = (f[j + 1] + f[i])%MOD;
        }
    }
    cout << f[n] << "\n"; 
}