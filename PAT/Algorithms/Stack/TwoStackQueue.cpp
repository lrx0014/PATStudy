class TwoStack {
public:
    vector<int> twoStack(vector<int> ope, int n) {
        // write code here
        stack<int> in;
        stack<int> out;
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            if(ope[i] != 0)
            {
                in.push(ope[i]);
            }
            else
            {
                if(out.empty())
                {
                    while(!in.empty())
                    {
                        int temp = in.top();
                        in.pop();
                        out.push(temp);
                    }
                    int temp = out.top();
                    out.pop();
                    result.push_back(temp);
                }
                else
                {
                    int temp = out.top();
                    out.pop();
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};