#include <bits/stdc++.h>
using namespace std;

int grid[502][502];

void init()
{
    memset(grid, -1, sizeof(grid));
    int x = 251, y = 251;
    grid[x][y] = 0;
    int num = 1;
    int dir = 0;
    int steps = 1;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (num < 250000)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < steps; j++)
            {
                x += dx[dir];
                y += dy[dir];
                grid[x][y] = num++;
            }
            dir = (dir + 1) % 4;
        }
        steps++;
    }
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    int max_num = n * n - 1;
    int min_x = 502, max_x = -1, min_y = 502, max_y = -1;

    for (int x = 0; x < 502; x++)
    {
        for (int y = 0; y < 502; y++)
        {
            if (grid[x][y] != -1 && grid[x][y] <= max_num)
            {
                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
        }
    }

    for (int i = min_x; i <= max_x; i++)
    {
        for (int j = min_y; j <= max_y; j++)
        {
            if (j > min_y)
                cout << " ";
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
}