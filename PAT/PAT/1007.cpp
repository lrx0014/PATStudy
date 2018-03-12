#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    bool isNeg = false;
    int sum = -1;
    int temp = 0;
    int left = 0,right = 0;
    int index = 0;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        if(num[i]>=0)
        {
            isNeg = true;
        }
        temp += num[i];
        if(temp>sum)
        {
            sum = temp;
            left = index;
            right = i;
        }else if(temp<0){
            index = i+1;
            temp = 0;
        }
    }
    if(!isNeg)
    {
        printf("%d %d %d",0,num[0],num[n-1]);
    }else{
        printf("%d %d %d",sum,num[left],num[right]);
    }

}
