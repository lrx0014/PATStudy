/// PAT 1024 ע�⣺�����ӷ�

#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string Plus(string num1,string num2)
{
    if(num1.size()<num2.size()) //��num1�̶�Ϊλ���ϴ���Ǹ�����������洦��
    {
        string temp=num1;
        num1=num2;
        num2=temp;
    }
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag�ǽ�λ���
    while(length1>0) //�ӵ�λ��ʼ�Ѷ�Ӧ��λ���
    {
        a=num1[length1-1]-'0';//��ȡnum1��ǰλ������
        if(length2>0)//���num2��û���꣨ע�⣬num2��λ�����ٵģ�
            b=num2[length2-1]-'0';//��ȡnum2��ǰλ������
        else
            b=0;//���num2�����ˣ�num2��Ӧλ�Ͼ�û����������
        //��ʱ��û��break����Ϊ��Ȼnum2û�����������ˣ������ܻ��н�λ��Ҫ��
        sum=a+b+flag;//num1��num2��Ӧλ�ϵ�������ӣ��ټ��Ͻ�λλ
        if(sum>=10) //���������������10���Ǿ���Ҫ��λ��
        {
            num1[length1-1]='0'+sum%10;//�������֮�󣬵�ǰλӦ���Ƕ���
            flag=1;//�ѽ�λ�����1
        }
        else
        {
            num1[length1-1]='0'+sum;//�������֮�󣬵�ǰλӦ���Ƕ���
            flag=0;//�ѽ�λ�����0
        }
        length1--;//���λ�ƶ�1λ
        length2--;//���λ�ƶ�1λ
    }
    //�����������Ӧλ�������ˣ���λλ��1��˵��λ��Ҫ����1��
    //����99+1������֮�󣬱������λ��100����ʵ��������ǰ���һλ1
    if(1==flag)
        num1="1"+num1;
    return num1;
}

string IntToString(int num)
{
    stringstream ss;
    string str;
    ss << num;
    ss >> str;
    return str;
}

int StringToInt(string str)
{
    stringstream ss;
    ss<<str;
    int num;
    ss>>num;
    return num;
}

bool isPalin(string str1)
{
    string str2 = str1;
    reverse(str1.begin(),str1.end());
    if(str1==str2)
    {
        return true;
    }
    return false;
}

string add(string str)
{
    string str2 = str;
    reverse(str.begin(),str.end());
    return Plus(str,str2);
}

int main()
{
    string num;
    int k;
    cin>>num>>k;
    for(int i=0; i<k; i++)
    {
        if(isPalin(num))
        {
            cout<<num<<"\n"<<i;
            return 0;
        }
        else
        {
            num = add(num);
        }
    }
    cout<<num<<"\n"<<k;
    return 0;
}

