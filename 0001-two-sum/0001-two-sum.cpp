class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        vector<int> return_vect;
        for (int i = 0; i < nums.size(); i++){
            if(hash.find(nums[i]) != hash.end()){
                printf("here me boi\n");
                return_vect.push_back(hash[nums[i]]);
                return_vect.push_back(i);
                return return_vect;
            }

            hash[target - nums[i]] = i;
        }

        return return_vect;
    }
};