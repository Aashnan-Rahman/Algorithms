#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define iPair pair<int,int>

vector<iPair> adj[100];
int visited[100]={}, cost[100]={};
int V,E,x,y,w,dst,T;

void reset(int V) 
{
	for(int i=0;i<=V;i++)
	{
		cost[i]=INF;
		visited[i]=0;
		adj[i].clear();
	}
}

void dijkastra(int dst);

void input()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		cin>>V>>dst>>T>>E;

		reset(V);

		for(int j=0;j<E;j++)
		{
			cin>>x>>y>>w;

			adj[y].push_back({x,w});
		}
		
		dijkastra(dst);

		if(tc)
			cout<<endl;
	}
}

void dijkastra(int dst)
{
	priority_queue<iPair, vector <iPair> , greater<iPair> > pq;
	cost[dst] = 0;
	pq.push({0,dst});

	while(!pq.empty())
	{
		int v = pq.top().second;
		int u = pq.top().first;
		pq.pop();

		if(visited[v]!=0)
			continue;

		visited[v] = 1;

		for(int i=0;i<adj[v].size();i++)
		{
			int v1 = adj[v][i].first;
			int u1 = adj[v][i].second;
				
			if(cost[v1] > cost[v] + u1 )
			{
				cost[v1] = cost[v] + u1;
				pq.push({cost[v1],v1});
			}
		}

	}
	int cnt = 0;
	for(int i=1;i<=V; i++)
	{
		//cout<<cost[i]<<" ";
		if(cost[i]<=T)
			cnt++;
	}

	cout<<cnt<<endl;
}

int main()
{
	input();
}