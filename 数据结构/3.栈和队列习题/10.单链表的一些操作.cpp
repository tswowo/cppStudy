#include<iostream>
using namespace std;

typedef struct Listnode{
	int val;
	struct Listnode* next;
}node,*nodeptr;

nodeptr create(int n)
{
	nodeptr head=new node;
	head->val=-1;
	head->next=nullptr;
	nodeptr tail=head;
	while(n--)
	{
		int val;
		cin>>val;
		tail->next=new node;
		tail=tail->next;
		tail->val=val;
		tail->next=nullptr;
	}
	return head;
}

void printList(nodeptr head)
{
	nodeptr p=head->next;
	while(p)
	{
		cout<<p->val<<' ';
		p=p->next;
	}
}

int get_max(nodeptr head)
{
	int ans=-1;
	nodeptr p=head->next;
	while(p)
	{
		ans=(ans>p->val)?ans:p->val;
		p=p->next;
	}
}

int get_count(nodeptr head)
{
	int count=0;
	nodeptr p=head->next;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}

int get_averger(nodeptr head)
{
	int sum=0;
	nodeptr p=head->next;
	while(p)
	{
		sum+=p->val;
		p=p->next;
	}
	return sum/get_count(head);
}

int main()
{
	nodeptr p=create(10);
	printList(p);
	cout<<'\n'<<get_max(p);
	cout<<'\n'<<get_count(p);
	cout<<'\n'<<get_averger(p);
	return 0;
}
