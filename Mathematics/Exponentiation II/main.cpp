#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
 
const ll MOD = 1e9 + 7;
 
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
ll powM(ll a, ll b, ll M) {
    if (b == 0)
        return 1%M;
 
    ll t = powM(a, b/2, M);
    t = t*t % M;
    if (b&1)
        t = t*a % M;
 
    return t;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll t = powM(b, c, MOD - 1);
        cout << powM(a, t, MOD) << '\n';
    }
}