/// PAT 1065

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int A,B,C;
    bool res[10] = {true};
    for(int i=0;i<n;i++)
    {
        cin>>A>>B>>C;
        long long int temp = A+B;
        if(A>0&&B>0&&temp<=0)    res[i] = true;
        else if(A<0&&B<0&&temp>=0)   res[i] = false;
        else if(temp>C) res[i] = true;
        else   res[i] = false;
    }
    for(int i=0;i<n;i++)
    {
        if(res[i]==true)
        {
            printf("Case #%d: true",i+1);
        }else{
            printf("Case #%d: false",i+1);
        }
        if(i!=n-1)
        {
            cout<<"\n";
        }
    }
    return 0;
}
