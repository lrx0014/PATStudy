/***************************************************************************************************

������˼·�����Ȱ���׺���ʽת��Ϊ��׺���ʽ��Ȼ���ú�׺���ʽ�����ʽ�ӵ�ֵ

1.����׺���ʽת��Ϊ��׺���ʽ�ķ�����
(1) ��ʼ������ջ�������ջS1�ʹ����м�����ջS2��
(2) ��������ɨ����׺���ʽ��
(3) ����������ʱ������ѹ��S2�������������������ܴ���10������������ֺ���һ���������������
    �򽫡�#����S2ջ�䵱�ָ��ߣ�
(4) ���������ʱ�����������
(4-1) ���������ֱ����S1ջ��S1Ϊ�բ������Ϊ����������������ȼ���S1ջ��������ĸߣ�
(4-2)��������š�)���������ε���S1ջ�������������ѹ��S2��ֱ������������Ϊֹ����ʱ����һ�����Ŷ�����
(4-3) ����������ȼ�С�ڻ����S1ջ������������ȼ��������ε���S1ջ��Ԫ�أ�
      ֱ������������ȼ�����S1ջ����������ȼ���
(6) �ظ�����(2)��(5)��ֱ�����ʽ�����ұߣ�
(7) ��S1��ʣ�����������ε�����ѹ��S2��
(8) ���ε���S2�е�Ԫ�ز���������������Ϊ��׺���ʽ��Ӧ�ĺ�׺���ʽ��
��������ȼ�������=����>����=����>��������=�����ţ���

2.��׺���ʽ���㷽����
��1������һ��intջS3������һ����������num�����洢����10�����ֱ��ڼ��㣬��������ɨ����ʽ��
��2����������ʱ��
��2-1�������ֺ���һ��Ԫ�ز���#�����ֺ���ֻ������#�����֣��������ַ�ת��Ϊ���ִ���num[ ]�����У�
��2-2�������ֺ���һ��Ԫ����#����num�����б���������������ѹ��S3ջ�С�
��3�����������ʱ������S3ջ�����������������������������Ӧ�ļ��㣨�ζ�Ԫ�� op ջ��Ԫ�أ���
     ���������ջ���ظ���������ֱ�����ʽ���Ҷˣ��������ó���ֵ��Ϊ���ʽ�Ľ����

***************************************************************************************************/

#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

stack<char> s1,s2;
stack<int> s3;
char ch[150] = {0};
int num[11];

int priority(char ch)
{
    if(ch==')' || ch=='(')  return 1;
    if(ch=='+' || ch=='-')  return 2;
    if(ch=='*' || ch=='/')  return 3;
}

int calTwoNum(int x,int y,char op)
{
    switch(op)
    {
    case '+':
        return x+y;
    case '-':
        return x-y;
    case '*':
        return x*y;
    case '/':
        return x/y;
    }
}

void Transfer(int n)
{
    int k = 0;
    for(int i=0;i<n;i++)
    {
        if(ch[i]>='0' && ch[i]<='9')
        {
            if(i+1<n && (ch[i+1]<'0' || ch[i+1]>'9') || i==n-1)
            {
                s2.push(ch[i]);
                s2.push('#');
            }
            else
            {
                s2.push(ch[i]);
            }
        }
        else
        {
            if(s1.empty() || ch[i]=='(' || priority(ch[i])>priority(s1.top()))
            {
                s1.push(ch[i]);
            }
            else if(ch[i]==')')
            {
                while(s1.top()!='(')
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.pop();
            }
            else
            {
                while(!s1.empty() && priority(ch[i])<=priority(s1.top()) && s1.top()!='(')
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(ch[i]);
            }
        }
    }
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty())
    {
        ch[k++] = s2.top();
        s2.pop();
    }
    reverse(ch,ch+k);
    ch[k] = 0;
}

int calculate(int n)
{
    int x,y,tmp=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(ch[i]=='#')
        {
            continue;
        }
        else if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]=='/')
        {
            x = s3.top();
            s3.pop();
            y = s3.top();
            s3.pop();
            x = calTwoNum(y,x,ch[i]);
            s3.push(x);
        }
        else
        {
            if(ch[i+1]=='#')
            {
                num[k++] = ch[i]-'0';
                for(int j=0;j<k;j++)
                {
                    tmp += (num[j]*(int)pow(10,k-j-1));
                }
                s3.push(tmp);
                tmp = 0;
                k = 0;
            }
            else
            {
                num[k++] = ch[i]-'0';
            }
        }
    }
    return s3.top();
}

int main()
{
    gets(ch);
    Transfer(strlen(ch));
    cout<<calculate(strlen(ch))<<endl;
}
