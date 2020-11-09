#include <bits/stdc++.h>

using namespace std;
const int maxN = 15;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))

int n;
bool used[1 << maxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    int u = 0;
    used[u] = 1;
    int i = 1;
    vector<bool> res(n + (1 << n) - 1, 0);

    while (i < 1 << n) {
        u = u & ((1 << (n - 1)) - 1);
        // cout << u << ' ';
        u = (u << 1) | 1;
        if (used[u]) 
            --u;
        // cout << u << '\n';
        res[n + i - 1] = u&1;
        used[u] = true; 
        ++i;
    }

    for (auto e: res)
        cout << e;
}