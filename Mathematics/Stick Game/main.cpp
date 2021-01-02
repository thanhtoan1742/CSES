#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6 + 100;

int n, k;
vector<int> a;

bool w[maxN];

int main() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    w[0] = 0;
    for (int i = 1; i <= n; ++i) {
        w[i] = 0;
        for (auto e: a)
            if (i >= e && !w[i - e])
                w[i] = 1;

        cout << (w[i] ? 'W' : 'L');
    }

}
