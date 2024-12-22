class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int a = nums1.size(); 
        int b = nums2.size();

        if(b < a){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total = a + b;

        int half = (total + 1)/2;

        int l = 0; int h = a;


        while(true){
            int mid = (l+h)/2;

            int bMid = half - mid;

            int r1 = INT_MAX;
            int l1 = INT_MIN;
            int r2 = INT_MAX;
            int l2 = INT_MIN;

            if (mid >= 0 && mid < a){
                r1 = nums1[mid];
                cout<<"r1"<<endl;
                cout<<mid<<endl;
                
            }
            
            if (mid < a) r1 = nums1[mid];

            if (bMid < b) r2 = nums2[bMid];

            if (mid - 1 >= 0)  l1 = nums1[mid - 1]; 

            if (bMid - 1 >= 0) l2 = nums2[bMid - 1];

            if (l1 <= r2  && l2 <= r1){
                if (total % 2 != 0){
                    return max(l1, l2);
                }
                return (max(l1, l2) + min(r1,r2)) / 2.0;
            }

            if (r1 > l2){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }

        }


        return -1;

    }
};