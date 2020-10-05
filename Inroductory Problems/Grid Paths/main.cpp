// barely got accepted, 0.99s on the largest test.
// this shit run ony 0.8s on my machine.
// this solution is ridiculous, i don't know what is going on anymore


#include <bits/stdc++.h>
 
#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))
 
using namespace std;
const char d[] = {'D', 'R', 'U', 'L'};
// have to increase the size to 8 so that i don't have to mod 4 later
const int dx[] = {1, 0, -1, 0, 1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1, 0, 1, 0, -1};
 
string p;
 
bool visiting[10][10];
int res;
 
inline bool valid(int u, int v) {
    return u > -1 && v > -1 && u < 7 && v < 7 && !visiting[u][v];
    // this is actualy faster than this:
    // if (u < 0 || v < 0) return false;
    // if (u > 6 || v > 6) return false;
    // return !visiting[u][v];
}
 
bool wall_cut(int x, int y, int i) {
    // don't have to mod 4 here
    int l = (i + 3);
    int r = (i + 1);

    return !valid(x + dx[i], y + dy[i]) && valid(x + dx[l], y + dy[l]) && valid(x + dx[r], y + dy[r]);
}
 
void dfs(int x, int y, int i) {
    if (x == 6 && y == 0) {
        res += (i == 48);
        return;
    }
    visiting[x][y] = true;
 
    for (int j = 0; j < 4; ++j) 
        if (p[i] == '?' || p[i] == d[j]) {
            int u = x + dx[j];
            int v = y + dy[j];
            if (!valid(u, v)) continue;
            if (wall_cut(u, v, j)) continue;
            dfs(u, v, i + 1);
        }

    visiting[x][y] = false;
}
 
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> p;
    for (int i = 0; i < 7; ++i)
    for (int j = 0; j < 7; ++j)
        visiting[i][j] = false;
    dfs(0, 0, 0);

    cout << res << '\n';
}