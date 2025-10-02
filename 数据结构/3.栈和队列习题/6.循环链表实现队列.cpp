#include<iostream>
using namespace std;

struct Listnode{
	int val;
	Listnode*next;
};

typedef Listnode node;
typedef Listnode* nodeptr;

nodeptr create()
{
	nodeptr tail=new node;
	tail->val=-1;
	tail->next=tail;
	return tail;
}

int front(nodeptr tail)
{
	if(tail->next!=tail)
		return tail->next->val;
	return -1;
}

void push(nodeptr tail,int val)
{
	nodeptr newNode=new node;
	newNode->next=tail->next;
	newNode->val=val;
	tail->next=newNode;
}

void pop(nodeptr tail)
{
	if(tail->next!=tail)
	{
		nodeptr front=tail->next;
		tail->next=front->next;
		delete front;
	}
}

int main()
{
    nodeptr queue = create();
    cout<<front(queue)<<'\n';
    push(queue,1);
    cout<<front(queue)<<'\n';
    pop(queue);
    cout<<front(queue)<<'\n';
    
    return 0;
}
