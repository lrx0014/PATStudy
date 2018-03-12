/// PAT 1132

#include <sstream>
#include <iostream>
using namespace std;

int strToint(string str)
{
    stringstream ss;
    int res;
    ss<<str;
    ss>>res;
    return res;
}

string intTostr(int num)
{
    stringstream ss;
    string str;
    ss<<num;
    ss>>str;
    return str;
}

bool solve(int num)
{
    string s = intTostr(num);
    int len = s.size();
    string a,b;
    for(int i=0;i<len/2;i++)
    {
        a += s[i];
        b += s[len/2 + i];
    }
    int aa,bb;
    aa = strToint(a);
    bb = strToint(b);
    if(aa*bb==0)
    {
        return false;
    }
    if(num%(aa*bb)==0)
    {
        return true;
    }
    return false;
}


int main()
{
    int n;
    long nums;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>nums;
        if(solve(nums)==true)
        {
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}
