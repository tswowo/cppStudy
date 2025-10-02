#include<bits/stdc++.h>
using namespace std;

bool solve(){
	int w,h,a,b;
	int x1,y1,x2,y2;
	cin>>w>>h>>a>>b;
	cin>>x1>>y1>>x2>>y2;
	if(abs(x1-x2)%a==0&&(x1!=x2||abs(y1-y2)%b==0))
		return true;
	if(abs(y1-y2)%b==0&&(y1!=y2||abs(x1-x2)%a==0))
		return true;
	return false;
}

int main(){
//	FILE*fp=freopen("input.txt","r",stdin);
	int t;cin>>t;
	while(t--){
		cout<<(solve()?"Yes\n":"No\n");
	}
	return 0;
}