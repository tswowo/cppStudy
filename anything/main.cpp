#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> links(20);
int target;

void dfs(int u, int target, vector<bool> &visited, vector<int> &path, vector<vector<int>> &paths)
{
    if (u == target)
    {
        paths.push_back(path);
        return;
    }
    for (int v : links[u])
    {
        if (!visited[v])
        {
            visited[v] = true;
            path.push_back(v);
            dfs(v, target, visited, path, paths);
            path.pop_back();
            visited[v] = false;
        }
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int ans = INT_MAX;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    int start1, start2;
    cin >> start1 >> start2;
    cin >> target;
    vector<vector<int>> paths1, paths2;
    vector<bool> visited1(n + 1, false), visited2(n + 1, false);
    vector<int> path1, path2;

    visited1[start1] = true;
    path1.push_back(start1);
    dfs(start1, target, visited1, path1, paths1);

    visited2[start2] = true;
    path2.push_back(start2);
    dfs(start2, target, visited2, path2, paths2);

    if (paths1.empty() || paths2.empty())
    {
        cout << "Impossible" << endl;
        return 0;
    }

    for (auto &p1 : paths1)
    {
        unordered_set<int> set1(p1.begin(), p1.end());
        for (auto &p2 : paths2)
        {
            unordered_set<int> set2(p2.begin(), p2.end());
            bool flag = true;
            for (int town : set2)
            {
                if (town != target && set1.count(town))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                int total = set1.size() + set2.size() - 1;
                ans = min(ans, total);
            }
        }
    }

    if (ans != INT_MAX)
        cout << ans;
    else
        cout << "Impossible";
    return 0;
}

