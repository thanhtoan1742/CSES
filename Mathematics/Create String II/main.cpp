#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int M = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int d[100];

ll fact(int n) {
    ll res = 1;
    for (ll i = 1; i <= n; ++i)
        res = res * i % M;

    return res;
}


ll Pow(ll a, ll n, ll M) {
    if (!n)
        return 1 % M;

    ll t = Pow(a, n/2, M);
    t = t*t % M;
    if (n&1)
        t = t*a % M;
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    for (char c: s)
        d[c - 'a']++;

    ll res = fact(s.size());
    for (int i = 0; i <= 'z' - 'a'; ++i)
        res = res * Pow(fact(d[i]), M - 2, M) % M;

    cout << res << '\n';
}
