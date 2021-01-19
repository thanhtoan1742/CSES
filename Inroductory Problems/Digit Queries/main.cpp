#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll solve(ll x) {
    if (x < 10)
        return x;

    ll l = 1;
    ll n = 9;
    while (1) {
        if (x <= n*l)
            break;

        x -= n*l;
        n *= 10;
        ++l;
    }

    ll a = n/9 + (x - 1)/l;
    ll b = x%l;
    if (b == 0)
        b = l;
    while (b < l) {
        a /= 10;
        ++b;
    }
    return a%10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        cout << solve(x) << '\n';
    }
}
