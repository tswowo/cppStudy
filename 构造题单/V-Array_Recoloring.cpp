#include<bits/stdc++.h>
using namespace std;

long long solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(auto&x:a)
        cin>>x;
    if(k==1){
        int max1=*max_element(a.begin(),a.end()-1);
        int max2=*max_element(a.begin()+1,a.end());
        return max(0LL+a.back()+max1,0LL+a.front()+max2);
    }else{
        sort(a.begin(),a.end(),greater<>());
        long long ans=0;
        for(int i=0;i<=k;i++)
            ans+=a[i];
        return ans;
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
    return 0;
}