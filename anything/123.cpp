#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    int blockIdx = 0;
    unordered_map<int, set<pair<int, int>>> mp;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> belong(n, vector<int>(n));
    int startIdx = -1, endIdx = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        while (cnt < n)
        {
            int count;
            char c;
            cin >> count >> c;
            if (c == 'S')
                startIdx = blockIdx;
            if (c == 'D')
                endIdx = blockIdx;
            for (int tmpi = 0; tmpi < count; tmpi++, cnt++)
            {
                grid[i][cnt] = c;
                belong[i][cnt] = blockIdx;
                mp[blockIdx].insert({i, cnt});
            }
            blockIdx++;
        }
    }
    queue<int> q;
    unordered_map<int, int> dist;
    q.push(startIdx);
    dist[startIdx] = 0;
    while (!q.empty())
    {
        int curIdx = q.front();
        q.pop();
        if (curIdx == endIdx)
        {
            break;
        }
        for (auto &[curi, curj] : mp[curIdx])
        {
            for (int k = 0; k < 4; k++)
            {
                int nexti = curi + dx[k];
                int nextj = curj + dy[k];
                if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n)
                {
                    int nextIdx = belong[nexti][nextj];
                    if (grid[nexti][nextj] == 'R')
                        continue;
                    if (dist.find(nextIdx) == dist.end())
                    {
                        int add = (grid[nexti][nextj] == 'G') ? 1 : 0;
                        dist[nextIdx] = dist[curIdx] + add;
                        q.push(nextIdx);
                    }
                }
            }
        }
    }
    cout << dist[endIdx];
    return 0;
}
