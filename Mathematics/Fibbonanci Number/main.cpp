#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
const ll M = 1e9 + 7;

using namespace std;
using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

array<array<ll, 2>, 2> mul(array<array<ll, 2>, 2> a, array<array<ll, 2>, 2> b) {
    array<array<ll, 2>, 2> c;
    c[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % M;
    c[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % M;
    c[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % M;
    c[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % M;
    return c;
}

array<array<ll, 2>, 2> Pow(array<array<ll, 2>, 2> m, ll n) {
    if (n == 1) 
        return m;

    auto t = Pow(m, n/2);
    t = mul(t, t);
    if (n&1)
        t = mul(t, m);

    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    if (n == 0 ||  n == 1) {
        cout << n << '\n';
        return 0;
    }

    array<array<ll, 2>, 2> m;
    m[0][0] = 1; m[0][1] = 1;
    m[1][0] = 1; m[1][1] = 0;
    
    m = Pow(m, n - 1);
    ll res = m[0][0];

    cout << res << '\n';
}
