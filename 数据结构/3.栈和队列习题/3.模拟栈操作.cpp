#include<iostream>
using namespace std;

int main()
{
	int n;
	int size=114514;
	int stk[size];
	int pos=0;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		if(a==-1)
		{
			if(pos==0)
				cerr<<"Õ»¿Õ";
			else
				cout<<stk[--pos]<<'\n';
		}
		else
		{
			if(pos>=size)
				cerr<<"Õ»Âú";
			else
				stk[pos++]=a;
		}
	}
	return 0;
}
