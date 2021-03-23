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

const int maxN = 1e6 + 100;
const ll base = 263;
const ll MOD = 1e9 + 7;

int n;
string s;
ll ha[maxN], rha[maxN];
ll p[maxN];

int ri(int i) {
    return n - i - 1;
}

void make_hash(const string& s, ll ha[]) {
    ha[0] = 0;
    p[0] = 1;
    for (int i = 0; i < n; ++i) {
        ha[i + 1] = (ha[i]*base + s[i])%MOD;
        p[i + 1] = p[i]*base%MOD;
    }
}

ll get_hash(ll ha[], int l, int r) {
    if (r < l)
        swap(l, r);
    r += 1;
    return (ha[r] - ha[l]*p[r - l] + MOD*MOD)%MOD;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    n = s.size();
    make_hash(s, ha);
    reverse(s.begin(), s.end());
    make_hash(s, rha);
    reverse(s.begin(), s.end());

    int r1 = -1, r2 = 0, i1 = 0, i2 = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = min(i + 1, n - i - 1) + 1;
        while (l < r) {
            int m = (l + r)/2; 
            if (get_hash(ha, i - m + 1, i) == get_hash(rha, ri(i + m), ri(i + 1)))
                l = m + 1;
            else
                r = m;
        }
        if (r1 < r - 1) {
            r1 = r - 1;
            i1 = i;
        }

        l = 0, r = min(i, n - i - 1) + 1;
        while (l < r) {
            int m = (l + r)/2;
            if (get_hash(ha, i - m, i - 1) == get_hash(rha, ri(i + m), ri(i + 1)))
                l = m + 1;
            else
                r = m;
        }
        if (r2 < r - 1) {
            r2 = r - 1;
            i2 = i;
        }
    }

    if (2*r1 > 2*r2 + 1)
        cout << s.substr(i1 - r1 + 1, 2*r1) << "\n";
    else
        cout << s.substr(i2 - r2, 2*r2 + 1) << "\n";
}