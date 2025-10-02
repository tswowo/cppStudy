#include<iostream>
using namespace std;

typedef struct
{
	int top[2],bot[2];
	int*stk;
	int m;
}DblStack;

DblStack* init(int size)
{
	DblStack* newStack=new DblStack;
	newStack->top[0]=-1;
	newStack->top[1]=size;
	newStack->bot[0]=-1;
	newStack->bot[1]=size;
	newStack->stk=new int[size];
	newStack->m=size;
	return newStack;
}

bool empty(DblStack* stk)
{
	return stk->top[0]==stk->bot[0]&&stk->top[1]==stk->bot[1];
}

bool full(DblStack* stk)
{
	return stk->top[1]-stk->top[0]==1;
}

int top(DblStack* stk,int index)
{
	if(stk->top[index]==stk->bot[index])
	{
		cerr<<"Õ»¿Õ";
		return int();
	}
	return stk->stk[stk->top[index]];
}

void push(DblStack* stk,int index,int val)
{
	if(full(stk))
	{
		cerr<<"Õ»Âú";
		return;
	}
	if(index==0)
		stk->stk[++stk->top[0]]=val;
	else
		stk->stk[--stk->top[1]]=val;
}

void pop(DblStack* stk,int index)
{
	if(index==0)
	{
		if(stk->top[0]==stk->bot[0])
		{
			cerr<<"Õ»¿Õ";
			return;
		}
		stk->top[0]--;
	}
	else
	{
		if(stk->top[1]==stk->bot[1])
		{
			cerr<<"Õ»¿Õ";
			return;
		}
		stk->top[1]++;
	}
}

int main()
{
    DblStack* stack = init(5);
    
    push(stack, 0, 10);
    push(stack, 0, 20);
    cout << top(stack, 0) << endl;
    
    push(stack, 1, 100);
    push(stack, 1, 200);
    cout << top(stack, 1) << endl;
    
    pop(stack, 0);
    cout << top(stack, 0) << endl;
    
    pop(stack, 1);
    cout << top(stack, 1) << endl;
    
    pop(stack, 0);
    pop(stack, 0);
    
    return 0;
}
