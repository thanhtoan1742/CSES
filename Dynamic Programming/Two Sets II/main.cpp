#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 500 + 100;
const int base = 1e9 + 7;

struct NIA {
    int d[maxN*maxN*2];
    const int t = maxN*maxN;

    int& operator[](int i) {
        return d[i + t];
    }
};

int n;
NIA f[2];

int dp() {
    int m = n*n;

    int t = 0;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = -m + 1; j < m; ++j) f[!t][j] = 0;
        for (int j = -m + 1; j < m; ++j) 
            if (f[t][j]) {
                if (j + i < m) f[!t][j + i] = (f[!t][j + i] + f[t][j]) % base;
                if (j - i > -m) f[!t][j - i] = (f[!t][j - i] + f[t][j]) % base;
            }
        t = !t;
        // cout << i << ' ' << f[t][0] << '\n';
    }

    long long res = f[t][0];
    // (5e8 + 4) is modular inverse of 2 to (10^9 + 7)
    res = res * (long long)(5e8 + 4) % base;
    return res;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    cout << dp() << '\n';
}
