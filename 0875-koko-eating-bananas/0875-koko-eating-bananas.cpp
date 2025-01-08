class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long max = -1;
        

        for (int num : piles){
            if(num > max){
                max = num;
            }
        }

        int l = 1; int hi = max;
        int res = max;
        while(l <= hi){
            int mid = (l+hi)/2;
            long long time = 0;
            for(int num : piles){
                time += ceil(static_cast<double>(num)/mid);
            }

            cout << time<<endl;
            if(time > h){
                l = mid + 1;
            }else{
                res = mid;
                hi = mid - 1;
            }
        }

        return res;

    }
};