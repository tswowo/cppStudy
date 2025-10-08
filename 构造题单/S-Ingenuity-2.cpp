#include <bits/stdc++.h>
using namespace std;

char inv(char c)
{
    if (c == 'N')
        return 'S';
    if (c == 'S')
        return 'N';
    if (c == 'E')
        return 'W';
    if (c == 'W')
        return 'E';
    return ' ';
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string r = "R";
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
            y += 1;
        if (s[i] == 'S')
            y -= 1;
        if (s[i] == 'E')
            x += 1;
        if (s[i] == 'W')
            x -= 1;
    }
    string ans;
    for (int i = 0; i < n; i++)
        ans += r;
    if (x % 2 || y % 2)
    {
        puts("NO");
        return;
    }
    if (x == y && y == 0)
    {
        if (n == 2)
        {
            puts("NO");
            return;
        }
        ans[0] = ans[s.find(inv(s[0]))] = 'H';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N' && y > 0)
                ans[i] = 'H', y -= 2;
            if (s[i] == 'S' && y < 0)
                ans[i] = 'H', y += 2;
            if (s[i] == 'E' && x > 0)
                ans[i] = 'H', x -= 2;
            if (s[i] == 'W' && x < 0)
                ans[i] = 'H', x += 2;
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
