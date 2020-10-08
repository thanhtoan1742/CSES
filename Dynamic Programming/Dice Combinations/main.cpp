#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e6 + 100;
const int base = 1e9 + 7;

int n;
int f[maxN];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j < 7; ++j)
            if (i - j >= 0) f[i] = (f[i] + f[i - j])%base;

    cout << f[n];
}
