class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq_map;
        string res = "";
        uint32_t check = 0;

        for (char c: s){
            freq_map[c]++;
        }

        for(int i = 0; i < s.size(); i++ ){

                freq_map[s[i]]--;

                if((1<<(s[i] - 'a') & check)){
                    continue;
                }

                while(res.size() && res[res.size()-1] > s[i] && freq_map[res[res.size()-1]] > 0){
                    check ^= (1 <<(res[res.size()-1] -'a'));
                    res.pop_back();
                    continue;
                }
            
                res += s[i];
                check |= (1 << (s[i]-'a'));
                
        }

        return res;
    }
};