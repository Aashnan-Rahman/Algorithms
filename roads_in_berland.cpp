#include<bits/stdc++.h>
using namespace std;

int G[10005][10005]={};
string str[100005];
int V,E,x,y,w;

void reset()
{
	for(int i=0;i<=V;i++)
	{
		for(int j=0;j<=V;j++)	
		{
			if(i==j)
				G[i][j]==0;
			else
				G[i][j]=1e9;
		}
	}
}

void sum();

void floyd_washall(int a,int b,int w)
{
	for(int i = 1 ; i<=V ; i++)
	{
		for(int j = 1 ; j<=V ; j++)
			
			G[i][j] = min(G[i][j],min(w+G[i][a]+G[b][j],w+G[i][b]+G[a][j]));
	}
	//sum();
}

void sum()
{
	int sum=0;

	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			cout<<G[i][j]<<" ";
			/*if(i<j)*/
				sum+=G[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<sum/2<<" "<<endl;
}

void input()
{
	int tc,cases;
	
	cin>>V;

	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			cin>>G[i][j];
		}
	}

	cin>>E;

	for(int i=0;i<E;i++)
	{
		cin>>x>>y>>w;

		//if(G[x][y]>w)
		{
			//G[x][y]=w;
			floyd_washall(x,y,w);
		}
		sum();
	}
	
}

int main()
{
	input();
	return 0;
}