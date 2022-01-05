#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define iPair pair<int,int>

int cost[500000]={},stat[5000000]={};
vector<iPair>adj[20000];
int N,M,S,T,x,y,w,tc,V;

void reset(int V)
{
	for(int i = 0 ; i <= V ; i++)
	{
		cost[i] = INF;
		adj[i].clear();
		stat[i] = 0;
	}
}

void dijkstra(int src, int dst)
{
	priority_queue< iPair , vector<iPair> , greater<iPair> > pq;
	cost[src] = 0;
	pq.push({0,src});

	while(!pq.empty())
	{
		int v = pq.top().second;
		int u = pq.top().first;
		pq.pop();

		if(stat[v])
			continue;

		stat[v] = 1;

		if(v==dst)
			break;

		for(int i=0;i<adj[v].size();i++)
		{
			int v1 = adj[v][i].first;
			int u1 = adj[v][i].second;

			if(cost[v1] > cost[v] + u1)
			{
				cost[v1] = cost[v] + u1;
				pq.push({cost[v1],v1});	
			}
		}

	}	

	cout<<cost[dst]<<endl;
}


void input()
{
	cin>>tc;
	while(tc--)
	{
		cin>>N>>M>>S>>T;
		V = N;
		reset(V);		

		for(int c=0;c<M;c++)
		{
			cin>>x>>y>>w;
			adj[x].push_back({y,w});
			adj[y].push_back({x,w});
		}

		dijkstra(S,T);
	}
}


int main()
{
	input();
	return 0;
}