/// PAT 1048  O(N) AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    const int MAX = 10001;
    vector<int> Coins(MAX);
    Coins.assign(MAX,0);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        int c;
        cin>>c;
        Coins[c]++;
    }
    bool flag = false;
    for(int i=1;i<=M/2;i++)
    {
        Coins[i]--;
        Coins[M-i]--;
        if(Coins[i]>=0&&Coins[M-i]>=0)
        {
            cout<<i<<" "<<M-i;
            flag = true;
            return 0;
        }
    }
    if(!flag)
    {
        cout<<"No Solution";
    }
    return 0;
}
