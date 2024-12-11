class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> count_map;

        for (string str : strs){
            int count[26] = {0};
            
            for (char c : str){
                count[c - 'a']++;
            }
            
            string key = to_string(count[0]) + ',';
            
            for (int i = 1; i < 26; i++) {
                key += to_string(count[i]) + ','; 
            }

            
            count_map[key].push_back(str);

        }
        vector<vector<string>> res;
        
        for (const auto & [key, value]: count_map){
            res.push_back(value);
        }

        return res;
    }
};