bool cmp(pair<int,int>& a, pair<int, int>& b){
    return a.second > b.second;
}
class Solution {
public:


    vector<int> sort1(map<int,int>& a, int k) {
        vector<pair<int,int>> m;
        
        vector<int> return_val;
       
        for (auto& it: a){
            m.push_back(it);
        }

        sort(m.begin(), m.end(), cmp);

        for (int i = 0; i < k; i++ ){
            return_val.push_back(m[i].first);
        }

        return return_val;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq_map;

        for (int i = 0; i < nums.size(); i++){
            if(freq_map.find(nums[i]) == freq_map.end()) {
                freq_map[nums[i]] = 0;
            }else{
                freq_map[nums[i]]++;
            }
        }

        return sort1(freq_map, k);
    }
};