#include<bits/stdc++.h>
using namespace std;

long long solve(){
    int n;cin>>n;
    long long maxNum=0,sum=0,cntJi=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        maxNum=max(maxNum,x);
        sum+=x;
        if(x%2==1)
            cntJi++;
    }
    return (cntJi==0||cntJi==n)?maxNum:sum-cntJi+1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cout<<solve()<<'\n';
    }
    return 0;
}