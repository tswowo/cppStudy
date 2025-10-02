#include<iostream>
using namespace std;

const int nMax=10;
int q[nMax];
int tag=0;
int rear=0,front=0;

int get_front()
{
	if(tag==0)
		return -1;
	return q[(front+1)%nMax];
}

void push(int val)
{
	if(tag==1)
		return;
	if(tag==0)
		tag=2;
	q[front]=val;
	front=(front-1+nMax)%nMax;
	if(rear==front)
		tag=1;
}

void pop()
{
	if(tag==0)
		return;
	if(tag==1)
		tag=2;
	rear=(rear-1+nMax)%nMax;
	if(rear==front)
		tag=0;
}

int main()
{
	
}
