class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int h = nums.size() - 1;

        int pivot =  h;

        while (l<=h){
            int mid = (l + h)/2;

            if (nums[mid] == target){
                return mid;
            }

            if (nums[mid] > nums[h]){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
            if (nums[mid] < nums[pivot]) pivot = mid;
        }

        l = 0; h = nums.size() - 1;

        if (target > nums[pivot] && target <= nums[h]){
            l = pivot + 1;
        }
        else{
            h = pivot - 1;
        }

        while (l <= h){
            int mid = (l + h)/2;

            if (nums[mid] == target){
                return mid;
            }

            if (nums[mid] > target){
                h = mid - 1; 
            }else{
                l = mid - 1;
            }
        }

        return -1;
    }
};