/// PAT 1048 O(N2) OverTime

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    int Coins[100001];
    cin>>N>>M;
    int x,cnt=0;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        if(x<M)
        {
            Coins[cnt++] = x;
        }
    }

    int v1=0;
    int v_min = 0;
    for(int i=0;i<cnt;i++)
    {
        for(int j=i+1;j<cnt;j++)
        {
            if(Coins[i]+Coins[j]==M)
            {
                v1 = (Coins[i]<Coins[j])?Coins[i]:Coins[j];
            }
            if(v1<v_min||v_min==0)
            {
                v_min = v1;
            }
        }
    }
    int v2 = M-v_min;
    if(v_min==0&&v2==M)
    {
        cout<<"No Solution";
        return 0;
    }
    if(v_min>v2)
    {
        cout<<v2<<" "<<v_min;
    }else{
        cout<<v_min<<" "<<v2;
    }
}
