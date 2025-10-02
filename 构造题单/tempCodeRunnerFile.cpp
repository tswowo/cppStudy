#include <bits/stdc++.h>
using namespace std;

void f()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void solve()
{
    long long n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1)
        cout << l << endl;
    else
    {
        if (n == 2)
            cout << -1 << endl;
        else
        {
            long long cnt = 0;
            while (cnt<=l)
                cnt<<=1;
            if (r >= cnt)
            {
                if (k <= n - 2)
                    cout << l << endl;
                else
                    cout << cnt << endl;
            }
            else
                cout << -1 << endl;
        }
    }
}

int main()
{
    f();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}