#include<iostream>
using namespace std;

const int nMax=10;
int q[nMax];
int tag=0;
int front=0,rear=0;

int get_front()
{
	if(tag==0)
		return -1;
	return q[front];
}

void push(int val)
{
	if(tag==1)
		return;
	if(tag==0)
		tag=2;
	q[rear]=val;
	rear=(rear+1)%nMax;
	if(front==rear)
		tag=1;
}

void pop()
{
	if(tag==0)
		return;
	if(tag==1)
		tag=2;
	front=(front+1)%nMax;
	if(front==rear)
		tag=0;
}

int main()
{
	
}
