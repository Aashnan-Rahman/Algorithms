#include<bits/stdc++.h>
using namespace std;
#define iPair pair<int,int>
#define INF 1e8

int G[1005][1005]={};
int src,V,E,dst;

void reset(int V)
{
	for(int i = 0 ; i<=V ; i++ )
	{
		for(int j = 0 ; j<=V ; j++ )
			{
				if(i==j)
					G[i][j] = 0;
				else
					G[i][j] = INF;
			}	
	}
}

void Floyd_Warshall(int src,int dst)
{
	for(int k = 1 ; k<=V ; k++)
	{
		for(int i = 1 ; i<=V ; i++ )
		{	
			for(int j = 1 ; j<=V ; j++ )
				G[i][j] = min(G[i][j],G[i][k]+G[k][j]);	
		}
	}

	for(int i = 1 ; i<=V ;i++)
		cout<<G[src][i]<<" ";
	
}


void input()
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

			G[x][y] = w;
		}

		Floyd_Warshall(src,dst);
	}
}

int main()
{
	input();
}