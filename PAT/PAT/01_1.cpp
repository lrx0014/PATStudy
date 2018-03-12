#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d",&a,&b);
    c = a + b;
    d = abs(c);
    if(d<1000)
    {
        printf("%d",c);
    }
    if(d>=1000 && d<1000000)
    {
        printf("%d,%03d",c/1000,d%1000);
    }
    if(d>=1000000)
    {
        printf("%d,%03d,%03d",c/1000000,(d/1000)%1000,d%1000);
    }
}
