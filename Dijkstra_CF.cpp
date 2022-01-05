
#include<bits/stdc++.h>
#include <ctime>
#define RAPIDO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define arr(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
#define iPair pair<int,int>
#define INF 1e9

using namespace std;

vector<iPair> adj[200500];
int V,S,T,E,cnt=0,w,x,y;
int cost[200500]={},path[200500]={},visited[200500]={};

void spath(int v) {
    if (v == -1) {
        return ;
    } else {
        int x = path[v];
        spath(x);
        if (x != -1) printf("%d ", x);
    }
} 

void dijkastra()
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push({0,1});
    cost[1] = 0;

    while(!pq.empty())
    {
        int v = pq.top().second;
        int u = pq.top().first;
        pq.pop();

        if(visited[v])
            continue;

        visited[v] = 1;

        for(int i = 0 ; i<adj[v].size();i++)
        {
            int u1 = adj[v][i].second;
            int v1 = adj[v][i].first;

            if(cost[v1]>cost[v]+u1)
            {
                cost[v1]=cost[v]+u1;
                pq.push({cost[v1],v1});

                path[v1] = v;
            }
        
        }
    }
}

void input()
{
    cin>>V>>E;

    for(int i=0;i<=V;i++)
    {
        path[i] = -1;
        cost[i] = INF;
        visited[i] = 0;
        adj[i].clear();
    }/*
    memset(path,-1,sizeof(path));
    memset(cost,INF,sizeof(cost));
    memset(visited,0,sizeof(visited));
    */

   for(int q=0;q<E;q++)
   {
       cin>>x>>y>>w;

       adj[x].push_back({y,w});
   }
   dijkastra();
   spath(V);
}

int main()
{
    RAPIDO;
    input();
    return 0;
}

