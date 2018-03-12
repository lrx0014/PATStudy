/// PAT 1028

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Person{
    int id;
    char name[20];
    int score;
};

Person per[100001];

int cmp1(Person A,Person B)
{
    return A.id < B.id;
}

int cmp2(Person A,Person B)
{
    if(strcmp(A.name,B.name)<0)
    {
        return true;
    }else if(strcmp(A.name,B.name)==0&&A.id<B.id)
    {
        return true;
    }
    return false;
}

int cmp3(Person A,Person B)
{
    if(A.score<B.score)
    {
        return true;
    }else if(A.score==B.score&&A.id<B.id)
    {
        return true;
    }
    return false;
}

int main()
{
    int N,C;
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++)
    {
        scanf("%d%s%d",&per[i].id,per[i].name,&per[i].score);
    }
    switch(C)
    {
    case 1:
        sort(per,per+N,cmp1);
        break;
    case 2:
        sort(per,per+N,cmp2);
        break;
    case 3:
        sort(per,per+N,cmp3);
        break;
    }
    for(int i=0;i<N;i++)
    {
        printf("%06d %s %d\n",per[i].id,per[i].name,per[i].score);
    }
}
