class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        std::unordered_map<char,int> items;
        
        for (int i = 0; i < s.length(); i++) {
            if (items.find(s[i]) == items.end()){
                items[s[i]] = 1;
                continue;
            }

            items[s[i]] += 1;
        }

        for (int i = 0; i < t.length(); i++) {
            if(items.find(t[i]) == items.end() || items[t[i]] == 0){
                return false;
            }
            items[t[i]] -= 1;
        }

        return true;
    }
};