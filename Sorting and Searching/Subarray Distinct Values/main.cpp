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
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k;
int a[maxN];

map<int, int> m;

long long res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int c = 0;
    int j = 0;
    res = 0;
    for (int i = 0; i < n; ++i) {
        while (1) {
            if (j == n)
                break;

            auto it = m.find(a[j]);
            if ((it == m.end() || it->second == 0) && c == k)
                break;

            if (it == m.end()) {
                m[a[j]] = 1;
                ++c;
            }
            else if (it->second == 0) {
                it->second = 1;
                ++c;
            }
            else 
                it->second++;

            ++j;
        }

        res += j - i;

        auto it = m.find(a[i]);
        it->second--;
        if (it->second == 0)
            --c;
    }

    cout << res << '\n';
}


