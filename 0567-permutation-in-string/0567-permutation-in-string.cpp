class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int hash[26] = {0};
        int hash2[26] = {0};
        int count = 0;
        for (char c : s1){

            if(hash[c - 'a']++ == 0){
                count++;
            };
        } 

        int l = 0; int h = 0;
        int match = 0;
        
        for (; h < s1.size(); h++){
            if (hash[s2[h] - 'a'] == 0) continue;
            if (++hash2[s2[h]- 'a'] == hash[s2[h] - 'a']) match++;
            if (match == count) return true;

        }
        cout<<count<<endl;
        if (hash[s2[l] - 'a'] != 0 && hash2[s2[l] - 'a'] == hash[s2[l] - 'a']) match--;
        l++;
        while (h < s2.length()){
            if (hash[s2[h] - 'a'] != 0 && hash2[s2[h] - 'a'] == hash[s2[h] - 'a'] - 1){
                 match++;
                 cout<<"match"<<endl;
                 cout<<s2[h]<<endl;
            }
            hash2[s2[h] - 'a']++;
            if (match == count) return true;
            
            if (hash[s2[l] - 'a'] != 0 && hash2[s2[l] - 'a'] == hash[s2[l] - 'a']){
                match--;
                cout<<"no match"<<endl;
                cout<<s2[l]<<endl;
            }
            hash2[s2[l] - 'a']--;
            cout<<s2[l]<<endl;
            cout<<s2[h]<<endl;
            cout<<match<<endl;
            l++;
            h++;
        }
        
        return false;
    }
};