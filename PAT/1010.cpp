/// PAT 1010

#include <iostream>
#include <cstring>
#include <functional>
using namespace std;

long long int Cal(char c)
{
    if(c>='0' && c<='9')
    {
        return (c - '0');
    }else{
        return (c - 'a' + 10);
    }
}

long long int CalValueBaseRadix(char t[],long long int radix)
{
    int i;
    long long int result = 0;
    for(i=0;i<strlen(t);i++)
    {
        result *= radix;
        result += Cal(t[i]);
        if(result < 0)
        {
            return -1;
        }
    }
    return result;
}

int main()
{
    char a[15],b[15];
    long long tag;
    long long radixA,radixB;

    scanf("%s%s%lld%lld",a,b,&tag,&radixA);

    if(tag==2)
    {
        char tmp[15];
        strcpy(tmp,a);
        strcpy(a,b);
        strcpy(b,tmp);
    }

    long long minRadix,maxRadix;

    long long i;
    long long int valueA = CalValueBaseRadix(a,radixA);
    minRadix = 0;
    for(i=0;i<strlen(b);i++)
    {
        if(Cal(b[i])>minRadix)
        {
            minRadix = Cal(b[i])+1;
        }
    }

    maxRadix = valueA + 1;
    while(minRadix <= maxRadix)
    {
        radixB = (minRadix + maxRadix)/2;
        long long int valueB = CalValueBaseRadix(b,radixB);
        if(valueB==-1||valueB>valueA)
        {
            maxRadix = radixB - 1;
        }else if(valueB<valueA){
            minRadix = radixB + 1;
        }else if(valueA==valueB)
        {
            cout<<radixB;
            return 0;
        }
    }
    cout << "Impossible";
    return 0;
}
