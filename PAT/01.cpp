#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conv(int num,char *s)
{
    if(num<0)
    {
        *s = '-';
        s++;
        num = 0 - num;
    }
    while(num>=10)
    {
        *s = (num%10) + '0';
        num = num / 10;
        s++;
    }
    *s = num + '0';
    s++;
    *s = '\0';
}

int main()
{
    char s[10];
    conv(-12345678,s);
    printf("%s",s);
}

int main2()
{
    int a;
    int b;
    int c;
    while(scanf("%d",&a)!=EOF)
    {
        scanf("%d",&b);
        c = a + b;
        if(c<1000)
        {
            printf("%d\n",c);
            continue;
        }
        char str[20];
        conv(c,str);
        int len = strlen(str);
        char *head;
        head = &str[len-1];
        int ct = 3;
        char op[30];
        op[0] = 'x';
        char *p;
        p = &op[29];
        for(int i=0;i<=len;i++)
        {
            if(*head=='-')
            {
                head--;
                //printf("-");
                op[0] = '-';
                continue;
            }
            if(ct>0)
            {
                //printf("%c",*head);
                *p = *head;
                p--;
                head--;
                ct--;
            }else{
                //printf(",");
                *p = ',';
                p--;
                ct = 3;
            }
        }
        if(op[0]=='-')
        {
            printf("-");
        }
        p++;
        while(p!=&op[30])
        {
            printf("%c",*p);
            p++;
        }
        printf("\n");
    }
}
