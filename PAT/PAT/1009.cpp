/// PAT 1009

#include <iostream>
using namespace std;

struct poly{
    int exp;
    double coe;
};

poly p1[10];
double product[100001] = {0};

int main()
{
    int k,i=0,j=0,cnt=0;
    int exp;
    double coe;
    cin>>k;
    while(i<k)
    {
        cin>>p1[i].exp>>p1[i].coe;
        i++;
    }
    cin>>k;
    while(j<k)
    {
        cin>>exp>>coe;
        for(int k=0;k<i;k++)
        {
            int index = exp + p1[k].exp;
            if(product[index]==0)
            {
                cnt++;
            }
            product[index] += coe * p1[k].coe;
            if(product[index]==0)
            {
                cnt--;
            }
        }
        j++;
    }
    cout<<cnt;
    for(int k=100000;k>=0;k--)
    {
        if(product[k]!=0)
        {
            printf(" %d %.1f",k,product[k]);
        }
    }
}
