#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxA = 1e6 + 100;
const ll M = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int f[maxA];

ll powM(ll a, ll n, ll M) {
    if (!n)
        return 1 % M;

    ll t = powM(a, n/2, M);
    t = t*t % M;
    if (n&1)
        t = t*a % M;

    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    f[0] = 1;
    for (ll i = 1; i < maxA; ++i)
        f[i] = f[i - 1]*i % M;

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << f[a]*powM(f[b], M - 2, M)%M * powM(f[a - b], M-2, M) % M << '\n';
    }
}
