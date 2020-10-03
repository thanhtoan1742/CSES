#include <bits/stdc++.h>
 
#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))
 
using namespace std;
const int maxN = 2e5 + 100;
 
struct UI {
    int u, i;
 
    bool operator<(const UI& other) const & {
        return u < other.u;
    }
 
    bool operator>(const UI& other) const & {
        return u > other.u;
    }
 
    bool operator<=(const UI& other) const & {
        return u <= other.u;
    }
};
 
int n, k;
UI a[maxN];
 
bool in_l[maxN];
priority_queue<UI> l;
priority_queue<UI, vector<UI>, greater<UI>> r;
 
int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].u;
        a[i].i = i;
        in_l[i] = true;
 
        if (i < k) l.push(a[i]);
 
        if (i == k) {
            l.push(a[i]);
            for (int j = 0; j < k/2; ++j) {
                in_l[l.top().i] = false;
                r.push(l.top());
                l.pop();
            }
        }
 
        if (i > k) {
            while (!l.empty() && l.top().i <= i - k) l.pop();
            while (!r.empty() && r.top().i <= i - k) r.pop();
 
            if (a[i] > l.top()) {
                r.push(a[i]);
                in_l[i] = false;
 
                if (in_l[i - k]) {
                    l.push(r.top());
                    in_l[r.top().i] = true;
                    r.pop();
 
                    while (!r.empty() && r.top().i <= i - k) r.pop();
                }
            }
            else {
                l.push(a[i]);
                in_l[i] = true;
 
                if (!in_l[i - k]) {
                    r.push(l.top());
                    in_l[l.top().i] = false;
                    l.pop();
 
                    while (!l.empty() && l.top().i <= i - k) l.pop();
                }
            }
        }
        
        // cout << a[i].u  << ' ' 
        // << (l.empty()? -1: l.top().i) << ' ' 
        // << (r.empty()? -1: r.top().i) << '\n';
        if (i >= k) cout << l.top().u << ' ';
    }
    cout << '\n';
}