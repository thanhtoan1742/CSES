#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

multiset<int, greater<int>> s;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }

    while (m--) {
        int a;
        cin >> a;
        auto it = s.lower_bound(a);
        if (it == s.end())
            cout << "-1\n";
        else {
            cout << *it << '\n';
            s.erase(it);
        }
    }
}