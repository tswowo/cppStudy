#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(auto&x:a)cin>>x;
    int ans=1;
    for(int i=0;i<n-1;i++)
        if(a[i+1]%a[i]!=0)
            ans=lcm(ans,a[i]/gcd(a[i],a[i+1]));
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
        cout<<solve()<<'\n';
    return 0;
}