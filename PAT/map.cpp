/// 迷宫问题 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int map[5][5];
int visit[5][5];
int pre[100];  //相当于并查集里的父节点，即它的前一步是从哪个位置开始走的
struct cam
{
	int x;
	int y;
}list[100];
int dir[4][2]={{-1,0},{0,1},{0,-1},{1,0}};
int go(int x,int y)
{
	if(0<=x&&x<3&&0<=y&&y<3&&map[x][y]==0)
	return 1;
	return 0;
}
void print(int x)
{
	int t;
	t=pre[x];
    if(t==0)
	{
		printf("(0, 0)\n");   //不要忘记先输出起点
        printf("(%d, %d)\n",list[x].x,list[x].y); //找到第一个点，并且只输出第一个点
		return;
	}
	else
	print(t);  //利用那个父节点不断向前推导，直到找到第一次走的那个点为止
    printf("(%d, %d)\n",list[x].x,list[x].y);//递归退回的时候把过程中的每一个标记点输出
}
void bfs()
{
	int i,head,tail;
	memset(visit,0,sizeof(visit)); //每次访问开始都要先标记为0，以便和访问的标记为1区别开
    head=0;
	tail=1;
    list[0].x=0;  //初始化第一个值
	list[0].y=0;
	pre[0]=-1;
	while(head<tail)  //这个条件没太大用
	{
		int x=list[head].x;
		int y=list[head].y;
		if(x==2&&y==2)
		{
		    //printf("[%d and %d] pre = %d\n",list[18].x,list[18].y,pre[1]);
		    //printf("-->%d\n",head);
            print(head);  //递归输出
			return;      //递归输出结束返回主函数
		}
		for(i=0;i<4;i++)
		{
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(go(nx,ny)&&!visit[nx][ny])
			{
			    //printf("%d\n",tail);
				visit[nx][ny]=1;

				list[tail].x=nx;  //记录走过的路线
				list[tail].y=ny;
				pre[tail]=head;
				printf("%d  ",pre[tail]);
				printf("(%d,%d)\n",nx,ny);
				tail++;  //记录走了几次 （各个子节点数）
				//printf("%d\n",tail);
			}
		}
		head++;  //记录走了的父节点数
		//printf("%d\n",head);
	}

	return;
}
int main()
{
	int i,j;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	scanf("%d",&map[i][j]);
	bfs();
	return 0;
}

