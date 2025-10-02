#include<bits/stdc++.h>
using namespace std;

bool solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    if(k>s.size()/2)
        return true;
    int cnt=0;
    for(auto&x:s)
        if(x=='1')
            cnt++;
    if(cnt<=k||k>s.size()/2)
        return true;
    return false;
}

int main()
{
    int t;cin>>t;
    while(t--){
        cout<<(solve()?"Alice\n":"Bob\n");
    }
    return 0;
}