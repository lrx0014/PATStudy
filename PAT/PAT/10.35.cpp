/// PAT 1035

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct Team{
    string name;
    string pwd;
};

Team team[1001];

bool Found(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='1'||str[i]=='l'||str[i]=='0'||str[i]=='O')
        {
            return true;
        }
    }
    return false;
}

void Solve(string &str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='1')
        {
            str[i] = '@';
        }
        if(str[i]=='l')
        {
            str[i] = 'L';
        }
        if(str[i]=='O')
        {
            str[i] = 'o';
        }
        if(str[i]=='0')
        {
            str[i] = '%';
        }
    }
}

int main()
{
    int N;
    cin>>N;
    string name,pwd;
    int modified[1001];
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        scanf("%s %s",name,pwd);
        team[i].name = name;
        team[i].pwd = pwd;
    }
    for(int i=0;i<N;i++)
    {
        if(Found(team[i].pwd))
        {
            modified[cnt++] = i;
            Solve(team[i].pwd);
        }
    }
    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++)
    {
        cout<<team[modified[i]].name<<" "<<team[modified[i]].pwd<<"\n";
    }
}

