class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxu = 0;
        stack<pair<int,int>> stacku;


        for (int i = 0; i < heights.size(); i++){
            
            int index = i;
            
            while(!stacku.empty() && stacku.top().second > heights[i]){
                pair<int,int> top = stacku.top();
                int start = top.first;
                int height = top.second;
                maxu = max(maxu, height * (i - start));
                index = start;
                stacku.pop();
            }
            stacku.push({index, heights[i]});

        }

        while(!stacku.empty()){
            int size = static_cast<int>(heights.size());
            int index = stacku.top().first;
            int height = stacku.top().second;

            maxu = max(maxu, height * (size - index));

            stacku.pop();
        }

        return maxu;
    }
};