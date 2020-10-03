#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n, k;
int a[maxN];

long long ntop = 0, nbot = 0;
map<int, int> top;
map<int, int, greater<int>> bot;
pair<int, int> x = {-1, -1};

long long s = 0;

void move_x_up() {
    // cout << "move x up: \n";
    auto new_x = *top.begin();

    s -= (new_x.first - x.first)*ntop;
    s += (new_x.first - x.first)*(nbot + x.second);

    top.erase(top.begin());
    ntop -= new_x.second;
    bot[x.first] = x.second;
    nbot += x.second;
    x = new_x;
}

void move_x_down() {
    // cout << "move x down: \n";
    auto new_x = *bot.begin();

    s -= (x.first - new_x.first)*nbot;
    s += (x.first - new_x.first)*(ntop + x.second);

    bot.erase(bot.begin());
    nbot -= new_x.second;
    top[x.first] = x.second;
    ntop += x.second;
    x = new_x;
}

void add(int a) {
    if (x.second == -1) {
        x = {a, 1};
        return;
    }
    if (x.first == a) {
        x.second++;
        return;
    }

    if (a > x.first) {
        auto it = top.find(a);
        if (it == top.end()) top[a] = 1;
        else it->second++;
        ntop++;

        s += a - x.first;
    }
    else {
        auto it = bot.find(a);
        if (it == bot.end()) bot[a] = 1;
        else it->second++;
        nbot++;
        
        s += x.first - a;
    }
}

void remove(int a) {
    // cout << "remove: " << a << '\n';
    if (x.first == a) {
        if (x.second > 1) {
            x.second--;
            return;
        }

        if (!bot.empty()) move_x_down();
        else move_x_up();
        remove(a);
        return;
    }

    if (a > x.first) {
        s -= a - x.first;
        top[a]--;
        if (top[a] == 0) top.erase(a);
        ntop--;
    }
    else {
        s -= x.first - a;
        bot[a]--;
        if (bot[a] == 0) bot.erase(a);
        nbot--;
    }
}

void optimize() {
    // cout << "optimize:\n\ttop.size: " << ntop << ' ' << "\n\tbot.size: " << nbot << '\n';
    while (!top.empty())
    {
        auto new_x = *top.begin();
        long long ds = (new_x.first - x.first)*(nbot + x.second) - (new_x.first - x.first)*ntop;
        if (ds > 0) break;
        move_x_up();
    }

    while (!bot.empty())
    {
        auto new_x = *bot.begin();
        long long ds = (x.first - new_x.first)*(ntop + x.second) - (x.first - new_x.first)*nbot;
        if (ds > 0) break;
        move_x_down();
    }
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)  {
        // cout << "index: " << i << '\n';
        // cout << "before add:\n\ttop.size: " << ntop << ' ' << "\n\tbot.size: " << nbot << '\n';
        add(a[i]);
        // cout << "after add:\n\ttop.size: " << ntop << ' ' << "\n\tbot.size: " << nbot << '\n';
        if (i - k >= 0) remove(a[i - k]);
        optimize();

        if (i >= k - 1) cout << s << ' ';
    }
}
