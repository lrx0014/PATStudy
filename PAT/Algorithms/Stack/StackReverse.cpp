class StackReverse {
public:
    vector<int> reverseStack(vector<int>& A, int n) {
        // write code here
        if(A.empty())
        {
            return A;
        }
        int last = getLast(A);
        reverseStack(A,n);
        A.push_back(last);
        return A;
    }
    
    int getLast(vector<int>& A)
    {
        int result = A.back();
        A.pop_back();
        if(A.empty())
        {
            return result;
        }
        int last = getLast(A);
        A.push_back(result);
        return last;
    }
};