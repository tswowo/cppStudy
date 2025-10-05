#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int die[1005][1005];
int n, m;

int dfs(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m)
        return 1;
    if (die[i][j] == 1 || die[i][j] == 2)
        return die[i][j];
    if (die[i][j] == -1)
        return 2;
    die[i][j] = -1;
    int res = 1;
    if (grid[i][j] == 'U') {
        res = dfs(i - 1, j);
    } else if (grid[i][j] == 'D') {
        res = dfs(i + 1, j);
    } else if (grid[i][j] == 'L') {
        res = dfs(i, j - 1);
    } else if (grid[i][j] == 'R') {
        res = dfs(i, j + 1);
    } else if (grid[i][j] == '?') {
        res = 1;
        for (int d = 0; d < 4; d++) {
            int ni = i + (d == 0 ? -1 : d == 1 ? 1 : 0);
            int nj = j + (d == 2 ? -1 : d == 3 ? 1 : 0);
            if (dfs(ni, nj) == 2) {
                res = 2;
                break;
            }
        }
    }
    
    die[i][j] = res;
    return res;
}

void solve() {
    memset(die, 0, sizeof(die));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++)
            grid[i][j] = s[j-1];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (die[i][j] == 0)
                dfs(i, j);
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (die[i][j] == 2)
                ans++;
    
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
