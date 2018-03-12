#include "stdio.h"
#define MAX 1010
int main()
{
    int n,m;
    float z;
    while(scanf("%d",&n)!=EOF)
    {
        float t[MAX]= {0}; //定义float类型数组，用于存放不同指数下的系数和，数字下标即代表指数
        for(int i=0; i<n; i++)
        {
            scanf("%d%f",&m,&z);
            t[m]+=z;
        }
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%f",&m,&z);
            t[m]+=z;
        }
        n=0;
        //计算多项式有几项
        for(int i=0; i<MAX; i++)
        {
            if(t[i]!=0) n++;
        }
        printf("%d",n);
        for(int i=MAX-1; i>=0; i--)
        {
            if(t[i]!=0) printf(" %d %.1f",i,t[i]);
        }
        printf("\n");
    }
}
