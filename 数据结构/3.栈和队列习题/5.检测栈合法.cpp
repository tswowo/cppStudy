#include<iostream>
using namespace std;

bool check(char*str,int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		char op=str[i];
		if(op=='I')
			cnt++;
		else
		{
			if(cnt==0)
				return false;
			else
				cnt--;
		}
	}
	return true;
}

int main()
{
	int n;cin>>n;
	char str[n+1];cin>>str;
	if(check(str,n))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
