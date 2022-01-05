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

void floyd_washall()
{
	for(int k = 1 ; k<=V ; k++)
	{
		for(int i = 1 ; i<=V ; i++)
		{
			for(int j = 1 ; j<=V ; j++)
				G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
		}
	}
}

void str_val(string a, string b)
{
	int a1,b1;

	for(int i=1;i<=V;i++)
	{
		if(a==str[i])
			a1 = i;
		if(b==str[i])
			b1 = i;
	}
	cout<<G[a1][b1]<<endl;
}

void input()
{
	int tc,cases;
	cin>>tc;
	while(tc--)
	{
		cin>>V;
		reset();

		for(int i = 1 ; i <= V ; i++)
		{
			cin>>str[i];
			cin>>E;

			for(int j = 1; j <=E ; j++ )
			{
				cin>>y>>w;

				G[i][y]= w;
			}

		}

		floyd_washall();
		
		cin>>cases;
		string a,b;

		while(cases--)
		{
			cin>>a>>b;
			floyd_washall();
			str_val(a,b);
		}
	}
}

int main()
{
	input();
	return 0;
}