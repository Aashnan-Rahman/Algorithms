#include<bits/stdc++.h>
using namespace std;

#define INF 1e9;

int G[1005][1005]={};
int visited[1005]={};
int cost[1005]={};
int V,E,dst,M,x,y,w,T;

void reset(int V)
{
	for(int i=0; i<=V ; i++)
	{	
		for(int j=0; j<=V ; j++)
			if(i==j)
				G[i][j] = 0;
			else
				G[i][j] = INF;
	}
}

floyd_warshal(int dst)
{
	for(int k = 1 ; k<=V ; k++)
	{
		for(int i = 1 ; i<=V ; i++)
		{
			for(int j = 1 ; j<=V ; j++)
				G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
		}
	}

	int cnt = 0;
	for(int i=1;i<=V;i++)
	{
		if(G[i][dst]<=T) cnt++;
	}

	cout<<cnt<<endl;
}

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

			G[x][y] = w;
		}
		
		floyd_warshal(dst);

		if(tc)
			cout<<endl;
	}
}

int main()
{
	input();
}