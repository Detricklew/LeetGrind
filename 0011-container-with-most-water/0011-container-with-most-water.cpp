class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; int r = height.size()-1;
        int maxi = INT_MIN;

        while(l < r){
            maxi = max((min(height[l],height[r]) * (r-l)),maxi);
       
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }

        return maxi;
    }
};