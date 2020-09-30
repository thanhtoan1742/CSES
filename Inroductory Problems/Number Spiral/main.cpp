#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nTest;
    cin >> nTest;
    while (nTest--) {
        int i, j;
        cin >> i >> j;
        long long c = max(i, j);
        long long res = (c - 1) * (c - 1);
        if (c & 1) 
            res += j + (j < c ? 0 : c - i);
        else 
            res += i + (i < c ? 0 : c - j);
        cout << res << '\n';
    }
}