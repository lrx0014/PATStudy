/// �Թ����� 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int map[5][5];
int visit[5][5];
int pre[100];  //�൱�ڲ��鼯��ĸ��ڵ㣬������ǰһ���Ǵ��ĸ�λ�ÿ�ʼ�ߵ�
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
		printf("(0, 0)\n");   //��Ҫ������������
        printf("(%d, %d)\n",list[x].x,list[x].y); //�ҵ���һ���㣬����ֻ�����һ����
		return;
	}
	else
	print(t);  //�����Ǹ����ڵ㲻����ǰ�Ƶ���ֱ���ҵ���һ���ߵ��Ǹ���Ϊֹ
    printf("(%d, %d)\n",list[x].x,list[x].y);//�ݹ��˻ص�ʱ��ѹ����е�ÿһ����ǵ����
}
void bfs()
{
	int i,head,tail;
	memset(visit,0,sizeof(visit)); //ÿ�η��ʿ�ʼ��Ҫ�ȱ��Ϊ0���Ա�ͷ��ʵı��Ϊ1����
    head=0;
	tail=1;
    list[0].x=0;  //��ʼ����һ��ֵ
	list[0].y=0;
	pre[0]=-1;
	while(head<tail)  //�������û̫����
	{
		int x=list[head].x;
		int y=list[head].y;
		if(x==2&&y==2)
		{
		    //printf("[%d and %d] pre = %d\n",list[18].x,list[18].y,pre[1]);
		    //printf("-->%d\n",head);
            print(head);  //�ݹ����
			return;      //�ݹ������������������
		}
		for(i=0;i<4;i++)
		{
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(go(nx,ny)&&!visit[nx][ny])
			{
			    //printf("%d\n",tail);
				visit[nx][ny]=1;

				list[tail].x=nx;  //��¼�߹���·��
				list[tail].y=ny;
				pre[tail]=head;
				printf("%d  ",pre[tail]);
				printf("(%d,%d)\n",nx,ny);
				tail++;  //��¼���˼��� �������ӽڵ�����
				//printf("%d\n",tail);
			}
		}
		head++;  //��¼���˵ĸ��ڵ���
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

