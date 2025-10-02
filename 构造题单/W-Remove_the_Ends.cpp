#include<bits/stdc++.h>
using namespace std;

long long solve(){
    int n;cin>>n;
    vector<long long>a(n),pre(n),suf(n);
    for(auto&x:a)cin>>x;
    for(int i=0;i<n;i++){
        if(i>0)
            pre[i]+=pre[i-1];
        if(a[i]>0)
            pre[i]+=a[i];
    }
    for(int i=n-1;i>=0;i--){
        if(i<n-1)
            suf[i]+=suf[i+1];
        if(a[i]<0)
            suf[i]+=-a[i];
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,pre[i]+suf[i]);
    }
    return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
    return 0;
}