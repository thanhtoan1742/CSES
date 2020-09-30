#include <bits/stdc++.h>

#define read(a) cin >> a
#define print(a) cout << (a) << '\n'
#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e4 + 100;

int n;
long long f[maxN];

void dp() {
    f[1] = 0;
    f[2] = 6;
    f[3] = 28;
    f[4] = 96;
    f[5] = 252;
    f[6] = 550;
    for (long long i = 7; i <= n; ++i) {
        f[i] = f[i - 1] +
            (2*i - 1)*sqr(i - 1) - 4*(2*i - 10) - 2*5 - 3*4 + 
            (2*i - 1)*(2*i - 2)/2 - 2;
    }

    // altenative:
    // f[n] = C(n*n, 2) - 4*(n - 1)*(n - 2)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read(n);
    dp();
    for (int i = 1; i <= n; ++i)
        print(f[i]);
}