class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        // write code here
        if(arr.empty() || w>n)
        {
            return arr;
        }
        
        vector<int> res(n-w+1);
        deque<int> qmax;
        int index = 0;
        for(int i=0;i<n;i++)
        {
            while(!qmax.empty() && arr[qmax.back()]<=arr[i])
            {
                qmax.pop_back();
            }
            qmax.push_back(i);
            if(qmax.front() == i-w)
            {
                qmax.pop_front();
            }
            if(i>=w-1)
            {
                res[index++] = arr[qmax.front()];
            }
        }
        return res;
    }
};