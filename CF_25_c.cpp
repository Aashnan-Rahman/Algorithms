/// AASHNAN RAHMAN
/// ID 190041204
/// CSE 4404 Lab 6 Roads to Berland

#include<bits/stdc++.h>
#include <ctime>
#define RAPIDO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define arr(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
#define iPair pair<int,int>
#define INF 1e9

using namespace std;

int G[305][305]={};
int V,S,T,E,cnt=0;

void reset()
{
    for(int i=0;i<305;i++)
    {
        for(int j=0;j<=305;j++)
            {
                if(i==j)
                    G[i][j]=0;
                else G[i][j]=INF;
            }
            
    }
}

void input()
{
    int x,y,w,B;

   cin>>V;

   for(int q=0;q<V;q++)
   {
        for(int r=0;r<V;r++)
        {
            cin>>G[x][y];
        }
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

void sum()
{
    int sum_=0;
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
            sum += G[i][j];
    }

    cout<<sum<<" ";
}

int floyd_warshall(int a, int b)
{
    //reset(V);
    cnt=0;

    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                //cout<<G[i][j] <<" "<< G[i][k] + G[k][j]<<endl;
                if(G[i][j] > G[i][k] + G[k][j])
                {

                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }

    //cout<<endl;
    //prnt(V);

    for(int k=1;k<=V;k++)
    {
        if(G[k][S]<=T) cnt++;
    }

    cout<<cnt<<endl;
}

int main()
{
    RAPIDO;

    int tc,aa;
    int x,y,w;
    cin>>tc;

    while(tc--)
    {
        reset();
        input();
        cin>>a;

        while(a--)
        {
            cin>>x>>y>>w;
        }

        if(tc>0) cout<<endl;
    }
}

