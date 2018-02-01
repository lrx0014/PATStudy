/// PAT 1032

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int Map[100005];
int vst[100005] = {0};

int main()
{
    memset(Map,-1,sizeof(Map));
    int add1,add2,n;
    scanf("%d%d%d",&add1,&add2,&n);

    for(int i=0;i<n;i++)
    {
        ///printf("%d::%d\n\n",i,n);
        int cur,Next;
        char ch;
        scanf("%d %c %d",&cur,&ch,&Next);
        ///cin>>cur>>ch>>Next;
        Map[cur] = Next;
    }

    int add = add1;
    while(add!=-1)
    {
        vst[add] = 1;
        add = Map[add];
    }
    add = add2;
    while(add!=-1 && !vst[add])
    {
        add = Map[add];
    }
    if(add==-1)
    {
        printf("-1");
    }else{
        printf("%05d",add);
    }
}
