#include<bits/stdc++.h>
using namespace std;

const int nMax=500010;
const int mMax=2000010;

vector<vector<int>>adj(nMax);
vector<int>dfn(nMax);//???
vector<int>low(nMax);//???????
vector<bool>is_cut(nMax,false);//???
stack<pair<int,int>>stk;//?????
vector<vector<pair<int,int>>>components;//????????
int timecount=0;//??????
int n,m;

void tarjan(int u,int parent)
{
    dfn[u]=low[u]=++timecount;
    int son=0;
    for(int v:adj[u])
    {
        if(v==parent)
            continue;
        if(!dfn[v])
        {
            stk.push({u,v});
            son++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if((parent==-1&&son>1)||(parent!=-1&&low[v]>=dfn[u]))
            {
                is_cut[u]=true;
                vector<pair<int,int>>comp;
                while(true)
                {
                    auto top=stk.top();
                    comp.push_back(top);
                    stk.pop();
                    if(top==make_pair(u,v))
                        break;
                }
                components.push_back(comp);
            }
        }
        else if(dfn[v]<dfn[u])
        {
            stk.push({u,v});
            low[u]=min(low[u],dfn[v]);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
        {
            tarjan(i,-1);
            vector<pair<int,int>>comp;
			if(!stk.empty())
            {
                while(!stk.empty())
                {
                    comp.push_back(stk.top());
                    stk.pop();
                }
            }
            else
            {
            	comp.push_back(make_pair(i,i));
			}
            components.push_back(comp);
        }
    }
    cout<<components.size()<<'\n';
    for(auto&x:components)
    {
    	set<int>f;
        for(auto&y:x)
        {
        	f.insert(y.first);
        	f.insert(y.second);
		}
		cout<<f.size();
		for(auto&it:f)
			cout<<' '<<it;
		cout<<'\n';
    }
    return 0;
}	
