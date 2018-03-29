#include <iostream>

using namespace std;

int n = 8;
int total = 0;
int *c = new int(n);

bool is_ok(int row)
{
    for(int i=0;i!=row;i++)
    {
        if(c[row]==c[i] || row-c[row]==i-c[i] || row+c[row]==i+c[i])
        {
            return false;
        }
    }
    return true;
}

void put_queen(int row)
{
    if(row == n)
    {
        total ++;
    }
    else
    {
        for(int col=0;col!=n;col++)
        {
            c[row] = col;
            if(is_ok(row))
            {
                put_queen(row+1);
            }
        }
    }
}

int main()
{
    put_queen(0);
    cout<<total<<endl;
}
