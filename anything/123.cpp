#include<bits/stdc++.h>
using namespace std;

int getLen(int x){
	int ans=0;
	while(x>0)
	{
		x/=10;ans++;
	}
	return ans;
}

int p(int x){
	int ans=1;
	int len=getLen(x);
	for(int i=0;i<len;i++)
		ans=(ans*10)%11;
	return ans;
}

void solve(){
    int n;cin>>n;
    long long ans=0;
    vector<int>a(n);
    for(auto&x:a)cin>>x;
    unordered_map<int,int>cnt;
    for(auto&x:a)cnt[x%11]++;
    for(auto&x:a){
    	int need=-(x%11)*p(x)%11;
    	need=(need+11)%11;
    	ans+=cnt[need];
    	if(need==(x%11))
    		ans--;
	}
    cout<<ans;
}

int main(){
    solve();
    return 0;
}
