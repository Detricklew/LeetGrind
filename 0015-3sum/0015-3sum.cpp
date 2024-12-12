class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i< nums.size() - 2; i++){
            if (i > 0 && nums[i-1] == nums[i]){
                continue;
            }

            int l = i+1; int h = nums.size() - 1;

            while (l < h){
                if(nums[i] + nums[l] + nums[h] == 0){
                    res.push_back({nums[i], nums[l], nums[h]});
                    h--;
                }

                if (nums[i] + nums[l] + nums[h] > 0){
                    h--;
                }else{
                    l++;
                    while(l<h && nums[l-1] == nums[l]){
                        l++;
                    }
                    
                }

            }
        }

        return res;
    }
};