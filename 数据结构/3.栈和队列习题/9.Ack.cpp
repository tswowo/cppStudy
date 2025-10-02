#include<iostream>
using namespace std;

const int nMax=10000000;
int stkm[nMax],stkn[nMax];
int top=0;

int ack1(int m,int n)
{
	if(m==0)
		return n+1;
	if(n==0)
		return ack1(m-1,1);
	return ack1(m-1,(ack1(m,n-1)));
}

int ack2(int m,int n)
{
	int ans=0;
	stkm[top]=m;
	stkn[top]=n;
	top++;
	while(top!=0)
	{
		top--;
		int curm=stkm[top];
		int curn=stkn[top];
		if(curn==-1)
		{
			stkm[top]=curm;
			stkn[top]=ans;
			top++;
		}
		else if(curm==0)
		{
			ans=curn+1;
		}
		else if(curn==0)
		{
			stkm[top]=curm-1;
			stkn[top]=1;
			top++;
		}
		else
		{
			stkm[top]=curm-1;
			stkn[top]=-1;
			top++;
			stkm[top]=curm;
			stkn[top]=curn-1;
			top++;
		}
	}
	return ans;
}

int main()
{
	cout<<ack1(2,1)<<'\n';
	cout<<ack2(2,1)<<'\n';
	return 0;
}
