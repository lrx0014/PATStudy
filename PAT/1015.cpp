/// PAT 1015 ??

#include <iostream>
#include <cstdio>
using namespace std;

bool isPrime(int num)
{
    if(num<2)
    {
        return false;
    }
    if(num==2||num==3)
    {
        return true;
    }
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}

int rev_num(int num,int radix)
{
    int temp;
    while(num)
    {
        temp *= radix;
        temp += num%radix;
        num /= radix;
    }
    return temp;
}

int main()
{
    /// /// ??????
    cout<<rev_num(8,2);
}

int main2()
{
    int n,d;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
        {
            break;
        }
        scanf("%d",&d);
        int n_rev;
        n_rev = rev_num(n,d);
        if(isPrime(n)==true && isPrime(n_rev)==true)
        {
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}
