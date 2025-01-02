class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = 0; int h = 0;

        while(true){
            t = nums[t];
            h = nums[nums[h]];

            if (t == h){
                break;
            }
        }

        h = 0;
        while(true){
            t = nums[t];
            h = nums[h];
            
            if(t == h){
                return t;
            }
        }

        return -1;
    }
};