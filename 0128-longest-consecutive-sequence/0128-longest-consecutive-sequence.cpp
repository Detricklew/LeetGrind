class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mapper;
        int res = 0;
        for (int num : nums){
            mapper.insert(num);
        }


        for (int num : nums){
            int cur = 1;

            if (mapper.find(num) == mapper.end()){
                continue;
            }
            int val = num;

            while (mapper.find(++val) != mapper.end()){
                cur++;
            }

            val = num;

            while(mapper.find(--val) != mapper.end()){
                cur++;
            }

            if (cur > (nums.size()/2)) {
                return cur;
            }

            res = max(cur, res);

        }

        return res;
    }
};