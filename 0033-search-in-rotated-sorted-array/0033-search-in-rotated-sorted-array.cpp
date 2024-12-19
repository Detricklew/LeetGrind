class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        int l = 0; int h = nums.size()-1;
        int mid = (l+h)/2;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] > nums[nums.size()-1]){
            l = mid + 1;
        }else{
           h =  mid - 1;
        }

        pivot = mid;

        while(l <= h){
            mid = (l+h)/2;
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

        l = pivot; h = (l+nums.size()-1) % nums.size();

        while (l <= h){
            mid = (((l + h)/2) + pivot) % nums.size();
            cout<<l<<endl;
            cout<<h<<endl;
            cout<<mid<<endl;
            if (nums[mid] == target){
                return mid;
            }

            if (nums[mid] > target){
                cout<<"high hit"<< endl;
                h = mid - 1;
            }else{
                cout<<"low hit"<< endl;
                l = mid + 1;
            }
        }

        return -1;
    }
};