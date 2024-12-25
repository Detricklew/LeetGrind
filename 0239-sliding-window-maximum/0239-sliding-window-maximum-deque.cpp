class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int i = 0;
        for (; i < k-1; i++){
            if(dq.empty()){
                dq.push_back(nums[i]); 
                continue;
            } 

            while (!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }


            dq.push_back(nums[i]);
        }
        int l = 0;
        while (i < nums.size()){
            while (!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }

            dq.push_back(nums[i++]);

            res.push_back(dq.front());

            if(nums[l++] == dq.front()){
                dq.pop_front();
            }


        }

        return res;
    }
};