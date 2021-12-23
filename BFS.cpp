#include<bits/stdc++.h>
using namespace std;

int A[5][5] ={ {0,1,0,0,1},
               {1,0,1,1,1},
               {0,1,0,1,0},
               {0,1,1,0,1},
               {1,1,0,1,0} };

int g[5][5] ={ {0,1,1,0,0},
               {1,0,0,1,1},
               {1,0,0,0,0},
               {0,1,0,0,0},
               {0,1,0,0,0} };

int stat [5] ={1,1,1,1,1};
int path[5] ={};


queue<int>q;
stack<int>s;

void BFS(int x)
{
    q.push(x);
    stat[x]=2;
    cout<<x<<" ";

    while(!q.empty())
    {
        for(int i=0;i<5;i++)
        {
            if(stat[i]==1 && g[q.front()][i]==1)
            {
                q.push(i);
                stat[i]=2;
                cout<<i<<" ";
                path[i] = q.front();
            }
        }
        stat[q.front()]=3;
        q.pop();
    }
}

void DFS(int x)
{
    s.push(x);
    stat[x]=2;
    cout<<x<<" ";

    while(!s.empty())
    {
        for(int i=0;i<5;i++)
        {
            if(stat[i]==1 && g[s.top()][i]==1)
            {
                s.push(i);
                stat[i]=2;
                cout<<i<<" ";
            }
        }
        stat[s.top()]=3;
        s.pop();
    }
}

void solve(int b)
{
    int i,j;

    q.push(b);
    stat[b]++;

    while(!q.empty())
    {
        for(i=0;i<5;i++)
        {
            if(g[q.front()][i]==1 && stat[i]==1)
            {
                q.push(i);
                stat[i]=2;
            }
        }

        if(stat[q.front()] == 2)
        {
            cout<<q.front()<<" ";

            stat[q.front()] = 3;
            q.pop();
            //stat();

            //if(!q.empty())
                //cout<<" --> ";
        }
    }

}

int main()
{
    //solve(0);
    //BFS(0);
    BFS(0);
    cout<<endl;
    for(int i=0;i<5;i++)
        cout<<path[i]<<" ";
    return 0;
}
