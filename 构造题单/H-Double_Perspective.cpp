#include<bits/stdc++.h>
using namespace std;

struct node
{
    int l, r, i;
    bool operator < (const node& p) const
    {
        return l < p.l || l == p.l && r < p.r;
    }
};

void solve(){
    int n; cin >> n;
    vector <node> a(n);
    for (int i=0; i<n; ++i) cin >> a[i].l >> a[i].r, a[i].i = i;
    sort(a.begin(),a.end());
    vector <int> ans;
    int R = 0;
    for (int i=0; i<n; ++i)
    {
        if (a[i].r > R) R = a[i].r, ans.push_back(a[i].i);
    }
    cout << ans.size() << '\n';
    for (int x: ans) cout << x+1 << ' ';
    cout << '\n';
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}