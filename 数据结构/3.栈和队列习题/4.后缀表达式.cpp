#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<int>num;
	string in;
	int n=-1;
	while(cin>>in&&in!="$")
	{
		if(in==" ")
			continue;
		else if('0'<=in[0]&&in[0]<='9')
			num.push(stoi(in));
		else
		{
			int second=num.top();
			num.pop();
			int first=num.top();
			num.pop();
			if(in=="+")
				num.push(first+second);
			else if(in=="-")
				num.push(first-second);
			else if(in=="*")
				num.push(first*second);
			else if(in=="/")
				num.push(first/second);
		}
	}
	cout<<num.top();
	return 0;
}
