class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> return_val;
        std::unordered_map<string, vector<string>> items;
        
        for (string str : strs){
            int item[26] = {0};

            for (char c : str){
                item[c - 'a']++;
            }


            string key = std::to_string(item[0]);
            
            for (int i = 1; i < 26; ++i){
                key += "," + std::to_string(item[i]);
            }

            items[key].push_back(str);
        }

        for (const auto & [key, value] : items){
            return_val.push_back(value);
        }

        return return_val;
    }
};