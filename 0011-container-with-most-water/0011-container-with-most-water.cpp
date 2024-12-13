class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;

        int l = 0; int h = height.size() - 1;

        while (l<h){
            int distance = h - l;
            int water = min(height[l], height[h]) * distance;
            res = max(res, water);
            if (height[l] > height[h]){
                h--;
            }else{
                l++;
            }
        }

        return res;
    }
};