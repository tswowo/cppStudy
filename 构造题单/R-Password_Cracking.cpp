#include <bits/stdc++.h>
using namespace std;

int query(string s){
    cout<<"? "<<s<<endl;
    cout.flush();
    int in;cin>>in;
    return in;
}

void solve()
{
    int n;
    cin>>n;
    string ans;
    bool turn=true;
    while(ans.size()<n){
        if(turn){
            if(query(ans+"1")==1)
                ans=ans+"1";
            else if(query(ans+"0")==1)
                ans=ans+"0";
            else
                turn=false;
        }else{
            if(query("1"+ans)==1)
                ans="1"+ans;
            else
                ans="0"+ans;
        }
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
}

int main()
{
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}