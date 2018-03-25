/***************************************************************************************************

这个题的思路就是先把中缀表达式转化为后缀表达式，然后用后缀表达式计算出式子的值

1.将中缀表达式转换为后缀表达式的方法：
(1) 初始化两个栈：运算符栈S1和储存中间结果的栈S2；
(2) 从左至右扫描中缀表达式；
(3) 遇到操作数时，将其压入S2，这里由于运算数可能大于10，所以如果数字后面一个符号是运算符，
    则将‘#’入S2栈充当分割线；
(4) 遇到运算符时有三种情况：
(4-1) 三种情况下直接入S1栈①S1为空②运算符为‘（’③运算符优先级比S1栈顶运算符的高；
(4-2)如果右括号“)”，则依次弹出S1栈顶的运算符，并压入S2，直到遇到左括号为止，此时将这一对括号丢弃；
(4-3) 若运算符优先级小于或等于S1栈顶运算符的优先级，则依次弹出S1栈顶元素，
      直到运算符的优先级大于S1栈顶运算符优先级；
(6) 重复步骤(2)至(5)，直到表达式的最右边；
(7) 将S1中剩余的运算符依次弹出并压入S2；
(8) 依次弹出S2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式。
运算符优先级：（乘=除）>（加=减）>（左括号=右括号）。

2.后缀表达式计算方法：
（1）定义一个int栈S3，定义一个整形数组num用来存储大于10的数字便于计算，从左至右扫描表达式。
（2）遇到数字时：
（2-1）若数字后面一个元素不是#（数字后面只可能是#或数字）则将数字字符转化为数字存在num[ ]数组中；
（2-2）若数字后面一个元素是#，将num数组中保存的数字算出来并压入S3栈中。
（3）遇到运算符时，弹出S3栈顶的两个数，用运算符对它们做相应的计算（次顶元素 op 栈顶元素），
     并将结果入栈；重复上述过程直到表达式最右端，最后运算得出的值即为表达式的结果。

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
