/// AASHNAN RAHMAN
/// ID 190041204
/// CSE 4404 Lab 6 Mice and Maze

#include<bits/stdc++.h>
//#include <ctime>
#define RAPIDO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define arr(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
#define iPair pair<int,int>
#define INF 1e7+7
#define endl "\n"

using namespace std;

int G[105][105];
int V,S,T,E,cnt=0;

void reset(int V)
{
    for(int i=0;i<=V;i++)
    {
        for(int j=0;j<=V;j++)
            {
                if(i==j)
                    G[i][j]=0;
                else G[i][j]=INF;
            }

    }
}

void input()
{
    //memset(G,INF,sizeof G);    
    int x,y,w;

   cin>>V>>S>>T>>E;

    reset(V);


   for(int q=0;q<E;q++)
   {
       cin>>x>>y>>w;

       G[x][y]=w;
   }
}

void prnt(int V)
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }

}

int floyd_warshall()
{
    //reset(V);
    cnt=0;

    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                //cout<<G[i][j] <<" "<< G[i][k] + G[k][j]<<endl
                G[i][j] = min(G[i][j] , G[i][k] + G[k][j] ) ;
            }
        }
    }

    //cout<<endl;
    //prnt(V);

    for(int k=1;k<=V;k++)
    {
        if(G[k][S]<=T) cnt++;// k==S
    }

    cout<<cnt<<endl;
}

int main()
{
    //RAPIDO;
    int tc;
    cin>>tc;

    while(tc--)
    {
        //cin.ignore();
        //reset();
        input();
        //prnt(V);
        floyd_warshall();

        if(tc) cout<<endl;
    }
}

