#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e3 + 10;
const int maxX = 1e5 + 100;

int n, x;
int a[maxN], b[maxN];

int f[maxX];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int  i = 0; i < n; ++i)
        for (int j = x; j >= a[i]; --j)
            maximize(f[j], f[j - a[i]] + b[i]);

    int res = 0;
    for (int i = 0; i <= x; ++i)
        maximize(res, f[i]);
    
    cout << res << '\n';
}
