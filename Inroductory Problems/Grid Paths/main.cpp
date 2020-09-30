#include <bits/stdc++.h>
 
#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))
 
using namespace std;
const char d[4] = {'D', 'R', 'U', 'L'};
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
string p;
 
bool visiting[10][10];
 
int res;
 
bool valid(int u, int v) {
    if (u < 0 || v < 0)
        return false;
    if (u > 6 || v > 6)
        return false;
 
    return !visiting[u][v];
}
 
bool wall_cut(int x, int y, int i) {
    int l = (i + 3)%4;
    int r = (i + 1)%4;
    if (valid(x + dx[i], y + dy[i]))
        return false;
    if (!valid(x + dx[l], y + dy[l]))
        return false;
    return valid(x + dx[r], y + dy[r]);
}
 
void dfs(int x, int y, int i = 0) {
    if (x == 6 && y == 0) {
        res += (i == 48);
        return;
    }
 
    visiting[x][y] = true;
 
    for (int j = 0; j < 4; ++j) 
        if (p[i] == '?' || p[i] == d[j]) {
            int u = x + dx[j];
            int v = y + dy[j];
            if (!valid(u, v))
                continue;
            if (wall_cut(u, v, j)) 
                continue;
            dfs(u, v, i + 1);
        }

    // if (p[i] == '?' || p[i] == 'D')
    //     if (valid(x + 1, y) && !(!valid(x + 2, y) && valid(x + 1, y + 1) && valid(x + 1, y - 1))) 
    //         dfs(x + 1, y, i + 1);

    // if (p[i] == '?' || p[i] == 'U')
    //     if (valid(x - 1, y) && !(!valid(x - 2, y) && valid(x - 1, y + 1) && valid(x - 1, y - 1))) 
    //         dfs(x - 1, y, i + 1);

    // if (p[i] == '?' || p[i] == 'R')
    //     if (valid(x, y + 1) && !(!valid(x, y + 2) && valid(x + 1, y + 1) && valid(x - 1, y + 1))) 
    //         dfs(x, y + 1, i + 1);
        
    // if (p[i] == '?' || p[i] == 'L')
    //     if (valid(x, y - 1) && !(!valid(x, y - 2) && valid(x + 1, y - 1) && valid(x - 1, y - 1))) 
    //         dfs(x + 1, y, i + 1);

    visiting[x][y] = false;
}
 
int main(int argc, char* argv[]) {
    freopen(argv[1], "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> p;
    for (int i = 0; i < 7; ++i)
    for (int j = 0; j < 7; ++j)
        visiting[i][j] = false;
    dfs(0, 0);
    cout << res;
}