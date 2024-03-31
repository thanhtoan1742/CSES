#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;
const int maxLN = 20;

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

#define log(a, n) {cerr << #a << "\n"; for (int i = 0; i < (n); ++i) cerr << (a)[i] << " "; cerr << "\n";}

int n, q;
int out_from[maxN];
vector<int> into[maxN];

bool visited[maxN];
bool processed[maxN];
bool in_loop[maxN];
int loop_root[maxN];
int dflr[maxN];

int acs[maxN][maxLN];
int root[maxN];
int dfr[maxN];

void setup_in_loop() {
    memset(visited, 0, n);
    memset(processed, 0, n);
    for (int i = 0; i < n; ++i) {
        if (processed[i])
            continue;

        int j = i;
        while (!visited[j] && !processed[j]) {
            visited[j] = true;
            j = out_from[j];
        }

        if (!processed[j]) {
            in_loop[j] = true;
            dflr[j] = 0;
            loop_root[j] = j;

            int p = j;
            int k = out_from[j];
            while (k != j) {
                in_loop[k] = true;
                dflr[k] = dflr[p] + 1;
                loop_root[k] = loop_root[p];
                p = k;
                k = out_from[k];
            }
            dflr[j] = dflr[p] + 1;
        }

        j = i;
        while (!processed[j]) {
            processed[j] = true;
            j = out_from[j];
        }

    }
}


void setup_acs_rec(int u) {
    for (int i = 1; (1 << i) < n; ++i) {
        int a = acs[u][i - 1];
        if (a == -1)
            break;

        int aa = acs[a][i - 1];
        if (aa == -1)
            continue;

        acs[u][i] = aa;
    }

    for (int v: into[u])
        if (!in_loop[v]) {
            root[v] = root[u];
            dfr[v] = dfr[u] + 1;
            acs[v][0] = u;
            setup_acs_rec(v);
        }
}


void setup_acs() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; (1 << j) < n; ++j)
            acs[i][j] = -1;
    }

    for (int i = 0; i < n; ++i)
        if (in_loop[i]) {
            root[i] = i;
            dfr[i] = 0;
            setup_acs_rec(i);
        }
}


int is_acs(int u, int a) {
    if (dfr[u] < dfr[a])
        return false;

    for (int i = maxLN - 1; i >= 0; --i) {
        if (acs[u][i] == -1)
            continue;

        if (dfr[u] - dfr[a] < (1 << i))
            continue;

        u = acs[u][i];
    }
    return u == a;
}


int cal_loop(int u, int v) {
    int d = dflr[v] - dflr[u];
    if (d < 0) {
        d += dflr[loop_root[u]];
    }
    return d;
}


int cal(int u, int v) {
    int ru = root[u];
    int rv = root[v];
    int lru = loop_root[ru];
    int lrv = loop_root[rv];

    if (lru != lrv)
        return -1;

    if (in_loop[u] && in_loop[v]) {
        return cal_loop(u, v);
    }

    if (in_loop[u] && !in_loop[v])
        return -1;

    if (!in_loop[u] && in_loop[v]) {
        return cal_loop(ru, v) + dfr[u];
    }

    if (!is_acs(u, v))
        return -1;
    return dfr[u] - dfr[v];
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> out_from[i];
        out_from[i]--;
        into[out_from[i]].push_back(i);
    }

    setup_in_loop();
    setup_acs();

    /*
    log(in_loop, n);
    log(loop_root, n);
    log(dflr, n);
    log(root, n);
    log(dflr, n);
    for (int i = 0; i < n; ++i) {
        cerr << i << ": ";
        for (int j = 0; (1 << j) < n; ++j)
            cerr << acs[i][j] << " ";
        cerr << "\n";
    }
    */


    while (q--) {
        int u, v; cin >> u >> v; --u; --v;
        cout << cal(u, v) << "\n";
    }
}
