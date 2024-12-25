class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> dq;
        vector<int> res;
        int i = 0;
        for (; i < k-1; i++){
            if(dq.empty()){
                dq.push_back(nums[i]); 
                continue;
            } 

            while (!dq.empty() && dq[dq.size() - 1] < nums[i]){
                dq.pop_back();
            }


            dq.push_back(nums[i]);
        }
        int l = 0;
        while (i < nums.size()){
            while (!dq.empty() && dq[dq.size() - 1] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(nums[i++]);

            res.push_back(dq[0]);

            if(nums[l++] == dq[0]){
                dq.erase(dq.begin());
            }


        }

        return res;
    }
};