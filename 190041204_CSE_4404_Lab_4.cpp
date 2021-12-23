// AASHNAN RAHMAN
// 190041204
// CSE 4404 Lab 4

#include<bits/stdc++.h>
using namespace std;

int V[10000][10000]={},h,w,visited[10000][10000]={};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void init()
{
    cin>>h>>w;
    char a;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a;
            if(a=='!')
            {
                V[i][j]=0;
            }
            else V[i][j]=1;

            visited[i][j]=-1;
        }
    }
}

void print()
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}

int BFS()
{
    queue < pair<int,int> >q;
    int cnt = 0;


    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            //cout<<1<<endl;
            if(V[i][j] == 0 || visited[i][j]>=0)
            {
                //cout<<1<<endl;
                continue;
            }
            else
            {
                //cout<<i<<" "<<j<<"abc"<<endl;
                cnt++;
                q.push({i,j});
                visited[i][j]=1;

                while(!q.empty())
                {
                    pair<int,int> curr = q.front();
                    q.pop();

                    for(int x=0; x<4; x++)
                    {

                        int x1 = curr.first + dx[x];
                        int y1 = curr.second + dy[x];

                        //cout<<cnt<<endl;
                        //cout<<x1<<" "<<y1<<endl;


                        if(x1>=0 && x1<=h && y1>=0 && y1<=w)
                        {
                            if(V[x1][y1] == 1 && visited[x1][y1]==-1)
                            {
                                //cout<<x1<<" "<<y1<<endl;
                                q.push({x1,y1});
                                visited[x1][y1]=1;
                            }

                        }

                    }


                }


            }
        }

    }
    return cnt;
}

int main()
{
    init();
    //print();
    cout<<BFS();
}

