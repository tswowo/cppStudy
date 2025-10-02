#include<bits/stdc++.h>
using namespace std;

int n,m;
const int nMax=100010;

vector<int>p(nMax);
void init()
{
    for(int i=0;i<=n;i++)
        p[i]=i;
}

int find(int pos)
{
    if(p[pos]!=pos)
        p[pos]=find(p[pos]);
    return p[pos];
}

void merge(int x,int y)
{
    int rootA=find(x);
    int rootB=find(y);
    if(rootA<rootB)
    {
        p[rootB]=rootA;
    }
    else if(rootA>rootB)
    {
        p[rootA]=rootB;
    }
}

int main()
{
    cin>>n>>m;
    vector<tuple<int,int,int>>links(m);
    for(auto&[w,u,v]:links)
        cin>>u>>v>>w;
    sort(links.begin(),links.end());
    long long weight=0;
    init();
    for(auto&[w,u,v]:links)
    {
        if(find(v)!=find(u))
        {
            merge(v,u);
            weight+=w;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(find(i)!=find(1))
        {
            cout<<"impossible\n";
            return 0;
        }
    }
    cout<<weight;
    return 0;
}
