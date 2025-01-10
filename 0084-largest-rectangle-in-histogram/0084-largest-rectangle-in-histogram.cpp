class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
                int maxi = 0;

        vector<pair<int,int>> mono;

        for (int i = 0; i < heights.size(); i++){
            int index = i + 1;
            while(!mono.empty() && heights[i] < mono.back().first){
                int ele = mono.back().first;
                index = mono.back().second;
                maxi = max(maxi, ele * ((i+1) - index ));
                mono.pop_back();
            }

            mono.push_back({heights[i],index});
        }


        while(!mono.empty()){
            int ele = mono.back().first;
            int index = mono.back().second;
            int size = (int)heights.size();
            maxi = max(maxi, ele * (size - index + 1));
            mono.pop_back();
        }

        return maxi;
    }
};