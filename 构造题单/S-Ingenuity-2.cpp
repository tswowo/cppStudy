#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n%2==1)
    {
        cout<<"NO\n";
        return;
    }
    int x = 0, y = 0;
    for (auto &c : s)
    {
        if (c == 'N' || c == 'S')
            x ^= 1;
        else if (c == 'E' || c == 'W')
            y ^= 1;
    }
    if (x != 0 || y != 0)
    {
        cout << "NO\n";
        return;
    }
    for (auto &c : s)
    {
        if (c == 'N')
        {
            if (x == 1)
                cout << 'H';
            else
                cout << 'R';
            x ^= 1;
        }
        else if (c == 'S')
        {
            if (x == 0)
                cout << 'H';
            else
                cout << 'R';
            x ^= 1;
        }
        else if (c == 'E')
        {
            if (y == 0)
                cout << 'R';
            else
                cout << 'H';
            y ^= 1;
        }
        else
        {
            if (y == 1)
                cout << 'R';
            else
                cout << 'H';
            y ^= 1;
        }
    }
    cout << '\n';
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}