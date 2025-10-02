#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char str[n+1];
	char stk[n+1];
	cin>>str;
	auto isHuiwen=[](char*str,int n)->bool{
		for(int i=0;i<n/2;i++)
		{
			if(str[i]!=str[n-i-1])
				return false;
		}
		return true;
	};
	if(isHuiwen(str,n))
		cout<<"Is";
	else
		cout<<"No";
	return 0;
}
