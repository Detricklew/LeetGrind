class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int sum = 0;
        int max = 0;
        for(int num: piles){
            sum += num;
            if (max < num) max = num;
        }
        
        int hi = max; long int l = ceil(sum/h);
        int k = max;
        while (l<=hi && (l+hi)/2 != 0){
            int mid = (l+hi)/2;

            int kcan = 0;
            for (int num: piles){
                kcan += ceil((double)num/mid);
            }

            if (kcan <= h){
                k = mid;
                hi = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return k;
    }
};