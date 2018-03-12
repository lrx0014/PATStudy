/// PAT 1008

#include <iostream>
using namespace std;

int main()
{
    int N;
    int cur=0,next;
    int total = 0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>next;
        if(next==cur)
        {
            total += 5;
        }
        else if(next>cur)
        {
            total += (next-cur)*6 + 5;
            cur = next;
        }
        else if(next<cur)
        {
            total += (cur-next)*4 + 5;
            cur = next;
        }
    }
    cout<<total;
}
