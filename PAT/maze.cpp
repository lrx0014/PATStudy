/// √‘π¨Œ Ã‚ 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define M 3
#define N 3

struct Cur_Node{
    int x;
    int y;
    int steps;
};

struct Pre_Node{
    int x;
    int y;
    char op;
};

int     mmp[10][10] = {};
int visited[10][10] = {};

int directions[4][2] = {
    {1,0} ,
    {-1,0} ,
    {0,1} ,
    {0,-1}
};

queue<Cur_Node> q;

Cur_Node cur,pre;

Pre_Node path[10][10];

void bfs()
{
    cur.x     = 0;
    cur.y     = 0;
    cur.steps = 0;

    pre.x = M - 1;
    pre.y = N - 1;

    q.push(cur);

    path[cur.x][cur.y].x  = 100;
    path[cur.x][cur.y].y  = 100;
    path[cur.x][cur.y].op = 0;

    visited[cur.x][cur.y] = 1;

    while(!q.empty())
    {
        Cur_Node now = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            Cur_Node next;
            next.x = now.x + directions[i][0];
            next.y = now.y + directions[i][1];
            next.steps = now.steps + 1;
            if(next.x<0 || next.y<0 || next.x>M || next.y>N || visited[next.x][next.y] || mmp[next.x][next.y]==1)
            {
                continue;
            }else{
                q.push(next);
                path[next.x][next.y].x = now.x;
                path[next.x][next.y].y = now.y;
                if     (i==0) path[next.x][next.y].op = 'D';
                else if(i==1) path[next.x][next.y].op = 'L';
                else if(i==2) path[next.x][next.y].op = 'R';
                else if(i==3) path[next.x][next.y].op = 'U';

                visited[next.x][next.y] = 1;

                if(next.x==pre.x && next.y==pre.y)
                {
                    return;
                }
            }
        }
    }
    return;
}

void print_dfs(int x,int y)
{
    if(x==0 && y==0)
    {
        return;
    }else{
        print_dfs(path[x][y].x,path[x][y].y);
        cout<<path[x][y].op<<endl;
    }
}


int main()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>mmp[i][j];
        }
    }
    bfs();
    print_dfs(M-1,N-1);
}
