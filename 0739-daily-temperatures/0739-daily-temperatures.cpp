class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);

        vector<int> stacky_stack;

        for (int i = 0; i < temperatures.size(); i++){
            if (!(stacky_stack.size())){
                stacky_stack.push_back(i);
                continue;
            }

            while((stacky_stack.size()) && temperatures[stacky_stack.back()] < temperatures[i]){
                res[stacky_stack.back()] = i - stacky_stack.back(); stacky_stack.pop_back();
            }

            stacky_stack.push_back(i);
        }
        return res;
    }
};