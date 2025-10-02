#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string in;
    int left = 1, right = 1000000;
    int ans = left;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        cout << mid;
        cout.flush();
        cin >> in;
        if (in == ">=")
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << "! " << ans << endl;
}

int main()
{
    solve();
    return 0;
}