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
const int maxN = 2e6 + 100;
 
int n;
string s;

int kmp[maxN];

int KMP() {
    fill(kmp, kmp + n, -1);
    int k = 0;
    for (int j = 1; j < n; ++j) {
        int i = kmp[j - k - 1];
        while (i != -1 && s[j] != s[k + i + 1]) {
            if (s[j] < s[k + i + 1])
                k = j - i - 1;
            i = kmp[i];
        }
        if (i == -1 && s[j] != s[k]) {
            if (s[j] < s[k])
                k = j;
            kmp[j - k] = -1;
        }
        else 
            kmp[j - k] = i + 1;
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    s += s;
    n = s.size();
    int res = KMP();
    cout << s.substr(res, n/2) << "\n";
}