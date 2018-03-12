/// PAT 1005

#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 105;

const string s[10] = {"zero",
                      "one",
                      "two",
                      "three",
                      "four",
                      "five",
                      "six",
                      "seven",
                      "eight",
                      "nine"};

int main()
{
    char str[maxn],ans[5];
    cin>>str;
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<strlen(str);i++)
    {
        sum += str[i] - '0';
    }
    if(sum==0)
    {
        cout<<s[0];
        return 0;
    }
    while(sum)
    {
        ans[cnt++] = sum%10;
        sum = sum / 10;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        cout<<s[ans[i]];
        if(i)
        {
            cout<<" ";
        }
    }
    return 0;
}
