#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxX = 1e6 + 100;
const int maxN = 100 + 10;

int n, x;
int a[maxN];
int f[maxX];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    f[0] = 0;
    for (int i = 1; i <= x; ++i) {
        f[i] = x + 1;
        for (int j = 0; j < n; ++j)
            if (i - a[j] >= 0) f[i] = min(f[i], f[i - a[j]] + 1);
    }

    cout << (f[x] == x + 1? -1: f[x]);
}
