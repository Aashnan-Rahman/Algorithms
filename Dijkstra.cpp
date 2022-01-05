// Dijkstra

#include<bits/stdc++.h>
using namespace std;
#define iPair pair<int,int>
#define INF 1e8


int V,E,src,dst;
int cost[1005]={};
int stat[1005]={};
int path[1005]={};
vector<iPair> adj[1005];

int reset(int V)
{
	for(int i=0;i<=V;i++)
	{
		cost[i] = INF;
		path[i] = -1;
		stat[i] = 0;
		adj[i].clear();
	}
}

void spath(int v) {
	if (v == -1) {
		return ;
	} else {
		int x = path[v];
		spath(x);
		if (x != -1) printf("%d ", x);
	}
} 

void Dijkstra(int src)
{
	//reset(V);
	priority_queue< iPair, vector<iPair> , greater<iPair> >pq;
	cost[src] = 0;
	pq.push({0,src});

	while(!pq.empty())
	{
		int u = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(stat[v])
			continue;

		stat[v] = 1;

		for(int i = 0 ; i< adj[v].size() ; i++)
		{
			int u1 = adj[v][i].second;
			int v1 = adj[v][i].first;


			if(cost[v1] > cost[v] + u1)
			{
				cost[v1] = cost[v] + u1;
				pq.push({cost[v1],v1});
				path[v1] = v;
			}
		}
	}

	//for(int a=1;a<=V;a++) cout<<cost[a]<<" ";
	//cout<<endl;
	spath(dst);
	
}

int input()
{
	int tt,x,y,w;
	cin>>tt;
	while(tt--)
	{
		cin>>V>>E>>src>>dst;
		reset(V);
		for(int q=1;q<=E;q++)
		{
			cin>>x>>y>>w;

			adj[x].push_back({y,w});
		}

		Dijkstra(src);
	}
}

int main()
{
	input();
	//cout<<"Hello World"<<endl;
}