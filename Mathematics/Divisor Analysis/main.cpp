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

const int maxN = 1e5 + 100;
const ll MOD = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mulM(ll a, ll b, ll MOD = ::MOD) {
    a %= MOD;
    b %= MOD;
    return a*b % MOD;
}

ll powM(ll a, ll n) {
    if (n == 0)
        return 1;

    ll t = powM(a, n/2);
    t = mulM(t, t);
    if (n&1)
        t = mulM(t, a);
    return t;
}

ll divM(ll a, ll b) {
    return mulM(a, powM(b, MOD - 2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll no = 1, sum = 1, prd = 1;
    ll no2 = 1;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;

        sum = mulM(sum, divM(powM(a, b + 1) - 1 + MOD, a - 1));
        prd = mulM(powM(prd, b + 1), powM(powM(a, b*(b+1)/2), no2));
        no = mulM(no, b + 1);
        no2 = mulM(no2, b + 1, MOD - 1);
    }
    cout << no << ' ' << sum << ' ' << prd << '\n';
}
