/// PAT 1011

#include <cstdio>
#include <iostream>
using namespace std;

double odd[3][3];

int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>odd[i][j];
        }
    }
    double product = 0.65;
    double result = 0.0;
    const char ch[] = {'W','T','L'};
    int index[3];
    for(int i=0;i<3;i++)
    {
        double cur = odd[i][0];
        index[i] = 0;
        for(int j=0;j<3;j++)
        {
            if(cur<odd[i][j])
            {
                cur = odd[i][j];
                index[i] = j;
            }
        }
        product *= cur;
    }
    result = (product-1)*2;
    printf("%c %c %c %.2f",ch[index[0]],ch[index[1]],ch[index[2]],result);
}
