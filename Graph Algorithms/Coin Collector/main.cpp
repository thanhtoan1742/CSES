#include <bits/stdc++.h>

using namespace std;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))

struct UW {
    int u;
    long long w;

    UW(int _u, int _w)
    : u(_u), w(_w) {}

    bool operator<(const UW& other) const & {
        return w < other.w;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
}