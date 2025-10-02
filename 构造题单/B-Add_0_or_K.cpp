#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    vector<long long>a(n);
    for(auto&x:a)
        cin>>x;
    for(int g=2;;g++){
        if(__gcd(g,k)!=1){
            continue;
        }
        for(auto&x:a){
            while(x%g!=0)
                x+=k;
            cout<<x<<' ';
        }
        cout<<'\n';
        return;
    }
}

int main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}