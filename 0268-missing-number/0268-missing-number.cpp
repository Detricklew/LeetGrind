class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_sum = nums.size() * (nums.size() + 1)/2;

        int sum;

        for (int num : nums){
            sum += num;
        }
        
        return expected_sum - sum;
    }
};