class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1){
            return s.size();
        }

        unordered_set<char> setBoi;
        int l = 0; int h = 0;
        int res = 0;
        int count = 0;
        while(h < s.size()){
            if (setBoi.find(s[h]) != setBoi.end()){
                while(true){
                    setBoi.erase(s[l]);
                    count--;
                    if (s[l++] == s[h]){
                        break;
                    }

                }
            }

            cout<<"insert"<<endl;
            cout<<s[h]<<endl;
            setBoi.insert(s[h++]);
            res = max(res, ++count);
            cout<<count<<endl;
            
        }

        return res;
    }
};