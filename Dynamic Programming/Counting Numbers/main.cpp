#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int f[19];

bool check(ll a) {
    int last = -1;
    while (a) {
        if (a%10 == last)
            return 0;
        last = a%10;
        a /= 10;
    }

    return 1;
}

void dp() {
    f[1] = 1;
    for (int i = 2; i < 19; ++i)
        f[i] = 9*f[i - 1];
}

ll cal_start(string a, int start = 10) {
    if (a.size() == 1)
        return a[0] - '0' + 1;

    int h = a[0] - '0';
    ll res = (h - (start < h))*f[a.size()];

    if (a[1] != a[0])
        res += cal_start(a.substr(1), h);
    
    cout << a << ' ' << res << '\n';
    return res;
}

ll cal(string a) {
    ll res = 0;
    for (int i = 0; i < a.size(); ++i)
        res += f[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp();

    ll a, b;
    cin >> a >> b;
    // cout << cal(to_string(b)) - cal(to_string(a)) + check(a) << '\n';
    // cout << cal(to_string(a)) << '\n';
    // cout << cal(to_string(b)) << '\n';
    // cout << cal("989") << '\n';
    // cout << cal("990") << '\n';
    // cout << cal("900") << '\n';
    cout << cal("90") << '\n';
    cout << cal("89") << '\n';
}
