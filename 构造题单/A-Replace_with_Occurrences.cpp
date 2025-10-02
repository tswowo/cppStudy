#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>b(n);
    unordered_map<int,int>f;
    for(auto&x:b){
        cin>>x;
        f[x]++;
    }
    for(auto&[x,cnt]:f){
        if(cnt%x!=0){
            cout<<"-1\n";
            return;
        }
    }
    int idx=1;
    unordered_map<int,int>cnt1;//记录当前这个出现次数x，消耗了夺少 a b if(b==a) b->0 idx++
    unordered_map<int,int>cnt2;//当前这个出现次数，所对应的数字应该是
    for(auto&x:b){
        cnt1[x]++;
        if(cnt1[x]==1){
            cnt2[x]=idx++;
        }
        cnt1[x]%=x;
        cout<<cnt2[x]<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}