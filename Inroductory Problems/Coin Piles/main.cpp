#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nTest;
    cin >> nTest;
    for (int testCase = 1; testCase <= nTest; ++testCase) {
        int a, b;
        cin >> a >> b;
        a = min(a, b) - abs(a - b);
        if (a < 0 || a % 3 != 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}