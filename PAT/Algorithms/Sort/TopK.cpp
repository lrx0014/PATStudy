#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>& b)
    {
        return a.second > b.second;
    }
};

vector<int> topK(const unordered_map<int,int>& cnt, int k)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> heap;
    auto it = cnt.begin();
    for(int i=0;i<k;i++,it++)
    {
        heap.push(*it);
    }
    for(;it!=cnt.end();it++)
    {
        if(it->second > heap.top().second)
        {
            heap.pop();
            heap.push(*it);
        }
    }
    vector<int> result;
    while(!heap.empty())
    {
        result.push_back(heap.top().first);
        heap.pop();
    }
    return result;
}

unordered_map<int,int> counter(const vector<int>& input)
{
    unordered_map<int,int> cnt;
    for(int i=0;i<input.size();i++)
    {
        cnt[input[i]]++;
    }
    return cnt;
}

int main()
{
    int in[] = {1,1,1,2,2,3,4,5,6,7,7,7,8,8,8,8};
    vector<int> input(begin(in),end(in));
    auto cnt = counter(input);
    auto tk = topK(cnt,3);
    for(int i:tk)
    {
        printf("%d ",i);
    }
}
