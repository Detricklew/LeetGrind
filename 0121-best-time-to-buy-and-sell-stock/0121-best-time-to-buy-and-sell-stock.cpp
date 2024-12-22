class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0; int mini = INT_MAX;

        for (int price : prices){
            mini = min(price, mini);
            res = max(res, price - mini);
        }

        return res;
    }
};