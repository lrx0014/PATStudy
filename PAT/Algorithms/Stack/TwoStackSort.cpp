class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        vector<int> help;
        int cur;
        while(!numbers.empty())
        {
            cur = numbers.back();
            numbers.pop_back();
            while(!help.empty() && cur>help.back())
            {
                numbers.push_back(help.back());
                help.pop_back();
            }
            help.push_back(cur);
        }
        return help;
    }
};