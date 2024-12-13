class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0; int h = height.size() - 1;
        int lmax = height[l]; int hmax = height[h];
        int res = 0;

        while(l<h){
            int val = 0;
            if(height[l] < height[h]){
                val =  lmax - height[l];
                res += val < 0 ? 0 : val;
                if (height[l] > lmax) lmax = height[l];
                l++;
            }else{
                val =  hmax - height[h];
                res += val < 0 ? 0 : val;
                if (height[h] > hmax) hmax = height[h];
                h--;
            }
        }

        return res;
    }
};