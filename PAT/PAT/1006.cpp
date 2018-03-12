/// PAT 1006

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Person{
    string id;
    string signIn;
    string signOut;
};

int unlock(Person A,Person B)
{
    return A.signIn < B.signIn;
}

int lock(Person A,Person B)
{
    return A.signOut > B.signOut;
}

int main()
{
    int N;
    Person person;
    cin>>N;
    vector<Person> per;
    char id[10],signIn[10],signOut[10];
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %s",id,signIn,signOut);
        person.id = id;
        person.signIn = signIn;
        person.signOut = signOut;
        per.push_back(person);
    }
    sort(per.begin(),per.end(),unlock);
    string IN = per[0].id;
    sort(per.begin(),per.end(),lock);
    string OUT = per[0].id;
    cout<<IN<<" "<<OUT;
}
