class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq_map;
        vector<vector<int>> bucket(nums.size()+1);
        vector<int> return_val;
    
        for (int i = 0; i < nums.size(); i++){
            if(freq_map.find(nums[i]) == freq_map.end()) {
                freq_map[nums[i]] = 0;
            }else{
                freq_map[nums[i]]++;
            }
        }

        for(auto& item: freq_map) {
            bucket[item.second].push_back(item.first);
        }

        for(int i = bucket.size() - 1; i >= 0 ; i--) {
            if (return_val.size() == k){
                break;
            }
            for (int j : bucket[i]){
                return_val.push_back(j);
            }
        }
        
        return return_val;
    }
};