#include <stdio.h>

int main()
{
    int k1;
    while(scanf("%d",&k1)!=EOF)
    {
        float op[1001];
        for(int i=0; i<=1000; i++)
        {
            op[i] = 0;
        }
        int k2;
        for(int i=0; i<k1; i++)
        {
            int coe;
            scanf("%d",&coe);
            scanf("%f",&op[coe]);
        }
        scanf("%d",&k2);
        for(int i=0; i<k2; i++)
        {
            int coe;
            float temp;
            scanf("%d",&coe);
            scanf("%f",&temp);
            op[coe] += temp;
        }
        int ct = 0;
        for(int i=0; i<1000; i++)
        {
            if(op[i]!=0) ct++;
        }
        printf("%d",ct);
        for(int i=999; i>=0; i--)
        {
            if(op[i]!=0) printf(" %d %.1f",i,op[i]);
        }
        printf("\n");
    }
}


