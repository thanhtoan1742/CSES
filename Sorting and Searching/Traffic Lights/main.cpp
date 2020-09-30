#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

set<int> p;
multiset<int> s;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> x >> n;
    p.insert(0);
    p.insert(x);
    s.insert(x);


    while (n--) {
        int a; 
        cin >> a;

        auto it = p.upper_bound(a);
        s.erase(s.find(*it - *prev(it)));
        s.insert(a - *prev(it));
        s.insert(*it - a);
        p.insert(a);

        cout << *s.rbegin() << ' ';
    }
    cout << '\n';
}